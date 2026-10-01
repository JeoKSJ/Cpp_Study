#include <iostream>
#include <string>
using namespace std;

// 클래스를 정의합니다.
// 클래스는 구조체와 유사하지만, 멤버 변수와 멤버 함수를 포함할 수 있는 사용자 정의 데이터 타입입니다.
// 클래스는 객체 지향 프로그래밍의 핵심 개념 중 하나입니다.
class Person {
    public:
        string name;    // 클래스 멤버 변수(속성)를 정의합니다.
        int age;

        void introduce() {  // 클래스 멤버 함수(메서드)를 정의합니다.
            cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
        }
};

int main() {
    Person p1; // Person 클래스의 인스턴스를 생성합니다.
    p1.name = "Alice"; // 클래스 멤버에 값을 할당합니다.
    p1.age = 30;

    p1.introduce(); // introduce 메서드를 호출합니다.

    return 0;
}

// Hello, my name is Alice and I am 30 years old.