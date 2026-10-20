## 1. 예외가 왜 필요한가

에러가 났을 때 지금까지는 `return -1` 같은 방식으로 알렸는데, 함수가 여러 겹 호출되면 에러를 일일이 전달하기 번거롭고 **무시하기도 쉬워요.** 예외는 에러가 나면 **현재 흐름을 중단하고, 처리할 수 있는 곳까지 한 번에 점프**하는 방식입니다.

## 2. 기본 문법

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("0으로 나눌 수 없습니다");   // 예외 던지기
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        cout << divide(10, 2) << endl;   // 5
        cout << divide(1, 0) << endl;    // 여기서 예외 발생 → 아래 줄은 실행 안 됨
        cout << "이 줄은 실행되지 않음" << endl;
    } catch (const runtime_error& e) {
        cout << "에러: " << e.what() << endl;   // 에러: 0으로 나눌 수 없습니다
    }

    cout << "프로그램 계속 진행" << endl;
    return 0;
}
```

- `throw`: 예외를 **던진다.** 그 순간 현재 함수가 중단돼요
- `try { }`: 예외가 날 수 있는 코드를 감쌈
- `catch (...) { }`: 던져진 예외를 **받아서** 처리
- `e.what()`: 예외에 담긴 **메시지 문자열**을 돌려줌 (파이썬 `str(e)`)
- 받는 타입은 `const runtime_error&`처럼 **const 참조**로 쓰는 게 관례예요 (복사 방지, 3강)

## 3. 예외가 전달되는 흐름

예외는 호출한 쪽으로 **거슬러 올라가며** `catch`를 찾습니다.

```cpp
void c() { throw runtime_error("c에서 에러"); }
void b() { c(); }
void a() { b(); }

int main() {
    try { a(); }                       // a → b → c 에서 던져짐
    catch (const exception& e) { cout << e.what(); }   // main에서 받음
}
```

`c`에서 던지면 `b`, `a`를 **건너뛰고** `main`의 `catch`까지 올라와요. 중간 함수들이 에러 코드를 일일이 전달할 필요가 없는 게 장점입니다. 끝까지 받는 곳이 없으면 프로그램이 **강제 종료**돼요.

## 4. 표준 예외 클래스

`<stdexcept>`에 미리 만들어진 예외들이 있어요. 전부 `std::exception`의 자식입니다 (8강 상속).

| 예외 | 쓰임 |
|---|---|
| `runtime_error` | 실행 중 발생한 일반 오류 |
| `invalid_argument` | 잘못된 인자 값 |
| `out_of_range` | 범위 벗어남 (`vector::at`, `map::at`) |
| `logic_error` | 코드 논리상 말이 안 되는 상황 |
| `bad_alloc` | 메모리 할당 실패 (`new`) |

```
exception
├── logic_error
│   ├── invalid_argument
│   └── out_of_range
└── runtime_error
```

## 5. 여러 catch와 순서

```cpp
try {
    vector<int> v = {1, 2, 3};
    cout << v.at(10);          // out_of_range 발생
} catch (const out_of_range& e) {
    cout << "범위 오류: " << e.what() << endl;
} catch (const exception& e) {
    cout << "기타 오류: " << e.what() << endl;
}
```

- 위에서부터 **처음 맞는 `catch` 하나만** 실행돼요 (`if-else if`와 같음)
- ⚠️ **구체적인 것을 위에, 포괄적인 것(`exception`)을 아래에** 두세요. 순서가 반대면 부모 `catch`가 먼저 전부 받아버립니다 (다형성 때문)
- 모든 것을 받는 `catch (...)`도 있는데, 에러 내용을 알 수 없어서 **마지막 보루**로만 쓰세요

```cpp
catch (...) { cout << "알 수 없는 오류"; }
```

13강의 `at()` 약속이 여기서 회수됩니다. `[]`는 범위를 검사하지 않지만 **`at()`은 `out_of_range`를 던져요.**

```cpp
map<string, int> m;
try { m.at("없는키"); }
catch (const out_of_range& e) { cout << "키 없음"; }
```

## 6. 직접 예외 클래스 만들기

`exception`을 상속받으면 나만의 예외를 만들 수 있어요.

```cpp
class NegativeAgeError : public runtime_error {
public:
    NegativeAgeError(int age)
        : runtime_error("나이는 음수일 수 없습니다: " + to_string(age)) {}
};

void setAge(int age) {
    if (age < 0) throw NegativeAgeError(age);
}

try { setAge(-5); }
catch (const NegativeAgeError& e) { cout << e.what(); }
```

6강의 `setAge`에서 "음수 방지"를 `if`로만 막았는데, 예외를 쓰면 **호출한 쪽이 잘못을 알 수 있어요.** 상속 문법(`: runtime_error(...)`)은 8강에서 배운 부모 생성자 호출 그대로예요.

## 7. 예외와 소멸자 (7강 약속 회수)

예외가 던져져서 함수가 중간에 빠져나가도, 그 함수 안의 **지역 객체들의 소멸자는 자동으로 호출**돼요. 이걸 **스택 되감기(stack unwinding)**라고 합니다.

```cpp
class Guard {
public:
    Guard()  { cout << "자원 획득" << endl; }
    ~Guard() { cout << "자원 정리" << endl; }
};

void work() {
    Guard g;
    throw runtime_error("문제 발생");
    // g의 소멸자는 예외로 빠져나가도 자동 호출됨
}
```

출력은 `자원 획득` → `자원 정리`예요. 이 성질이 **15강 스마트 포인터의 핵심 원리**입니다. 반대로 `new`로 직접 만든 객체는 소멸자가 자동 호출되지 않아서, 예외가 나면 `delete`를 건너뛰어 **메모리 누수**가 생겨요. 15강에서 이걸 해결합니다.

## 8. 예외 사용 규칙

1. **정말 예외적인 상황에만** 쓴다. 일상적인 흐름 제어(`if`로 충분한 것)에는 쓰지 않는다
2. 던질 때는 `exception` 계열 객체를 던지고(`throw 5;`, `throw "문자열";`은 피함)
3. 받을 때는 **`const 타입&`** 으로 받는다
4. 처리할 수 없으면 잡지 않는다. 처리할 수 있는 위쪽에서 잡는다
5. 소멸자에서는 예외를 던지지 않는다

---

## 📌 14강 요약

1. `try`에 위험한 코드를, `catch`에 처리를, `throw`로 던진다 (파이썬 `try/except/raise`와 대응).
2. 예외는 호출 스택을 거슬러 올라가며 **처음 맞는 `catch`** 로 가고, 못 받으면 프로그램이 종료된다.
3. `<stdexcept>`의 표준 예외(`runtime_error`, `invalid_argument`, `out_of_range` 등)를 쓰고, `e.what()`으로 메시지를 꺼낸다.
4. `catch`는 **구체적 → 포괄적(`exception`)** 순으로 쓰고, `const 타입&`으로 받는다.
5. `vector::at()`, `map::at()`은 범위를 벗어나면 `out_of_range`를 던진다 (`[]`는 검사 안 함).
6. 예외가 나도 지역 객체의 소멸자는 자동 호출되므로(스택 되감기), 자원 정리는 소멸자에 맡기는 게 안전하다.

---