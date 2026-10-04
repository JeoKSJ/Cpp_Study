#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 다형성(Polymorphism) 예제
// Animal 클래스는 기본 클래스(Base Class)로, makeSound() 메서드를 가상 함수(virtual function)로 선언
// Dog와 Cat 클래스는 Animal 클래스를 상속받아 makeSound() 메서드를 오버라이딩(Overriding)함
// main() 함수에서는 Animal 포인터를 사용하여 Dog와 Cat 객체를 생성하고, makeSound() 메서드를 호출
// 이를 통해 다형성을 구현하고, 각 객체의 타입에 따라 다른 소리를 출력함

class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    
    virtual void makeSound() {
        cout << name << ": 동물 소리" << endl;
    }
};

class Dog : public Animal{
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << ": 멍멍!" << endl;
    }
};

class Cat : public Animal{
public:
    Cat(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << ": 야옹!" << endl;
    }
};

int main() {
    vector<Animal*> animals;
    animals.push_back(new Dog("초코"));
    animals.push_back(new Cat("나비"));
    
    for(Animal* a : animals) {
        a->makeSound();
    }
    // 초코: 멍멍!
    // 나비: 야옹!
    
    for(Animal* a : animals){
        delete a;
    }
    return 0;
}

// Vector에 대해서
// Vector는 동적 배열(Dynamic Array)로, 크기가 자동으로 조절되는 컨테이너(Container)입니다.
// Vector는 배열과 달리 크기를 미리 지정할 필요가 없으며, 요소를 추가하거나 제거할 때 자동으로 크기가 조절됩니다.
// Vector는 요소를 순차적으로 저장하며, 인덱스를 사용하여 요소에 접근할 수 있습니다.(예: animals[0], animals[1])