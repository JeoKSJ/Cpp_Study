#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << x << endl; // Output: 10
    cout << &x << endl; // Output: Address of x in memory

    return 0;
}

// x라는 값 자체는 10으로 고정
// x라는 변수 자체를 담고있는 메모리의 주소는 실행할 때마다 달라질 수 있음.