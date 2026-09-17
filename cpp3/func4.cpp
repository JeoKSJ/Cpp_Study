#include <iostream>

// 함수 오버로딩(Function Overloading) : 같은 이름의 함수를 여러 개 정의할 수 있는 기능
// 단, 매개변수의 타입이나 개수가 달라야 함

int add(int a, int b);
double add(double a, double b);
int add(int a, int b, int c);

int main() {
    int sum1 = add(10, 20); // int형 매개변수 2개를 받는 add 함수 호출
    double sum2 = add(10.5, 20.3); // double형 매개변수 2개를 받는 add 함수 호출
    int sum3 = add(1, 2, 3); // int형 매개변수 3개를 받는 add 함수 호출

    std::cout << "Sum1: " << sum1 << std::endl; // 결과 출력
    std::cout << "Sum2: " << sum2 << std::endl; // 결과 출력
    std::cout << "Sum3: " << sum3 << std::endl; // 결과 출력

    return 0;
}

int add(int a, int b) { // int형 매개변수 2개를 받는 add 함수 정의
    return a + b;
}
double add(double a, double b) { // double형 매개변수 2개를 받는 add 함수 정의
    return a + b;
}
int add(int a, int b, int c) { // int형 매개변수 3개를 받는 add 함수 정의
    return a + b + c;
}
// 함수 오버로딩(Function Overloading)의 장점
// 1. 코드의 가독성을 높일 수 있음 : 같은 이름의 함수를 사용하여 다양한 타입과 개수의 매개변수를 처리할 수 있으므로, 함수 이름을 기억하기 쉽고 코드가 직관적임
// 2. 유지보수가 용이함 : 새로운 기능을 추가할 때 기존 함수를 수정하지 않고, 새로운 매개변수 타입이나 개수를 가진 함수를 추가할 수 있으므로, 기존 코드에 영향을 주지 않고 기능을 확장할 수 있음
// 3. 코드 재사용성이 높음 : 같은 이름의 함수를 사용하여 다양한 타입과 개수의 매개변수를 처리할 수 있으므로, 코드의 중복을 줄이고 재사용성을 높일 수 있음
// Sum1: 30
// Sum2: 30.8
// Sum3: 6