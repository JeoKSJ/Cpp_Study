#include <iostream>
#include <string>
using namespace std;

class Animal {  // Animal 부모 클래스
public:
    string name;

    Animal(string n) : name(n) {}   // 생성자: 이름 초기화

    void eat() {
        cout << name << "가 먹이를 먹습니다." << endl;
    }
};

class Dog : public Animal { // Dog 자식 클래스, Animal 클래스를 상속받음
public:
    Dog(string n) : Animal(n) {}    // 생성자: 부모 클래스의 생성자를 호출하여 이름 초기화

    void bark() {
        cout << name << "가 짖습니다: 멍멍!" << endl;
    }
};

int main() {
    Dog myDog("Buddy");
    myDog.eat();  // Animal 클래스의 eat() 함수 호출
    myDog.bark(); // Dog 클래스의 bark() 함수 호출
    return 0;
}

// 상속자를 쓰는 경우
// 1. 코드 재사용성 증가: 기존 클래스의 기능을 재사용하여 새로운 클래스를 만들 수 있습니다.
// 2. 계층 구조 표현: 객체 간의 관계를 계층 구조로 표현
// 3. 다형성 구현: 부모 클래스의 포인터나 참조를 통해 자식 클래스의 객체를 다룰 수 있어, 다양한 형태의 객체를 동일한 방식으로 처리할 수 있습니다.
// 4. 유지보수 용이: 공통 기능을 부모 클래스에 정의하면, 수정 시 자식 클래스에 영향을 주지 않고 유지보수가 용이합니다.

// 상속자를 쓰는 경우 주의할 점
// 1. 상속 남용: 불필요한 상속은 코드 복잡성을 증가시키고 유지보수를 어렵게 만들 수 있습니다.
// 2. 부모 클래스 변경 시 영향: 부모 클래스의 변경이 자식 클래스에 영향을 미칠 수 있으므로, 상속 구조를 설계할 때 신중해야 합니다.
// 3. 다중 상속의 복잡성: 다중 상속은 이름 충돌과 같은 문제를 야기할 수 있으므로, 필요할 때만 사용하고 가급적 피하는 것이 좋습니다.
// 4. 접근 제어: 상속 시 public, protected, private 접근 지정자를 적절히 사용하여 클래스 간의 접근을 제어해야 합니다.