#include <iostream>

// 함수 선언: add라는 이름의 함수가 int형 매개변수 a와 b를 받아서 int형 값을 반환한다는 것을 알려줌
int add(int a, int b); 

int main() {
    int sum = add(10, 20); // add 함수를 호출하여 10과 20을 더하고 결과를 sum 변수에 저장
    std::cout << "Sum: " << sum << std::endl; // 결과 출력
    return 0;
}

int add(int a, int b) { // 함수 정의: add 함수가 실제로 어떻게 동작하는지 구현
    return a + b; // a와 b를 더한 값을 반환
}

// 함수 선언(prototype)과 함수 정의(function definition)의 차이점
// 함수 선언은 함수의 이름, 반환형, 매개변수의 타입을 알려주는 역할만 하고 실제로 함수가 어떻게 동작하는지는 정의하지 않음
// 함수 정의는 함수가 실제로 어떤 동작을 수행하는지 구현하는 부분으로, 함수 선언과 달리 함수의 본문(body)을 포함함
// 함수 선언은 보통 헤더 파일에 작성하고, 함수 정의는 소스 파일에 작성하는 것이 일반적임
// Sum: 30