#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    
    virtual void makeSound() {
        cout << name << ": 동물 소리" << endl;
    }
};

class Dog {
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << ": 멍멍!" << endl;
    }
};

class Cat {
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
    
    for(Animal* a : animals){
        delete a;
    }
    return 0;
}