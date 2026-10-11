#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 클래스로 템플릿 선언하기
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T get() const { return value; }
    void set(T v) { value = v; }
};

int main() {
    // 함수 템플릿과 다르게 타입을 <>로 선언해줘야함.
    Box<int> a(10);                 // T = int
    Box<string> b("hello");         // T = string

    cout << a.get() << endl;   // 10
    cout << b.get() << endl;   // hello
    a.set(20);                 // 변경 (void set(T v))
    cout << a.get() << endl;   // 20
    return 0;
}