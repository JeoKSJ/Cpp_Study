#include <iostream>
#include <string>
using namespace std;

// 구조체를 정의합니다.
// 구조체는 여러 개의 관련된 데이터를 하나의 단위로 묶을 수 있는 사용자 정의 데이터 타입입니다.
struct Person {
    string name;
    int age;
    double height;
};

int main() {
    Person p1; // Person 구조체의 인스턴스를 생성합니다.
    p1.name = "Alice"; // 구조체 멤버에 값을 할당합니다.
    p1.age = 30;
    p1.height = 5.5;

    cout << p1.name << ", " << p1.age << ", " << p1.height << endl;
    return 0;
}

// Alice, 30, 5.5