#include <iostream>
#include <string>
using namespace std;

// class와 struct의 차이점에 대해 설명합니다.
// class는 기본적으로 멤버 변수와 멤버 함수가 private로 설정되며, struct는 기본적으로 public으로 설정됩니다.
// class는 객체 지향 프로그래밍에서 사용되며, struct는 주로 데이터를 묶는 용도로 사용됩니다.
class Person { int x; }; // class의 기본 접근 지정자는 private입니다.
struct Person2 { int x; }; // struct의 기본 접근 지정자는 public입니다.

int main() {
    Person p1; // Person 클래스의 인스턴스를 생성합니다.
    // p1.x = 10; // 오류: x는 private 멤버이므로 외부에서 접근할 수 없습니다.

    Person2 p2; // Person2 구조체의 인스턴스를 생성합니다.
    p2.x = 10; // 정상: x는 public 멤버이므로 외부에서 접근할 수 있습니다.

    cout << "p2.x: " << p2.x << endl; // p2.x: 10
    return 0;
}