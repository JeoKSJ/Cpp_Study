#include <iostream>
#include <string>

// 소멸자(Destructor)에 대해서
// 소멸자는 객체가 소멸될 때 자동으로 호출되는 특별한 함수입니다. 
// 소멸자는 클래스 이름 앞에 ~를 붙여 정의하며,객체가 소멸될 때 필요한 정리 작업을 수행할 수 있습니다. 
// 예를 들어, 동적 메모리 해제, 파일 닫기 등의 작업을 수행할 수 있습니다.

class Person {
public:
    std::string name;

    Person(std::string n) : name(n) {
        std::cout << name << " 생성됨" << std::endl;
    }

    ~Person() {   // 소멸자: 클래스 이름 앞에 ~ 를 붙임
        std::cout << name << " 소멸됨" << std::endl;
    }
};

int main() {
    Person p1("철수");
    std::cout << "프로그램 실행 중..." << std::endl;
    return 0; // 여기서 p1이 소멸되면서 소멸자가 자동으로 호출됩니다.
}
// 출력:
// 철수 생성됨
// 프로그램 실행 중...
// 철수 소멸됨   <- main 함수가 끝나면서 p1이 자동으로 소멸됨