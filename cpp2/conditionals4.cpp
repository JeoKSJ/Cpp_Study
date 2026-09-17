#include <iostream>

int main() {
    // for 루프를 사용하여 1부터 5까지 반복하면서 각 반복 횟수를 출력
    for (int i = 1; i <= 5; ++i) {
        std::cout << "This is iteration number: " << i << std::endl;
    }

    std::cout << std::endl; // 줄바꿈

    int count = 0;
    while (count < 5) {
        std::cout << "This is iteration number: " << (count + 1) << std::endl;
        ++count;
        // ++의 의미 : count = count + 1; 또는 count += 1; 과 동일한 의미로, count의 값을 1 증가시킨다.
        // --의 의미 : count = count - 1; 또는 count -= 1; 과 동일한 의미로, count의 값을 1 감소시킨다.
        // ++와 --는 단항 연산자(unary operator)로, 변수의 값을 1씩 증가시키거나 감소시키는 역할을 한다.
        // ++와 --는 변수 앞에 붙으면 전위 연산자(prefix operator)로, 변수의 값을 먼저 증가시키거나 감소시킨 후에 그 값을 사용한다.
        // ++와 --는 변수 뒤에 붙으면 후위 연산자(postfix operator)로, 변수의 값을 먼저 사용한 후에 그 값을 증가시키거나 감소시킨다
    }
}

// This is iteration number: 1
// This is iteration number: 2
// This is iteration number: 3
// This is iteration number: 4
// This is iteration number: 5

// This is iteration number: 1
// This is iteration number: 2
// This is iteration number: 3
// This is iteration number: 4
// This is iteration number: 5