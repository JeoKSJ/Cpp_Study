## 1. 왜 파일을 나누나

- 파일 하나가 수백, 수천 줄이 되면 **찾기도 고치기도 힘듭니다**
- 클래스마다 파일을 나누면 **역할별로 정리**되고, 다른 프로젝트에서 **재사용**하기 쉬워요
- 파일별로 따로 컴파일하므로, 한 파일만 고치면 **그 파일만 다시 컴파일**할 수 있어요 (Makefile이 이 장점을 살립니다)

## 2. 헤더(.h)와 소스(.cpp)의 역할

| 파일 | 담는 것 | 비유 |
|---|---|---|
| `.h` (헤더) | **선언**: "이런 함수/클래스가 있다" | 목차, 메뉴판 |
| `.cpp` (소스) | **정의**: 실제 동작 코드 | 본문, 주방 |

3강의 함수 선언(prototype)과 정의를 기억하시죠? 그걸 **파일 단위로 확장**한 거예요.

## 3. 가장 간단한 예: 함수 나누기

파일 3개를 만듭니다.

**`math_utils.h`** (선언)
```cpp
#pragma once

int add(int a, int b);
int multiply(int a, int b);
```

**`math_utils.cpp`** (정의)
```cpp
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

**`main.cpp`** (사용)
```cpp
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << add(3, 4) << std::endl;        // 7
    std::cout << multiply(3, 4) << std::endl;   // 12
    return 0;
}
```

컴파일은 소스 파일들을 **함께** 적어줍니다.

```bash
g++ main.cpp math_utils.cpp -o myprogram
./myprogram
```

`main.cpp`는 `add`가 어떻게 생겼는지 몰라도 **헤더의 선언만 보고** 호출 코드를 만들 수 있고, 실제 연결은 나중에 합쳐질 때(링크) 이뤄집니다.

## 4. `#include`의 두 가지 표기

```cpp
#include <iostream>        // 꺾쇠: 표준 라이브러리, 시스템 헤더
#include "math_utils.h"    // 큰따옴표: 내가 만든 헤더
```

- `<>`는 컴파일러가 정해진 시스템 경로에서 찾고
- `""`는 **먼저 현재 폴더**에서 찾습니다

내가 만든 파일은 항상 큰따옴표를 쓰세요.

`#include`가 하는 일은 단순해요. 전처리 단계에서 **그 자리에 헤더 파일 내용을 그대로 복사해 붙여넣는 것**입니다. 이게 다음에 나올 "중복 포함 문제"의 원인이에요.

## 5. include guard: `#pragma once`

헤더가 **두 번 이상 포함**되면 같은 클래스나 함수가 중복 선언되어 에러가 나요.

```cpp
// a.h 가 Point.h를 include, b.h도 Point.h를 include
// main.cpp가 a.h와 b.h를 둘 다 include → Point 정의가 두 번 들어옴 → 에러
```

이를 막는 장치가 **include guard**이고, 두 가지 방식이 있습니다.

```cpp
// 방식 1: #pragma once (간단, 요즘 대부분 컴파일러가 지원)
#pragma once
// ... 내용 ...

// 방식 2: 전통적인 매크로 방식 (표준 문법, 어디서든 동작)
#ifndef POINT_H
#define POINT_H
// ... 내용 ...
#endif
```

의미는 같아서 **"이 헤더는 한 번만 포함하라"**는 뜻이에요. 앞으로 **모든 헤더 파일 맨 위에 `#pragma once`를 넣는 습관**을 들이세요.

## 6. 클래스 나누기 (가장 많이 쓰는 형태)

7강의 `Person` 클래스를 나눠볼게요.

**`Person.h`** (클래스 선언)
```cpp
#pragma once
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string name, int age);
    void introduce() const;
    int getAge() const;
};
```

**`Person.cpp`** (멤버 함수 정의)
```cpp
#include "Person.h"
#include <iostream>

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::introduce() const {
    std::cout << name << " (" << age << "세)" << std::endl;
}

int Person::getAge() const {
    return age;
}
```

**`main.cpp`**
```cpp
#include "Person.h"

int main() {
    Person p("철수", 25);
    p.introduce();
    return 0;
}
```

```bash
g++ main.cpp Person.cpp -o myprogram
```

새로 나온 문법은 **`Person::`** 하나예요. `::`는 1강에서 `std::cout`으로 봤던 "소속을 밝히는" 기호입니다. `Person::introduce`는 **"Person 클래스에 속한 introduce 함수"**라는 뜻이라, 클래스 밖에서 멤버 함수를 정의할 때 반드시 붙여야 해요.

두 가지 규칙도 함께 기억하세요.

- 멤버 함수 뒤의 `const`는 **선언과 정의 양쪽에** 똑같이 적어야 합니다
- 반환 타입, 매개변수도 선언과 **정확히 일치**해야 합니다 (기본 매개변수 값은 선언 쪽에만 적어요)

## 7. 헤더에 `using namespace std;`를 쓰면 안 되는 이유

지금까지 예제에서 편하게 `using namespace std;`를 써왔지만, **헤더 파일에서는 쓰지 마세요.**

헤더는 `#include`로 **다른 파일에 그대로 복사**되기 때문에, 헤더에 쓰면 그걸 포함하는 **모든 파일이 강제로 영향**을 받아요. 이름 충돌이 생겨도 원인 찾기가 어렵습니다. 그래서 헤더에서는 `std::string`처럼 **항상 `std::`를 명시**하고, `using namespace std;`는 `.cpp` 안에서만(쓴다면) 쓰는 게 관례예요. 위 `Person.h`가 `std::string`을 쓴 이유입니다.

## 8. 템플릿은 왜 예외인가 (10강 약속 회수)

10강에서 "템플릿은 선언은 `.h`, 정의는 `.cpp`로 나누는 규칙이 안 통한다"고 했죠. 이유를 이제 설명할 수 있어요.

- 일반 함수는 `.cpp`에서 **미리 컴파일**되어 있다가 나중에 링크로 연결됩니다
- 템플릿은 `maxOf<int>`처럼 **사용하는 쪽에서 타입이 정해질 때** 컴파일러가 코드를 찍어내요. 그러려면 **사용하는 파일에서 함수 몸체가 보여야** 합니다
- 몸체가 `.cpp`에 숨어 있으면 `main.cpp`가 인스턴스화를 못 해서 **링크 에러**가 납니다

그래서 템플릿은 **정의까지 전부 헤더에 넣습니다.**

```cpp
// Box.h
#pragma once

template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() const { return value; }   // 몸체까지 헤더 안에
};
```

## 9. 자주 만나는 에러 3가지

**① `undefined reference to ...` (링크 에러)**
```
undefined reference to `add(int, int)'
```
선언은 있는데 **정의가 연결되지 않았다**는 뜻이에요. 가장 흔한 원인은 컴파일 명령에 `.cpp`를 빠뜨린 것입니다.
```bash
g++ main.cpp -o myprogram              # 에러: math_utils.cpp가 빠짐
g++ main.cpp math_utils.cpp -o myprogram   # OK
```
(`.cpp`는 컴파일 대상, `.h`는 컴파일 명령에 적지 않아요.)

**② `redefinition of ...` (재정의)**
헤더에 include guard(`#pragma once`)가 없을 때 납니다. 헤더 맨 위에 넣었는지 확인하세요.

**③ `multiple definition of ...` (다중 정의)**
**함수 몸체를 `.h`에 써놓고** 여러 `.cpp`에서 include하면 각 파일이 같은 함수를 갖게 되어 링크 때 충돌합니다.
```cpp
// bad.h
int add(int a, int b) { return a + b; }   // 몸체를 헤더에 쓰면 위험
```
일반 함수는 **헤더에는 선언만, 몸체는 `.cpp`에**. (템플릿과 클래스 안에 바로 적은 짧은 멤버 함수는 예외로 허용돼요.)

## 10. 권장 폴더 구조

```
cpp11/
├── main.cpp
├── Person.h
├── Person.cpp
├── math_utils.h
└── math_utils.cpp
```

파일이 더 늘어나면 `src/`와 `include/` 폴더로 나누기도 하는데, 지금은 한 폴더에 두면 충분해요. 파일 이름은 보통 **클래스 이름과 맞춰서** `Person.h` / `Person.cpp`로 짓습니다.

---

## 📌 오늘의 요약

1. 프로그램이 커지면 파일을 나누며, **`.h`는 선언(무엇이 있는지)**, **`.cpp`는 정의(어떻게 동작하는지)**를 담는다.
2. 내가 만든 헤더는 `#include "파일.h"`(큰따옴표)로 포함하고, 이는 **내용을 그 자리에 복사해 붙이는** 전처리 작업이다.
3. 모든 헤더 맨 위에 **`#pragma once`**(include guard)를 넣어 중복 포함을 막는다.
4. 클래스는 `.h`에 선언, `.cpp`에 정의하며, 밖에서 멤버 함수를 정의할 때는 **`클래스이름::함수이름`**을 쓴다.
5. 헤더에서는 `using namespace std;`를 쓰지 않고 `std::`를 명시한다.
6. **템플릿은 정의까지 헤더에** 작성한다. 사용하는 쪽에서 몸체가 보여야 인스턴스화할 수 있기 때문이다.
7. 컴파일할 때는 **모든 `.cpp`를 함께** 적는다 (`g++ main.cpp Person.cpp -o myprogram`). 빠지면 `undefined reference` 링크 에러가 난다.

---