#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    void introduce() {
        std::cout << name << " (" << age << "세)" << std::endl;
    }
};

int main() {
    Person p1;  // Person 클래스의 p1 인스턴스 생성
    p1.name = "철수"; p1.age = 25;

    Person p2;  // Person 클래스의 p2 인스턴스 생성
    p2.name = "영희"; p2.age = 23;

    p1.introduce();  // 철수 (25세)
    p2.introduce();  // 영희 (23세)

    return 0;
}

/*
철수 (25세)
영희 (23세)
*/