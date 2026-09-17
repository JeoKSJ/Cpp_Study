#include <iostream>

int main() {
    int day = 3;

    // switch-case 조건문을 사용하여 요일을 출력
    switch (day) {
        case 1:
            std::cout << "Today is Monday." << std::endl;
            break;  // break 문은 switch문을 빠져나가게 하는 역할으로 없으면 다음 case 문으로 계속 실행된다.
        case 2:
            std::cout << "Today is Tuesday." << std::endl;
            break;
        case 3:
            std::cout << "Today is Wednesday." << std::endl;
            break;
        case 4:
            std::cout << "Today is Thursday." << std::endl;
            break;
        case 5:
            std::cout << "Today is Friday." << std::endl;
            break;
        case 6:
            std::cout << "Today is Saturday." << std::endl;
            break;
        case 7:
            std::cout << "Today is Sunday." << std::endl;
            break;
        default:
            std::cout << "Invalid day." << std::endl;
    }
}

// Today is Wednesday.

// break와 continue의 차이점
// break : 반복문(for, while, do-while) 또는 switch-case 문을 빠져나가게 하는 역할을 한다. 
// 반복문 내에서 break를 만나면 반복문이 종료된다.
// continue : 반복문 내에서 continue를 만나면 현재 반복을 건너뛰고 다음 반복으로 넘어간다.