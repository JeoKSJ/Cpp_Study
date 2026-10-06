#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 복합 대입 +=와 증가 ++
class Counter {
public:
    int value = 0;

    Counter& operator+=(int n){
        value += n;
        return *this;   // 자기 자신을 돌려줌(this: 포인터 / *this: 객체 자신)
    }

    Counter& operator++(){  // 전위 ++c
        value++;
        return *this;
    }

    Counter operator++(int){    // 후위 c++ (int는 cpp에서 정한 구분용 더미)
        Counter old = *this;
        value++;
        return old;             // 증가 전 값을 돌려줌
    }
};

int main() {
    Counter c;

    (c += 5) += 5;
    cout << c.value << endl;

    ++c;
    cout << c.value << endl;

    c++;
    cout << c.value << endl;

    c.value = 10;

    Counter a = ++c;    // 전위: 먼저 올리고, 올린 뒤의 c를 줌
    cout << a.value << ", " << c.value << endl;
    // a.value = 11, c.value = 11

    Counter b = c++;    // 후위: 올리되, 올리기 전 값을 줌
    cout << b.value << ", " << c.value << endl;
    // b.value = 11, c.value = 12
    
    return 0;
}