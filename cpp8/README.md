## 1. 상속(Inheritance)이란?

이미 만들어진 클래스의 멤버 변수와 함수를 **물려받아서** 새로운 클래스를 만드는 것입니다. 중복 코드를 줄이고, "공통된 부분 + 각자 다른 부분"으로 구조를 나눌 수 있습니다.

```cpp
class Animal {
public:
    std::string name;

    Animal(std::string n) : name(n) {}

    void eat() {
        std::cout << name << "가 먹이를 먹습니다." << std::endl;
    }
};

class Dog : public Animal {   // Dog가 Animal을 상속받음
public:
    Dog(std::string n) : Animal(n) {}   // 부모의 생성자를 호출

    void bark() {
        std::cout << name << "가 짖습니다: 멍멍!" << std::endl;
    }
};

int main() {
    Dog d("초코");
    d.eat();   // Animal에게서 물려받은 함수 (초코가 먹이를 먹습니다.)
    d.bark();  // Dog만의 함수 (초코가 짖습니다: 멍멍!)
    return 0;
}
```

용어 정리:

- `Animal` : **부모 클래스**(기반 클래스, base class)
- `Dog` : **자식 클래스**(파생 클래스, derived class)
- `class Dog : public Animal` : "Dog는 Animal을 public으로 상속받는다"는 뜻
- `Dog`는 `Animal`의 `name`, `eat()`을 그대로 물려받고, 자기만의 `bark()`도 추가로 가집니다.

### 부모 생성자 호출하기

`Dog(std::string n) : Animal(n) {}` 부분을 주목하세요. 7강에서 배운 멤버 초기화 리스트 문법으로, **부모 클래스의 생성자를 명시적으로 호출**하는 것입니다. 자식 클래스가 만들어질 때는 부모 클래스 부분이 먼저 초기화되어야 하기 때문에, 이렇게 부모 생성자에게 필요한 값을 넘겨줘야 합니다.

## 2. protected — private과 public 사이

```cpp
class Animal {
protected:
    std::string name;   // 자식 클래스에서는 접근 가능, 외부에서는 불가

public:
    Animal(std::string n) : name(n) {}
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}

    void bark() {
        std::cout << name << "가 짖습니다!" << std::endl;  // OK, protected는 자식 클래스에서 접근 가능
    }
};

int main() {
    Dog d("초코");
    // d.name = "용팔이";  // 에러! 외부에서는 여전히 접근 불가
    return 0;
}
```

| 접근 제어 | 클래스 내부 | 자식 클래스 | 외부 |
|---|---|---|---|
| `private` | O | X | X |
| `protected` | O | O | X |
| `public` | O | O | O |

## 3. 함수 재정의 (Overriding)

자식 클래스에서 부모의 함수를 **같은 이름으로 다시 정의**해서 동작을 바꿀 수 있습니다.

```cpp
class Animal {
public:
    std::string name;
    Animal(std::string n) : name(n) {}

    void makeSound() {
        std::cout << name << ": 동물 소리" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}

    void makeSound() {   // 부모의 makeSound를 재정의(override)
        std::cout << name << ": 멍멍!" << std::endl;
    }
};

int main() {
    Dog d("초코");
    d.makeSound();   // "초코: 멍멍!" (Dog의 버전이 호출됨)
    return 0;
}
```

> ⚠️ 이름이 3강의 "오버로딩(overloading)"과 비슷해서 헷갈리기 쉬운데 다른 개념이에요. **오버로딩**은 같은 클래스 안에서 매개변수가 다른 함수를 여러 개 만드는 것, **오버라이딩**은 부모-자식 관계에서 같은 형태의 함수를 자식이 다시 정의하는 것입니다.

## 4. 다형성(Polymorphism)과 virtual 키워드

여기가 오늘의 핵심입니다. 아래 코드를 보세요.

```cpp
class Animal {
public:
    std::string name;
    Animal(std::string n) : name(n) {}

    void makeSound() {
        std::cout << name << ": 동물 소리" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}

    void makeSound() {
        std::cout << name << ": 멍멍!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Dog("초코");  // Animal 포인터가 Dog 객체를 가리킴
    animalPtr->makeSound();               // 어떤 게 호출될까?
    return 0;
}
```

직관적으로는 "`Dog` 객체니까 `Dog`의 `makeSound()`가 호출되겠지"라고 생각하기 쉽지만, **놀랍게도 `Animal`의 `makeSound()`가 호출됩니다** ("초코: 동물 소리"). 포인터의 타입(`Animal*`)을 기준으로 어떤 함수를 호출할지 **컴파일 시점에 미리 정해버리기 때문**입니다.

이걸 "진짜 가리키고 있는 객체(`Dog`)의 함수가 호출되도록" 바꾸려면 `virtual` 키워드가 필요합니다.

```cpp
class Animal {
public:
    std::string name;
    Animal(std::string n) : name(n) {}

    virtual void makeSound() {   // virtual 추가!
        std::cout << name << ": 동물 소리" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}

    void makeSound() override {   // override는 선택이지만 붙이는 걸 권장
        std::cout << name << ": 멍멍!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Dog("초코");
    animalPtr->makeSound();   // 이제 "초코: 멍멍!" (Dog의 버전이 호출됨!)

    delete animalPtr;
    return 0;
}
```

- 부모 클래스에서 함수 앞에 `virtual`을 붙이면, "이 함수는 자식 클래스가 재정의했으면 **실제 객체 타입에 맞는 버전**을 호출해라"는 뜻이 됩니다.
- `override`는 "나는 부모의 virtual 함수를 재정의하는 거다"라고 컴파일러에게 명시적으로 알려주는 키워드입니다. 필수는 아니지만, 철자를 잘못 써서 재정의가 안 되는 실수를 컴파일러가 잡아주기 때문에 습관적으로 붙이는 걸 권장합니다.

## 5. 다형성이 왜 유용할까?

여러 종류의 동물을 하나의 배열(또는 벡터)에 담아서, 각자 다르게 동작하게 할 수 있습니다.

```cpp
class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {}
    void makeSound() override {
        std::cout << name << ": 야옹!" << std::endl;
    }
};

int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Dog("초코"));
    animals.push_back(new Cat("나비"));

    for (Animal* a : animals) {
        a->makeSound();   // 각자 실제 타입에 맞게 다르게 동작!
    }
    // 초코: 멍멍!
    // 나비: 야옹!

    for (Animal* a : animals) {
        delete a;   // 동적 할당한 건 꼭 정리
    }
    return 0;
}
```

`Dog`든 `Cat`이든 `Animal*` 타입으로 똑같이 다룰 수 있고, 호출만 하면 알아서 각자 맞는 동작을 하는 것 — 이게 다형성의 핵심 가치입니다. 호출하는 쪽(`for`문)은 "얘가 Dog인지 Cat인지" 전혀 몰라도 됩니다.

> 💡 `new`와 `delete`는 4강에서 살짝 언급했던 "동적 할당"과 관련된 문법이에요. 지금은 "객체를 메모리에 직접 만들고(`new`), 다 쓰면 직접 정리한다(`delete`)" 정도로만 이해하시면 되고, 본격적인 내용은 다음에 메모리 관리를 다룰 때 자세히 설명할게요.

## 6. 가상 소멸자 (살짝 주의할 점)

다형성을 쓸 때는 부모 클래스의 소멸자도 `virtual`로 만드는 게 안전합니다.

```cpp
class Animal {
public:
    virtual ~Animal() {   // 가상 소멸자
        std::cout << "Animal 소멸" << std::endl;
    }
};
```

그렇지 않으면 위 예제처럼 `Animal*`로 `Dog` 객체를 `delete`할 때, `Dog`의 소멸자가 제대로 호출되지 않을 수 있습니다. 지금은 "다형성을 쓰는 부모 클래스는 소멸자에 `virtual`을 붙이는 게 국룰"이라는 정도로 기억해두세요.

---

## 📌 오늘의 요약

1. `class 자식 : public 부모`로 **상속**하면, 부모의 멤버 변수/함수를 물려받고 자식만의 기능을 추가할 수 있다.
2. `protected`는 외부에는 막혀있지만 자식 클래스에는 열려있는 접근 제어다.
3. 자식이 부모와 같은 이름의 함수를 다시 정의하는 것을 **오버라이딩**이라 하며, 3강의 오버로딩과는 다른 개념이다.
4. 부모 타입 포인터로 자식 객체를 다룰 때, 실제 객체의 함수가 호출되게 하려면 부모 함수에 **`virtual`**을 붙여야 한다 (다형성).
5. 자식 쪽에서는 `override`를 붙여 재정의임을 명시하는 게 안전하다.
6. 다형성을 쓰면 서로 다른 자식 타입들을 부모 타입 하나로 통일해서 다룰 수 있다.
7. 다형성을 쓰는 클래스는 부모 소멸자도 `virtual`로 만드는 게 안전하다.

---