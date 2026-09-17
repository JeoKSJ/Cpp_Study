#include <iostream> 
// 화면 출력(cout)과 입력(cin)기능이 정의된 표준 라이브러리

int main() { // 가장 먼저 호출되는 함수
    std::cout << "Hello, C++!" << std::endl;
    // std란? : C++ 표준 라이브러리의 모든 기능이 정의된 네임스페이스(namespace)으로 그 안에 있는 기능을 사용하기 위해서는 std::를 붙여야 한다.
    // std::cout : 화면 출력 기능을 제공하는 객체
    // 객체란? : 변수와 비슷하지만, 변수는 데이터를 저장하는 반면, 객체는 데이터와 그 데이터를 처리하는 기능(함수)을 함께 가지고 있는 것
    return 0;
}

// std라는 기능을 항상 사용하는 것이 귀찮다면
// using namespace std; --> 이렇게 선언하면 std::를 생략하고 cout, cin 등을 사용할 수 있다.