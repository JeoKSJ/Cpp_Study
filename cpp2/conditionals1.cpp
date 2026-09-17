# include <iostream>

int main() {
    // int score = 85; // 점수를 저장할 정수형 변수 score를 선언하고 초기화
    std::cout << "점수를 입력하시오.";
    int score; // 점수를 저장할 정수형 변수 score를 선언
    std::cin >> score; // 사용자로부터 점수를 입력받기

    // if-else if-else 조건문을 사용하여 점수에 따른 학점을 출력
    if (score >= 90) {
        std::cout << "A학점입니다." << std::endl;
    } else if (score >= 80) {
        std::cout << "B학점입니다." << std::endl;
    } else if (score >= 70) {
        std::cout << "C학점입니다." << std::endl;
    } else if (score >= 60) {
        std::cout << "D학점입니다." << std::endl;
    } else {
        std::cout << "F학점입니다." << std::endl;
    }
    return 0;
}

// 점수를 입력하시오.95
// A학점입니다.
// 점수를 입력하시오.0
// F학점입니다.