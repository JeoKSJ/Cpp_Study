#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::introduce() const {
    std::cout << name << " (" << age << "세)" << std::endl;
}

int Person::getAge() const {
    return age;
}