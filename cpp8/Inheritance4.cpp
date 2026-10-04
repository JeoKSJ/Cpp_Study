#include <iostream>
#include <string>
using namespace std;

/*
class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    
    void makeSound() {
        cout << name << ": 동물 소리" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() {
        cout << name << ": 멍멍!" << endl;
    }
};

int main() {
    Animal* animalPtr = new Dog("초코");
    animalPtr->makeSound();
    return 0;
}
*/ 
// 해당 구문은 Dog를 가리켜 makeSound를 호출하는게 아님
// Animal* 을 기준으로 어떤걸 호출할 지 정해짐. 따라서 Animal 클래스 내부의 makeSound가 호출
// 진짜 가리키는 객체 Dog의 내부 함수가 호출되도록 하려면 virtual 키워드가 필요하다.

class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    
    virtual void makeSound() {
        cout << name << ": 동물 소리" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << ": 멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << ": 야옹!" << endl;
    }
};

int main() {
    Animal* animalptr1 = new Dog("초코");
    Animal* animalptr2 = new Cat("나비");
    
    animalptr1->makeSound();
    animalptr2->makeSound();
    
    delete animalptr1;
    delete animalptr2;
    return 0;
}

// 예상 출력
// 초코: 멍멍!
// 나비: 야옹!