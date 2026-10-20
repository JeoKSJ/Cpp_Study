#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// ==========================================================
// 메모리 누수(Memory Leak)
void f() {
    int* p = new int(10);
}

// ==========================================================
// 예외로 건너뜀
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
};
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
};
void mayThrow() {
    throw invalid_argument("문제발생?");
}

void g() {
    Animal* a = new Dog("초코");
    mayThrow(); // 예외 발생 시 밑의 delete가 동작 안함.
    delete a;
}

// ==========================================================
// 이중 해제
void double_delete() {
    int* p = new int(10);
    delete p;
    delete p;   // 같은 것을 두번 지울 시 프로그램이 죽을 수 있음.
}

// ==========================================================
// 댕글링 포인트(dangling pointer) : 지운 것을 사용
void dangling_pointer(){
    int* p = new int(10);
    delete p;
    cout << *p; // 반납한 메모리를 사용.
}

int main() {}