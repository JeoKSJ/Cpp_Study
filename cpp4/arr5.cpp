#include <iostream>
using namespace std;

// 함수에서 포인터 연결하기.
void increase(int* num){
    *num += 1;
}

int main() {
    int x = 10;
    increase(&x);   // int* num = &x;
    cout << x << endl;
    return 0;
}

// 11