## 1. 템플릿이 왜 필요한가

3강의 함수 오버로딩을 떠올려보세요. 두 수 중 큰 값을 구하는 함수를 타입마다 만들어야 했습니다.

```cpp
int maxOf(int a, int b)          { return (a > b) ? a : b; }
double maxOf(double a, double b) { return (a > b) ? a : b; }
char maxOf(char a, char b)       { return (a > b) ? a : b; }
```

**타입만 다르고 코드는 똑같죠.** 타입이 늘어날 때마다 복사해서 만드는 건 비효율적이에요. 템플릿은 "**타입을 빈칸으로 두고 틀(template)만 만들어두는**" 기능입니다.

(참고: `(a > b) ? a : b`는 삼항 연산자예요. "a가 크면 a, 아니면 b"라는 `if-else`의 짧은 버전입니다.)

## 2. 함수 템플릿

```cpp
template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maxOf(3, 7) << std::endl;         // 7      (T = int)
    std::cout << maxOf(2.5, 1.2) << std::endl;     // 2.5    (T = double)
    std::cout << maxOf('a', 'z') << std::endl;     // z      (T = char)
    return 0;
}
```

- `template <typename T>`: "아래 함수에서 `T`는 **타입이 들어갈 빈칸**"이라는 선언
- `T`는 변수 이름처럼 그냥 관례적인 이름이에요 (`Type`의 T). `U`, `Item`으로 바꿔도 됩니다
- `maxOf(3, 7)`처럼 호출하면 컴파일러가 인자를 보고 `T = int`로 **자동 추론**하고, `int`용 함수를 **그 자리에서 만들어줍니다**

타입을 직접 지정할 수도 있어요.

```cpp
maxOf<double>(3, 7.5);   // T를 double로 명시
```

`<double>` 문법, 어디서 본 것 같죠? 맞아요, `vector<int>`와 같은 방식입니다.

## 3. 컴파일러는 뭘 하나? (인스턴스화)

템플릿 자체는 **함수가 아니라 "함수를 찍어내는 틀"**이에요. 호출될 때마다 컴파일러가 해당 타입으로 진짜 함수를 만듭니다.

```
maxOf(3, 7)      →  컴파일러가 int maxOf(int, int)를 생성
maxOf(2.5, 1.2)  →  컴파일러가 double maxOf(double, double)를 생성
```

이걸 **인스턴스화**라고 해요. 실행 중이 아니라 **컴파일 때** 일어나기 때문에 실행 속도 손해가 없습니다. 반대로 쓰지 않은 타입의 코드는 만들어지지 않아요.

## 4. 흔한 에러: 타입이 안 맞을 때

```cpp
maxOf(3, 7.5);   // 에러! 첫 인자는 int, 둘째는 double → T를 하나로 못 정함
```

두 인자가 모두 `T`인데 `int`와 `double`이 섞여서 추론이 안 되는 거예요. 해결책은 두 가지입니다.

```cpp
maxOf<double>(3, 7.5);     // 타입 명시
maxOf(3.0, 7.5);           // 인자를 같은 타입으로
```

그리고 템플릿 안에서 쓰는 연산은 **그 타입이 지원해야** 합니다. `maxOf`는 `>`를 쓰므로, `>`가 없는 타입을 넣으면 에러가 나요. 9강의 연산자 오버로딩이 여기서 연결됩니다.

```cpp
Point a(1, 2), b(3, 4);
maxOf(a, b);   // 에러! Point에는 operator>가 없음
```

`Point`에 `operator>`를 만들어주면 `maxOf`가 Point에도 동작합니다. **템플릿은 "필요한 연산만 갖춰져 있으면 어떤 타입이든 받는다"**는 방식이에요.

## 5. 타입 매개변수 여러 개

```cpp
template <typename A, typename B>
void printPair(A first, B second) {
    std::cout << first << " / " << second << std::endl;
}

printPair(10, "apple");     // 10 / apple    (A = int, B = const char*)
printPair(3.14, 'x');       // 3.14 / x
```

## 6. 클래스 템플릿

함수뿐 아니라 **클래스도 템플릿**으로 만들 수 있어요. 이게 `vector<int>`의 정체입니다.

```cpp
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T get() const { return value; }
    void set(T v) { value = v; }
};

int main() {
    Box<int> a(10);              // T = int
    Box<std::string> b("hello"); // T = string

    std::cout << a.get() << std::endl;   // 10
    std::cout << b.get() << std::endl;   // hello
    return 0;
}
```

함수 템플릿과 달리 클래스는 **타입을 `<>`로 직접 써줘야** 해요 (`Box<int>`). `vector<int>`, `vector<string>`이 바로 이렇게 만들어진 것입니다. 누군가 `template <typename T> class vector { ... };`를 만들어둔 거예요.

## 7. 실습: 간단한 vector 직접 만들어보기 (맛보기)

템플릿 클래스의 감을 잡기 좋은 예시로, 값을 두 개만 담는 `Pair`를 만들어볼게요.

```cpp
template <typename T>
class Pair {
public:
    T first, second;
    Pair(T a, T b) : first(a), second(b) {}

    T bigger() const {
        return (first > second) ? first : second;
    }
};

int main() {
    Pair<int> p(3, 9);
    Pair<double> q(1.5, 0.5);

    std::cout << p.bigger() << std::endl;   // 9
    std::cout << q.bigger() << std::endl;   // 1.5
    return 0;
}
```

## 8. 주의할 점 3가지

1. **템플릿 코드는 보통 헤더 파일(`.h`)에 통째로 넣어요.** 컴파일러가 인스턴스화할 때 함수 몸체를 봐야 해서, 선언은 `.h`, 정의는 `.cpp`로 나누는 일반 규칙이 템플릿에는 통하지 않습니다. 나중에 파일을 나눌 때 다시 설명할게요.
2. **에러 메시지가 매우 길고 읽기 어렵습니다.** 템플릿 에러는 수십 줄이 나오기도 하는데, 보통 **맨 위의 첫 줄과 "required from here"가 가리키는 내 코드 줄**만 보면 됩니다.
3. 기본 타입 이름이 `T`일 필요는 없지만 관례라서 대부분 `T`를 씁니다. 처음 보는 코드에서 `template <typename T>`가 나오면 "T는 타입 빈칸"이라고 읽으면 돼요.

> 💡 `template <typename T>` 대신 `template <class T>`로 쓰는 코드도 많아요. 둘은 이 자리에서 **완전히 같은 뜻**입니다.

---

## 📌 오늘의 요약

1. 템플릿은 **타입을 빈칸(`T`)으로 둔 틀**이며, 타입만 다르고 코드가 같은 함수/클래스를 한 번만 작성하게 해준다.
2. 함수 템플릿은 호출할 때 인자를 보고 `T`를 **자동 추론**하고, 필요하면 `maxOf<double>(...)`처럼 직접 지정한다.
3. 컴파일러가 사용된 타입마다 진짜 함수/클래스를 **컴파일 시점에** 만들어주므로(인스턴스화) 실행 속도 손해가 없다.
4. 템플릿 안에서 쓰는 연산(`>`, `+` 등)은 그 타입이 지원해야 하며, 직접 만든 클래스는 **연산자 오버로딩**으로 지원할 수 있다.
5. 클래스 템플릿은 `Box<int>`처럼 타입을 `<>`로 직접 써서 사용하며, `vector<int>`가 바로 이런 클래스 템플릿이다.
6. 템플릿 코드는 보통 헤더 파일에 통째로 작성한다.

---