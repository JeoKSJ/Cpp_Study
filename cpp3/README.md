## 1. 함수가 필요한 이유

같은 코드를 여러 번 반복해서 써야 한다면, 그 코드를 함수로 만들어두고 필요할 때마다 "호출"하면 됩니다. 코드가 짧아지고, 수정할 때도 한 곳만 고치면 됩니다.

## 2. 함수의 기본 구조

```cpp
#include <iostream>

// 함수 정의
int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int sum = add(3, 5);   // 함수 호출
    std::cout << sum << std::endl;  // 8
    return 0;
}
```

구조를 뜯어보면:

- `int` (맨 앞) : **반환 타입** — 이 함수가 돌려주는 값의 타입
- `add` : 함수 이름
- `(int a, int b)` : **매개변수(parameter)** — 함수가 받는 입력값들
- `return result;` : 함수를 호출한 곳으로 값을 돌려줌
- `add(3, 5)`처럼 호출할 때 넘기는 `3`, `5`를 **인자(argument)**라고 부릅니다.

## 3. 반환값이 없는 함수 - void

값을 돌려줄 필요 없이 "동작"만 하는 함수는 반환 타입을 `void`로 씁니다.

```cpp
void greet(std::string name) {
    std::cout << "안녕하세요, " << name << "님!" << std::endl;
}

int main() {
    greet("김철수");   // 안녕하세요, 김철수님!
    return 0;
}
```

`void` 함수는 `return;`만 쓸 수 있고(값 없이), 아예 안 써도 함수 끝에서 자동으로 종료됩니다.

## 4. 함수 선언(prototype)과 정의

`main` 함수보다 아래에 함수를 만들면, `main`이 그 함수를 아직 모르는 상태라서 컴파일 에러가 납니다.

```cpp
#include <iostream>

int add(int a, int b);  // 함수 선언(prototype) - "이런 함수가 있다"고 미리 알려줌

int main() {
    std::cout << add(2, 3) << std::endl;  // 문제없이 동작
    return 0;
}

int add(int a, int b) {  // 함수 정의는 나중에 등장해도 OK
    return a + b;
}
```

- **선언**: 함수의 "이름표"만 미리 알려주는 것 (`;`으로 끝남, 몸체 없음)
- **정의**: 실제 함수의 몸체(`{}`)가 있는 것

파일이 커지면 보통 선언은 헤더 파일(`.h`)에, 정의는 소스 파일(`.cpp`)에 나눠서 작성합니다. (이 부분은 나중에 프로젝트 구조를 다룰 때 더 자세히 볼게요.)

## 5. 값에 의한 전달 (Pass by Value)

C++에서 함수에 인자를 넘기면 기본적으로 **값이 복사**되어 전달됩니다.

```cpp
void increase(int num) {
    num = num + 1;
    std::cout << "함수 안: " << num << std::endl;
}

int main() {
    int x = 10;
    increase(x);
    std::cout << "함수 밖: " << x << std::endl;  // 여전히 10!
    return 0;
}
```

`increase` 함수 안에서 `num`을 바꿔도, 그건 `x`의 **복사본**일 뿐이라서 원본 `x`는 영향을 받지 않습니다. 이게 기본 동작입니다.

## 6. 참조에 의한 전달 (Pass by Reference)

원본 변수 자체를 바꾸고 싶다면 매개변수 타입에 `&`를 붙입니다.

```cpp
void increase(int& num) {   // & 를 붙이면 "참조" 전달
    num = num + 1;
}

int main() {
    int x = 10;
    increase(x);
    std::cout << x << std::endl;  // 11! 원본이 바뀜
    return 0;
}
```

- `int& num`은 "num은 원본 변수의 또 다른 이름(별명)"이라고 생각하면 됩니다. 복사본이 아니라 진짜 그 변수를 가리키는 것입니다.
- 두 값을 서로 바꾸는(swap) 함수처럼, 함수 안에서 여러 값을 "돌려줘야" 할 때 유용합니다.

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swap(x, y);
    std::cout << x << " " << y << std::endl;  // 2 1
    return 0;
}
```

> 💡 참고로 큰 데이터(예: 긴 문자열)를 함수에 넘길 때, 값 복사는 비용이 크기 때문에 **`const 참조`**(`const std::string& name`)로 넘기는 경우도 많습니다. "원본을 바꾸지 않으면서, 복사도 하지 않는" 방식이에요. 지금은 이런 게 있다는 정도만 알아두면 됩니다.

## 7. 함수 오버로딩 (Overloading)

**같은 이름의 함수를 매개변수 종류나 개수만 다르게 여러 개 만들 수 있습니다.** 컴파일러가 호출할 때 넘긴 인자를 보고 알아서 맞는 함수를 골라줍니다.

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << add(1, 2) << std::endl;         // int 버전 호출 → 3
    std::cout << add(1.5, 2.5) << std::endl;      // double 버전 호출 → 4
    std::cout << add(1, 2, 3) << std::endl;       // 3개 인자 버전 호출 → 6
    return 0;
}
```

같은 이름이라도 매개변수의 **개수**나 **타입**이 다르면 컴파일러가 구분해서 알맞은 함수를 찾아 실행합니다.

## 8. 기본 매개변수 (Default Parameter)

인자를 안 넘기면 사용할 기본값을 미리 정해둘 수 있습니다.

```cpp
void greet(std::string name, std::string greeting = "안녕하세요") {
    std::cout << greeting << ", " << name << "!" << std::endl;
}

int main() {
    greet("철수");                  // 안녕하세요, 철수!
    greet("영희", "반갑습니다");      // 반갑습니다, 영희!
    return 0;
}
```

⚠️ 기본값은 매개변수 목록의 **뒤쪽**부터 채워야 합니다. (`greet(std::string greeting = "안녕", std::string name)`처럼 앞쪽에 기본값을 주는 건 안 됩니다.)

---

## 📌 오늘의 요약

1. 함수는 `반환타입 함수이름(매개변수) { ... return 값; }` 형태로 정의하며, 반환값이 없으면 `void`를 쓴다.
2. `main`보다 나중에 정의될 함수는 미리 **선언(prototype)**을 해둬야 컴파일 에러가 나지 않는다.
3. 기본적으로 인자는 **값 복사**로 전달되어 함수 안에서 바꿔도 원본에 영향이 없다(Pass by Value).
4. 매개변수에 `&`를 붙이면 **참조 전달**이 되어 원본 변수를 직접 바꿀 수 있다(Pass by Reference).
5. **함수 오버로딩**으로 같은 이름의 함수를 매개변수 타입/개수만 다르게 여러 개 만들 수 있다.
6. **기본 매개변수**를 지정하면 호출 시 인자를 생략할 수 있으며, 반드시 뒤쪽 매개변수부터 지정해야 한다.

---