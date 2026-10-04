#include <iostream>
#include <string>
using namespace std;


// 함수 재정의(Overriding) : 자식 클래스에서 부모 클래스의 함수를 같은 이름으로 재정의
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

class Cat : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() {
        cout << name << ": 야옹!" << endl;
    }
};

int main() {
    Dog d("초코");
    Cat c("나비");
    d.makeSound();
    c.makeSound();
    return 0;
}