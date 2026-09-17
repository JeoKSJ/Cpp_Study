#include <iostream>
#include <string> // 문자열(string)형 변수를 사용하기 위해 필요한 헤더 파일

int age = 25; // 정수(int)형 변수
double height = 175.5; // 실수(double)형 변수
char grade = 'A'; // 문자 하나(작은 따옴표)
bool isStudent = true; // 논리형(bool) 변수(true 또는 false)
std::string name = "John"; // 문자열(string)형 변수(큰 따옴표)

int main() {

    std::string name;   // 문자열(string)형 변수 선언
    int age;            // 정수(int)형 변수 선언

    std::cout << "Enter your name: ";
    std::cin >> name; // 사용자로부터 이름을 입력받기

    std::cout << "Enter your age: ";
    std::cin >> age; // 사용자로부터 나이를 입력받기

    // >> : 입력 연산자(input operator)
    // << : 출력 연산자(output operator)

    std::cout << name << "님은" << age << "살입니다." << std::endl; // 입력받은 이름과 나이를 출력
    return 0;
}