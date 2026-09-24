#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {   // 널 포인트는 역참조(*ptr)시 crash가 뜬다.
        cout << "아직 아무것도 가리키지 않음" << endl;
    }
    return 0;
}