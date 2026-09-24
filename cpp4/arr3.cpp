#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x; // int*란 포인터 변수 선언, &x는 x의 주소를 가져오는 연산자
    // 포인터는 메모리 주소를 저장하는 변수로 사용됨.

    cout << x << endl;      // x의 값
    cout << &x << endl;     // x의 주소
    cout << ptr << endl;    // ptr에 저장된 값 = x의 주소
    cout << *ptr << endl;   // ptr이 가리키는 곳의 값 = x의 값

    return 0;
}

// 10
// 0x7fffc165bedc
// 0x7fffc165bedc
// 10