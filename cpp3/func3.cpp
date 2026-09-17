#include <iostream>

// 값의 전달(Pass by Value)과 참조의 전달(Pass by Reference)

void incrementByValue(int num) {
    num++; // num의 값을 1 증가시키지만, main 함수의 변수에는 영향을 주지 않음
}

void incrementByReference(int& num) {
    num++; // num의 값을 1 증가시키며, main 함수의 변수에도 영향을 줌
}

int main() {
    int value = 10;

    std::cout << "Before incrementByValue: " << value << std::endl;
    incrementByValue(value); // 값의 전달
    std::cout << "After incrementByValue: " << value << std::endl; // value는 여전히 10

    std::cout << "Before incrementByReference: " << value << std::endl;
    incrementByReference(value); // 참조의 전달
    std::cout << "After incrementByReference: " << value << std::endl; // value는 이제 11

    return 0;
}

// 값의 전달(Pass by Value)과 참조의 전달(Pass by Reference)의 차이점
// 1. 값의 전달(Pass by Value): 함수에 인자를 전달할 때, 인자의 값을 복사하여 함수 내부로 전달. 함수 내부에서 인자의 값을 변경해도, 원래의 변수에는 영향을 주지 않음.
// 2. 참조의 전달(Pass by Reference): 함수에 인자를 전달할 때, 인자의 메모리 주소를 전달. 함수 내부에서 인자의 값을 변경하면, 원래의 변수에도 영향을 줌.
// 위 예제에서 incrementByValue 함수는 value 변수의 값을 복사하여 num이라는 새로운 변수를 생성하고, 그 변수의 값을 증가시킴. 따라서 main 함수의 value 변수에는 영향을 주지 않음.
// 반면, incrementByReference 함수는 value 변수의 메모리 주소를 전달받아 num이라는 참조 변수를 생성하고, 그 변수의 값을 증가시킴. 따라서 main 함수의 value 변수에도 영향을 줌.

// Before incrementByValue: 10
// After incrementByValue: 10
// Before incrementByReference: 10
// After incrementByReference: 11