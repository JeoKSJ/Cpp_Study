#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    // 멤버 초기화 리스트를 사용한 생성자
    // 생성자 본문에서 대입 대신, 멤버 초기화 리스트를 사용하여 멤버 변수를 초기화합니다.
    Person(string n, int a) : name(n), age(a) {}
};

int main() {
    Person p1("Alice", 30);
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;
    return 0;
}

// Name: Alice, Age: 30