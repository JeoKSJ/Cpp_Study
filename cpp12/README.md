## 1. `g++` 한 줄 뒤에서 일어나는 4단계

`g++ main.cpp -o myprogram` 한 줄에는 사실 4단계가 숨어 있어요.

```
main.cpp
  │ ① 전처리 (Preprocess)   #include, #define 처리
  ▼
main.ii
  │ ② 컴파일 (Compile)      C++ → 어셈블리 코드
  ▼
main.s
  │ ③ 어셈블 (Assemble)     어셈블리 → 기계어
  ▼
main.o  (오브젝트 파일)
  │ ④ 링크 (Link)           여러 .o 와 라이브러리를 합침
  ▼
myprogram (실행 파일)
```

| 단계 | 하는 일 | 11강과 연결 |
|---|---|---|
| ① 전처리 | `#include`를 **복사 붙여넣기**로 치환, `#pragma once` 처리 | include가 "복사"라는 설명이 여기서 일어남 |
| ② 컴파일 | 문법 검사, C++ 코드를 어셈블리로 변환 | 문법 에러, 타입 에러가 여기서 남 |
| ③ 어셈블 | 어셈블리를 기계어(`.o`)로 변환 | `.cpp` 하나당 `.o` 하나 |
| ④ 링크 | `.o`들을 이어 붙여 함수 호출을 연결 | `undefined reference`가 여기서 남 |

보통 ②와 ③은 합쳐서 "컴파일"이라고 부릅니다.

## 2. 각 단계를 직접 확인해보기

11강에서 만든 `main.cpp`가 있는 폴더에서 해보세요.

```bash
g++ -E main.cpp -o main.ii    # ① 전처리까지만
g++ -S main.cpp -o main.s     # ② 어셈블리까지만
g++ -c main.cpp -o main.o     # ③ 기계어(.o)까지만 (링크 안 함)
g++ main.o -o myprogram       # ④ 링크
```

- `-E` : `main.ii`를 열어보면 `#include <iostream>`이 **수천 줄의 내용으로 펼쳐져** 있어요. include가 복사라는 걸 눈으로 확인할 수 있습니다
- `-S` : `main.s`를 열면 어셈블리 코드가 보입니다. 읽을 필요는 없고 "이런 게 생기는구나" 정도만요
- `-c` : **링크를 안 하고** `.o`까지만 만듭니다. 이 옵션이 Makefile의 핵심이에요

## 3. 파일이 여럿일 때: 따로 컴파일하고 한 번에 링크

11강의 `Person` 예제로 해볼게요.

```bash
g++ -c main.cpp -o main.o
g++ -c Person.cpp -o Person.o
g++ main.o Person.o -o myprogram
```

이제 **`Person.cpp`만 수정**했다고 해볼게요.

```bash
g++ -c Person.cpp -o Person.o      # 수정한 것만 다시 컴파일
g++ main.o Person.o -o myprogram   # 링크만 다시
```

`main.cpp`는 건드리지 않았으니 **`main.o`를 재사용**합니다. 파일이 수백 개인 프로젝트라면 수정한 파일만 컴파일해서 시간이 크게 절약돼요. 문제는 **"어떤 파일이 바뀌었는지 사람이 기억해서 일일이 명령을 치기"가 너무 번거롭다**는 점이고, 이걸 자동으로 해주는 도구가 `make`입니다.

## 4. Makefile 기본 구조

```makefile
목표(target): 의존 파일들(dependencies)
	명령어
```

`make`는 **"목표 파일이 의존 파일보다 오래됐으면(= 의존 파일이 수정됐으면) 명령을 다시 실행"**합니다. 파일의 수정 시각을 비교하는 거예요.

⚠️ 명령어 줄 앞은 **스페이스가 아니라 반드시 탭(Tab)**이에요. 스페이스로 들여쓰면 `*** missing separator` 에러가 납니다. VSCode 오른쪽 아래에 "Spaces: 4"라고 보이면 눌러서 "Indent Using Tabs"로 바꿔주세요.

## 5. 가장 기본적인 Makefile (11강 프로젝트용)

```makefile
myprogram: main.o Person.o
	g++ main.o Person.o -o myprogram

main.o: main.cpp Person.h
	g++ -c main.cpp -o main.o

Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o

clean:
	rm -f *.o myprogram
```

터미널에서 실행합니다.

```bash
make            # 첫 번째 목표(myprogram)를 만듦
make            # 다시 실행 → "make: 'myprogram' is up to date." (할 일 없음)
make clean      # 생성된 파일 삭제
```

`make`만 치면 **맨 위의 목표**를 만들려고 하고, 필요한 `.o`가 없거나 오래됐으면 **아래 규칙들을 거슬러 올라가며** 만들어줍니다.

```
myprogram이 필요 → main.o, Person.o가 필요
  main.o가 없거나 main.cpp/Person.h보다 오래됨 → 컴파일
  Person.o도 마찬가지 → 컴파일
→ 링크
```

### 의존성에 `.h`를 넣는 이유

`main.o: main.cpp Person.h`에서 `Person.h`가 빠지면 어떻게 될까요? 헤더만 수정했을 때 `main.cpp`는 안 바뀌었으니 make가 "다시 컴파일할 필요 없음"이라고 판단해요. 그런데 `#include`는 복사라서 `main.o`는 **옛날 헤더 내용으로 만들어진 상태**입니다. 이러면 이상한 오류가 생기니, **`.o`가 `#include`하는 헤더는 의존성에 적어야** 합니다.

## 6. 변수와 패턴 규칙으로 줄이기

파일이 늘 때마다 규칙을 쓰기 귀찮으니 일반화해볼게요.

```makefile
CXX      = g++
CXXFLAGS = -Wall -std=c++17
TARGET   = myprogram
SRCS     = main.cpp Person.cpp
OBJS     = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
```

| 문법 | 뜻 |
|---|---|
| `CXX = g++` | 변수 정의. `$(CXX)`로 사용 |
| `$(SRCS:.cpp=.o)` | `SRCS`의 `.cpp`를 `.o`로 치환 → `main.o Person.o` |
| `%.o: %.cpp` | "어떤 `.cpp`든 같은 이름 `.o`로 만든다"는 **패턴 규칙** |
| `$<` | 규칙의 **첫 번째 의존 파일** (해당 `.cpp`) |
| `$@` | **목표** 이름 (해당 `.o`) |
| `-Wall` | 의심스러운 코드에 경고 표시 (**항상 켜두는 걸 추천**) |
| `-std=c++17` | 사용할 C++ 표준 버전 |
| `.PHONY: clean` | `clean`은 파일 이름이 아니라 "명령"이라는 표시 |

이제 새 파일이 생기면 **`SRCS` 줄에 이름만 추가**하면 돼요.

## 7. 헤더 의존성 자동 처리 (알아두면 좋은 팁)

패턴 규칙에서는 `.h` 의존성이 빠져서 "헤더만 고쳤는데 재컴파일이 안 되는" 문제가 생겨요. 컴파일러에게 헤더 의존성을 자동으로 뽑게 할 수 있습니다.

```makefile
CXXFLAGS = -Wall -std=c++17 -MMD -MP

# ... (위와 동일) ...

-include $(OBJS:.o=.d)
```

- `-MMD -MP` : 컴파일할 때 `main.d` 같은 파일에 "이 `.o`가 어떤 헤더에 의존하는지"를 자동 기록
- `-include $(OBJS:.o=.d)` : 그 기록을 Makefile에 읽어들임 (앞의 `-`는 파일이 없어도 에러 내지 말라는 뜻)

처음엔 "헤더 수정이 반영 안 될 때 쓰는 해결책이 있다" 정도로만 알아두세요. `clean`에 `*.d`도 지우도록 추가하면 깔끔합니다.

## 8. 자주 만나는 에러

**① `Makefile:3: *** missing separator.  Stop.`**
명령어 줄 앞이 **탭이 아니라 스페이스**입니다.

**② `make: *** No rule to make target 'Person.cpp'...`**
`SRCS`에 적은 파일이 폴더에 없거나 **이름 철자가 다릅니다** (`max0f` 사건을 떠올려보세요).

**③ `make: 'myprogram' is up to date.`**
에러가 아니라 "바뀐 게 없어서 할 일 없음"이라는 정상 메시지예요. 강제로 다시 만들고 싶으면 `make clean && make`를 쓰면 됩니다.

**④ 헤더만 고쳤는데 결과가 안 바뀜**
의존성에 `.h`가 빠진 경우입니다. 위 7번의 `-MMD -MP`를 쓰거나 `make clean && make`로 해결하세요.

## 9. 폴더가 나뉜 프로젝트라면

앞서 `header/max0f.h`처럼 헤더를 별도 폴더에 두셨죠? 그럴 땐 컴파일러에 **헤더 위치**를 알려주는 `-I` 옵션을 쓰면 `#include "max0f.h"`만 써도 됩니다.

```makefile
CXXFLAGS = -Wall -std=c++17 -Iheader
```

`-I폴더`는 "헤더를 이 폴더에서도 찾아라"는 뜻이에요. 지금 방식(`#include "header/max0f.h"`처럼 경로 포함)도 충분히 좋아서, 폴더가 복잡해졌을 때 쓰는 옵션으로만 알아두세요.

---

## 📌 오늘의 요약

1. `g++`는 **전처리 → 컴파일 → 어셈블 → 링크** 4단계를 거치며, `-E`, `-S`, `-c` 옵션으로 중간 단계에서 멈출 수 있다.
2. `-c`는 링크 없이 **`.cpp`를 `.o`로만** 만들며, 파일마다 따로 컴파일한 뒤 한 번에 링크한다.
3. 수정한 파일만 다시 컴파일하면 시간이 절약되고, 이를 **자동화하는 도구가 `make`**다.
4. Makefile은 **`목표: 의존파일`** 아래에 **탭으로 들여쓴 명령어**를 적으며, 파일 수정 시각을 비교해서 필요한 것만 다시 만든다.
5. `.o`가 `#include`하는 **헤더도 의존성에 적어야** 헤더 수정이 반영된다 (`-MMD -MP`로 자동화 가능).
6. 변수(`CXX`, `SRCS`), 패턴 규칙(`%.o: %.cpp`), 자동 변수(`$<`, `$@`)로 파일이 늘어나도 Makefile을 거의 안 고치게 만든다.
7. `clean`은 파일이 아닌 명령이므로 `.PHONY`로 선언한다.
8. 에러가 나면 **탭/스페이스, 파일 이름 철자**부터 확인한다.

---