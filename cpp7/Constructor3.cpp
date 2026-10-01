#include <iostream>
#include <string>
using namespace std;

// this 포인터에 대해서
// 클래스의 멤버 함수에서 this 포인터는 해당 객체를 가리키는 포인터로 
// 이를 통해 객체의 멤버에 접근할 수 있습니다.

class Person {
public:
    string name;
    int age;

    // 멤버 함수 안에서 매개변수 이름과 멤버 변수 이름이 같으면?
    void setName(string name) {
        // name = name; // 매개변수가 자기 자신에 대입하는 꼴 -> 값이 변경되지 않음
        // 따라서 멤버 변수 name을 가리키기 위해서는 this 포인터를 사용해야 합니다.
        this->name = name; // this 포인터를 사용하여 멤버 변수에 접근
        // 여기서 this->name은 현재 객체의 name 멤버 변수를 가리키고,
        // name은 매개변수 name을 가리킵니다.
        // 따라서 this->name = name;은 매개변수 name의 값을 멤버 변수 name에 대입하는 의미가 됩니다.
    }
};

int main() {
    Person p1;
    p1.setName("Bob");
    cout << "Name: " << p1.name << endl; // Name: Bob
    return 0;
}

// 복습
// 1. 매개변수는 함수 호출 시 전달되는 값으로, 함수 내부에서만 유효합니다.
// 2. 멤버 변수는 클래스의 객체가 생성될 때 함께 생성되며, 객체가 소멸될 때 함께 소멸됩니다.
// 3. 멤버 함수 안에서 매개변수 이름과 멤버 변수 이름이 같으면, 
//    매개변수가 우선적으로 사용되므로 멤버 변수에 접근하려면 this 포인터를 사용해야 합니다.