// 사용(main.cpp로 보통 파일명 정의)
#include <iostream>
#include "math_utils.h"
using namespace std;

int main() {
    cout << add(3, 4) << endl;
    cout << sub(3, 4) << endl;
    cout << multiply(3, 4) << endl;
    cout << divide(3, 4) << endl;
    return 0;
}

// 컴파일 할 때 필수
// main.cpp와 math_utils.h의 헤더 선언의 동작 방식을 설명할 math_utils.cpp를 같이 컴파일 해야함.
// g++ main.cpp define/math_utils.cpp -o main
/*
7
-1
12
0  (int로 선언이라 소숫점 제외.)
*/