## 1. 조건문 - if / else if / else

프로그램이 조건에 따라 다른 코드를 실행하게 만듭니다.

```cpp
#include <iostream>

int main() {
    int score = 85;

    if (score >= 90) {
        std::cout << "A학점" << std::endl;
    } else if (score >= 80) {
        std::cout << "B학점" << std::endl;
    } else if (score >= 70) {
        std::cout << "C학점" << std::endl;
    } else {
        std::cout << "F학점" << std::endl;
    }

    return 0;
}
```

- 조건은 `()` 안에 넣고, 참(true)이면 그 블록 `{}`이 실행됩니다.
- 조건은 위에서부터 순서대로 검사하며, 처음 참이 되는 곳만 실행되고 나머지는 건너뜁니다.
- `score = 85`면 첫 조건(`>=90`)은 거짓, 두 번째(`>=80`)는 참이므로 "B학점"만 출력됩니다.

### 논리 연산자로 조건 조합하기

```cpp
int age = 20;
bool hasLicense = true;

if (age >= 18 && hasLicense) {
    std::cout << "운전 가능" << std::endl;
}
```

- `&&` : 그리고(AND) — 둘 다 참이어야 참
- `||` : 또는(OR) — 하나라도 참이면 참
- `!` : 부정(NOT) — 참/거짓을 뒤집음

### switch문

특정 변수의 값에 따라 여러 갈래로 나눌 때는 `switch`가 `if-else`보다 깔끔합니다.

```cpp
int day = 3;

switch (day) {
    case 1:
        std::cout << "월요일" << std::endl;
        break;
    case 2:
        std::cout << "화요일" << std::endl;
        break;
    case 3:
        std::cout << "수요일" << std::endl;
        break;
    default:
        std::cout << "알 수 없음" << std::endl;
}
```

⚠️ **`break`를 꼭 넣어야 합니다.** 안 넣으면 그 아래 `case`까지 계속 실행되어버립니다(이걸 "fall-through"라고 부릅니다). 실수로 자주 발생하는 버그이니 주의하세요.

## 2. 반복문 - for

정해진 횟수만큼 반복할 때 가장 많이 씁니다.

```cpp
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
}
// 출력: 0 1 2 3 4
```

구조를 뜯어보면:

- `int i = 0` : 시작할 때 딱 한 번 실행 (초기화)
- `i < 5` : 매 반복 전에 검사하는 조건. 참이면 계속, 거짓이면 반복 종료
- `i++` : 매 반복이 끝난 뒤 실행 (증가)

`i++`는 `i = i + 1`과 같은 뜻이에요. `i--`는 반대로 1을 뺍니다.

## 3. 반복문 - while / do-while

**조건만 있고 반복 횟수를 미리 모를 때** 사용합니다.

```cpp
int count = 0;
while (count < 3) {
    std::cout << "count: " << count << std::endl;
    count++;
}
```

`while`은 조건을 **먼저 검사한 후** 실행합니다. 반면 `do-while`은 **일단 한 번 실행하고 나서** 조건을 검사합니다.

```cpp
int num;
do {
    std::cout << "숫자를 입력하세요 (0 입력 시 종료): ";
    std::cin >> num;
    std::cout << "입력값: " << num << std::endl;
} while (num != 0);
```

- `do-while`은 "일단 한 번은 무조건 실행해야 하는" 상황(예: 사용자 입력을 최소 한 번은 받아야 할 때)에 유용합니다.

## 4. break와 continue

반복문 안에서 흐름을 제어하는 두 키워드입니다.

```cpp
// break: 반복문을 완전히 빠져나감
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    std::cout << i << " ";
}
// 출력: 0 1 2 3 4

// continue: 이번 반복만 건너뛰고 다음 반복으로
for (int i = 0; i < 5; i++) {
    if (i == 2) continue;
    std::cout << i << " ";
}
// 출력: 0 1 3 4  (2만 건너뜀)
```

## 5. 중첩 반복문 (반복문 안의 반복문)

구구단 같은 표를 만들 때 자주 쓰입니다.

```cpp
for (int i = 2; i <= 3; i++) {
    for (int j = 1; j <= 9; j++) {
        std::cout << i << " x " << j << " = " << i * j << std::endl;
    }
}
```

바깥 반복문이 한 번 돌 때마다 안쪽 반복문이 처음부터 끝까지 전부 실행됩니다. 즉 `i=2`일 때 `j`가 1~9까지 다 돌고, 그다음 `i=3`으로 넘어갑니다.

---

## 📌 오늘의 요약

1. `if / else if / else`는 조건에 따라 분기하며, 처음 참이 되는 블록만 실행된다.
2. `switch`는 하나의 변수값에 따라 여러 갈래로 나눌 때 쓰며, `break`를 빼먹으면 아래 case까지 줄줄이 실행된다(fall-through).
3. `for`는 반복 횟수를 알 때, `while`은 조건 기반으로 반복할 때, `do-while`은 최소 한 번은 실행이 보장되어야 할 때 사용한다.
4. `break`는 반복문을 즉시 종료, `continue`는 이번 회차만 건너뛰고 다음으로 넘어간다.
5. 반복문은 중첩해서 쓸 수 있으며, 표 형태의 데이터를 다룰 때 자주 활용된다.

---