## 1. 연산자 오버로딩이란?

`+`, `-`, `==`, `<<` 같은 연산자를 **내가 만든 클래스에서도 쓸 수 있게** 동작을 정의하는 문법입니다. 3강의 함수 오버로딩(같은 이름, 다른 매개변수)과 같은 발상으로, "같은 `+`인데 타입에 따라 다르게 동작"하는 거예요.

`int`나 `double`은 `+`가 이미 정의되어 있지만, 직접 만든 클래스는 그렇지 않습니다.

```cpp
class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    Point a(1, 2), b(3, 4);
    // Point c = a + b;   // 에러! 컴파일러는 Point끼리 더하는 법을 모름
    return 0;
}
```

(생성자의 `x(x)`는 7강의 초기화 리스트예요. 괄호 밖은 멤버, 안은 매개변수로 자동 구분되어 `this->`가 필요 없습니다.)

## 2. 기본 문법: `operator+`

연산자도 사실 **이름이 `operator+`인 함수**입니다. `a + b`는 컴파일러가 `a.operator+(b)`로 바꿔서 처리해요.

```cpp
class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

int main() {
    Point a(1, 2), b(3, 4);
    Point c = a + b;          // a.operator+(b) 와 같음
    std::cout << c.x << ", " << c.y << std::endl;   // 4, 6
    return 0;
}
```

하나씩 뜯어보면:

- `Point` (맨 앞): 반환 타입. 더한 결과도 Point
- `operator+`: `+`를 정의하는 함수 이름
- `const Point& other`: 오른쪽 피연산자를 **const 참조**로 받음 (3강, 복사 방지 + 수정 방지)
- 뒤의 `const`: "이 함수는 `this` 객체를 바꾸지 않는다"는 약속. `a + b`가 a나 b를 바꾸면 이상하니까요
- `a + b`에서 **왼쪽(a)이 `this`**, **오른쪽(b)이 `other`**

## 3. 비교 연산자 `==`

```cpp
bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

// 사용
Point a(1, 2), b(1, 2);
if (a == b) std::cout << "같은 점" << std::endl;
```

`!=`, `<`, `>` 등도 같은 방식으로 만듭니다. 반환 타입이 `bool`이라는 점만 다르고 구조는 동일해요.

## 4. 복합 대입 `+=`와 증가 `++`

```cpp
class Counter {
public:
    int value = 0;

    Counter& operator+=(int n) {
        value += n;
        return *this;        // 자기 자신을 돌려줌
    }

    Counter& operator++() {  // 전위 ++c
        value++;
        return *this;
    }

    Counter operator++(int) { // 후위 c++ (int는 구분용 더미)
        Counter old = *this;
        value++;
        return old;           // 증가 전 값을 돌려줌
    }
};
```

- `+=`는 `this`를 **바꾸는** 연산이라 뒤에 `const`가 없고, 자기 자신을 참조(`Counter&`)로 돌려줍니다
- `return *this;`: 4강의 역참조예요. `this`는 포인터니까 `*this`가 객체 자신입니다. 참조로 돌려주면 `c += 1 += 2` 같은 연쇄 호출도 가능해요
- 전위/후위 구분은 C++의 독특한 규칙이에요. 매개변수에 `int`를 하나 넣은 쪽이 후위인데, 그 `int`는 **구분용**일 뿐 실제로 쓰지 않습니다. 이 정도만 알아두세요

## 5. 출력 연산자 `<<` (가장 많이 쓰는 것)

`std::cout << p`로 객체를 바로 출력하고 싶을 때가 많죠. 파이썬의 `__str__`과 비슷한 역할이에요. 그런데 `<<`는 **왼쪽이 `cout`**이라서 Point 안에 멤버로 만들 수 없고, **클래스 밖의 일반 함수**로 만들어야 합니다.

```cpp
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point a(1, 2);
    std::cout << a << std::endl;   // (1, 2)
    return 0;
}
```

- `std::ostream&`: `cout`의 타입(출력 스트림). 참조로 받고 참조로 돌려줍니다
- 돌려주는 이유: `cout << a << b << endl`처럼 **연쇄**하려면 `<< a`의 결과가 다시 `cout`이어야 하기 때문
- 멤버 변수가 `private`이면 이 함수가 접근할 수 없어서, 클래스 안에 `friend std::ostream& operator<<(...);`로 "이 함수는 허용"이라고 선언해야 합니다. 지금은 "`public`이면 그냥 된다"만 기억하세요

## 6. 멤버 함수 vs 일반 함수

| 방식 | 왼쪽 피연산자 | 예시 |
|---|---|---|
| 멤버 함수 | 반드시 **그 클래스의 객체** | `a + b`, `a == b` |
| 일반 함수 | 무엇이든 가능 | `cout << a`, `3 * a` |

`Point`에 `a * 3`은 멤버로 만들 수 있지만, `3 * a`는 왼쪽이 `int`라서 **일반 함수**로 만들어야 합니다.

## 7. 지켜야 할 규칙과 주의점

- **새 연산자는 못 만듭니다.** `**`처럼 C++에 없는 기호는 불가능해요 (파이썬과 다른 점)
- `::`, `.`, `?:` 같은 일부 연산자는 오버로딩할 수 없습니다
- `int + int`처럼 **기본 타입만의 연산은 바꿀 수 없습니다.** 최소 하나는 내가 만든 클래스여야 해요
- **직관과 맞게 만드세요.** `+`가 뺄셈을 하면 코드를 읽는 사람이 혼란스럽습니다. "이 연산자를 보면 누구나 예상하는 동작"을 지키는 게 가장 중요한 원칙이에요

---

## 📌 오늘의 요약

1. 연산자 오버로딩은 `+`, `==`, `<<` 등을 **내가 만든 클래스에서도 쓰게** 정의하는 문법이다 (파이썬의 매직 메서드와 같은 발상).
2. 연산자는 `operator+` 같은 **이름의 함수**이고, `a + b`는 `a.operator+(b)`로 처리된다. 왼쪽이 `this`, 오른쪽이 매개변수다.
3. 오른쪽 피연산자는 `const 참조`로 받고, 객체를 바꾸지 않는 연산자는 뒤에 `const`를 붙인다.
4. `+=`, 전위 `++`는 `*this`를 참조로 돌려주고, 후위 `++`는 구분용 `int` 매개변수로 구별한다.
5. `<<`는 왼쪽이 `cout`이라 **클래스 밖 일반 함수**로 만들며, 연쇄 출력을 위해 `ostream&`를 반환한다.
6. 새 연산자 생성은 불가능하고, 직관에 맞는 동작으로만 정의해야 한다.

---