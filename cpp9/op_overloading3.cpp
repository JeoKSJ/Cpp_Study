#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Counter {
public:
    int value;

    Counter& operator+=(int n){
        value += n;
        return *this;   // 자기 자신을 돌려줌(this: 포인터 / *this: 객체 자신)
    }

    Counter& operator++(){  // 전위 ++c
        value++;
        return *this;
    }

    Counter operator++(int){    // 후위 c++ (int는 구분용 더미)
        Counter old = *this;
        value++;
        return old;             // 증가 전 값을 돌려줌
    }
};
