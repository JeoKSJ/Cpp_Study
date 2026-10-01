#include <iostream>
#include <string>
using namespace std;

// class의 public과 private 접근 지정자에 대해 설명합니다.
// public 접근 지정자는 클래스 외부에서 멤버 변수와 멤버 함수에 접근할 수 있도록 허용합니다.
// private 접근 지정자는 클래스 외부에서 멤버 변수와 멤버 함수에 접근할 수 없도록 제한합니다. 
// 기본적으로 클래스의 멤버 변수와 멤버 함수는 private로 설정됩니다.

class Person {
    private:
        int age; // private 멤버 변수는 클래스 외부에서 직접 접근할 수 없습니다.
    public:
        string name; // public 멤버 변수는 클래스 외부에서 접근할 수 있습니다

        void setAge(int newAge) { // setter: private 멤버 변수 age의 값을 설정하는 public 메서드입니다.
            if (newAge >= 0) { // 나이는 음수가 될 수 없으므로 조건을 확인합니다.
                age = newAge; // 유효한 나이일 경우에만 값을 설정합니다.
            } else {
                cout << "Invalid age!" << endl; // 유효하지 않은 나이일 경우 경고 메시지를 출력합니다.
            }
        }
        int getAge() { // getter: private 멤버 변수 age의 값을 반환하는 public 메서드입니다.
            return age; // private 멤버 변수 age의 값을 반환합니다.
        }
};

int main() {
    Person p1; // Person 클래스의 인스턴스를 생성합니다.
    p1.name = "Alice"; // public 멤버 변수에 값을 할당합니다.
    p1.setAge(30); // private 멤버 변수 age에 값을 설정하기 위해 setAge 메서드를 호출합니다.

    cout << p1.name << ", " << p1.getAge() << endl; // getAge 메서드를 호출하여 age 값을 출력합니다.

    p1.setAge(-5); // 유효하지 않은 나이를 설정하려고 시도합니다.

    return 0;
}

/*
Alice, 30
Invalid age!
*/