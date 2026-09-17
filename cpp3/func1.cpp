#include <iostream>

// 함수 정의: 두 정수를 더하는 함수
// 함수 이름 add에 int형 매개변수 a와 b를 받아서 그 합을 반환하는 함수
int add(int a, int b) {
    return a + b;
}

// void형 함수 : 반환값이 없이 단순히 기능만 수행하는 함수
void printMessage() {
    std::cout << "Hello from printMessage function!" << std::endl;
}

int main() {
    // 함수 호출: add 함수를 호출하여 3과 5를 더하고 결과를 sum 변수에 저장
    // 이때 넘기는 3과 5는 실제 매개변수(인자)라고 부른다.
    int sum = add(3, 5);
    std::cout << "Sum: " << sum << std::endl; // 결과 출력
    printMessage(); // printMessage 함수를 호출하여 메시지를 출력
    return 0;
}
// Sum: 8
// Hello from printMessage function!