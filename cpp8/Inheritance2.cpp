#include <iostream>
#include <string>
using namespace std;

// protected: private와 public 사이

class Animal {
protected:
    string name;    // 자식 클래스에서는 접근이 가능하나 외부에서는 불가하다
public:
    Animal(string n) : name(n) {}
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void bark() {
        cout << name << "가 짖습니다!" << endl;   // protected는 자식 클래스에서는 접근이 가능하다.
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    
    void Meow() {
        cout << name << "가 야옹거립니다!" << endl;
    }
};


int main() {
    Dog d("초코");
    Cat c("나비");
    // d.name = "모기"   // 외부에서는 접근이 불가능.
    return 0;
}