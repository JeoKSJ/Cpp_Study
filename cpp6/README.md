## 1. 구조체(struct)란?

지금까지는 데이터를 각각 변수로 따로 관리했습니다. 하지만 "한 사람"의 정보(이름, 나이, 키)처럼 **서로 관련된 데이터를 하나로 묶고 싶을 때** 구조체를 씁니다.

```cpp
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    Person p1;
    p1.name = "김철수";
    p1.age = 25;
    p1.height = 175.5;

    std::cout << p1.name << ", " << p1.age << "세" << std::endl;
    return 0;
}
```

- `.`(점)으로 구조체 안의 데이터(**멤버**)에 접근합니다.
- 선언과 동시에 초기화도 가능합니다: `Person p2 = {"이영희", 23, 162.0};`

## 2. 구조체 배열

구조체도 배열로 여러 개 관리할 수 있습니다.

```cpp
struct Person {
    std::string name;
    int age;
};

int main() {
    Person people[3] = {
        {"철수", 25},
        {"영희", 23},
        {"민수", 30}
    };

    for (int i = 0; i < 3; i++) {
        std::cout << people[i].name << ": " << people[i].age << "세" << std::endl;
    }
    return 0;
}
```

## 3. 클래스(class)란?

클래스는 구조체와 거의 비슷하지만, **데이터(변수)뿐 아니라 그 데이터를 다루는 동작(함수)까지 함께 묶을 수 있습니다.** 이게 바로 "객체지향"의 핵심입니다.

```cpp
class Person {
public:
    std::string name;
    int age;

    void introduce() {
        std::cout << "안녕하세요, 저는 " << name << "이고 " << age << "살입니다." << std::endl;
    }
};

int main() {
    Person p1;
    p1.name = "김철수";
    p1.age = 25;
    p1.introduce();   // 안녕하세요, 저는 김철수이고 25살입니다.
    return 0;
}
```

- 클래스 안에 정의된 변수를 **멤버 변수**, 함수를 **멤버 함수(메서드)**라고 부릅니다.
- `introduce()` 함수 안에서 `name`, `age`를 매개변수로 안 받았는데도 쓸 수 있죠? 멤버 함수는 **자기가 속한 객체의 멤버 변수에 자동으로 접근**할 수 있기 때문입니다.

## 4. public / private — 접근 제어

클래스의 가장 중요한 특징 중 하나는 **멤버를 외부에서 함부로 못 건드리게 막을 수 있다**는 점입니다.

```cpp
class Person {
private:
    int age;   // 외부에서 직접 접근 불가

public:
    std::string name;   // 외부에서 자유롭게 접근 가능

    void setAge(int newAge) {
        if (newAge >= 0) {   // 음수 방지 같은 검증 가능
            age = newAge;
        }
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person p1;
    p1.name = "철수";        // OK (public)
    p1.setAge(25);           // OK, 함수를 통해 간접적으로 설정
    // p1.age = -5;          // 에러! private는 외부에서 직접 접근 불가

    std::cout << p1.getAge() << std::endl;  // 25
    return 0;
}
```

- `private`: 클래스 내부(멤버 함수)에서만 접근 가능
- `public`: 클래스 외부에서도 자유롭게 접근 가능
- 이렇게 데이터를 숨기고 함수를 통해서만 접근하게 하는 걸 **캡슐화(encapsulation)**라고 합니다. `setAge`처럼 값을 검증하는 로직을 넣을 수 있어서, 잘못된 값이 들어오는 걸 막을 수 있습니다.
- 보통 `age`처럼 직접 접근을 막는 멤버 변수를 설정/조회하는 함수를 각각 **setter**(`setAge`), **getter**(`getAge`)라고 부릅니다.

## 5. struct vs class, 뭐가 다를까?

사실 C++에서 `struct`와 `class`는 **딱 하나만 다릅니다**: 아무것도 안 적었을 때 기본 접근 권한이 `struct`는 `public`, `class`는 `private`이라는 점뿐입니다.

```cpp
struct A { int x; };   // x는 기본적으로 public

class B { int x; };    // x는 기본적으로 private
```

관례적으로는 **단순히 데이터만 묶을 때는 `struct`**, **동작(함수)까지 포함하고 캡슐화가 필요할 때는 `class`**를 사용합니다.

## 6. 여러 객체 만들기

클래스는 "설계도"이고, 그 설계도로 찍어낸 실체를 **객체(object)** 또는 **인스턴스(instance)**라고 부릅니다.

```cpp
class Person {
public:
    std::string name;
    int age;

    void introduce() {
        std::cout << name << " (" << age << "세)" << std::endl;
    }
};

int main() {
    Person p1;
    p1.name = "철수"; p1.age = 25;

    Person p2;
    p2.name = "영희"; p2.age = 23;

    p1.introduce();  // 철수 (25세)
    p2.introduce();  // 영희 (23세)

    return 0;
}
```

`p1`과 `p2`는 같은 설계도(`Person` 클래스)에서 나왔지만, 각자 독립적인 `name`, `age` 값을 가집니다.

---

## 📌 오늘의 요약

1. 구조체(`struct`)는 서로 관련된 데이터를 하나로 묶는 자료형이며, `.`으로 멤버에 접근한다.
2. 클래스(`class`)는 구조체에 **멤버 함수(동작)**까지 더한 것으로, 객체지향 프로그래밍의 핵심이다.
3. 멤버 함수는 매개변수 없이도 자신이 속한 객체의 멤버 변수에 접근할 수 있다.
4. `private`는 클래스 내부에서만, `public`은 외부에서도 접근 가능하며, 데이터를 숨기고 함수로만 다루게 하는 걸 **캡슐화**라 한다.
5. `struct`와 `class`는 **기본 접근 제어(public/private)**만 다르며, 관례상 단순 데이터 묶음엔 struct, 동작 포함 시 class를 쓴다.
6. 클래스는 설계도, 객체(인스턴스)는 그 설계도로 만든 실체이며, 객체마다 독립적인 데이터를 가진다.

---