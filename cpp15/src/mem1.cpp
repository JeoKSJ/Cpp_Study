#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 메모리 구성의 두 영역: stack & heap
// 스택은 int x = 10; 과 같은 일반 변수로 선언 후 블럭 안에서만 사용됨.
// 힙은 new로 직접 요청하고 직접 delete를 해야 함. 정한 만큼의 용량을 가진다.

// new 와 delete의 기본
// new로 만든건 delete로 지운다.(배열 [] 은 delete[] 로)
int main() {
    int* p = new int(10);
    cout << *p << endl; // 10
    delete p;

    int* arr = new int[5];
    delete[] arr;
}