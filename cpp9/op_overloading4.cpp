#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 출력 연산자 <<
// 파이썬의 __str__과 같이 객체를 바로 출력하기 위해서 사용.
class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

ostream& operator<<(ostream& os, const Point& p){   // ostream& os: 앞의 cout(cpp 표준 라이브러리)를 참조로 진짜 받음 | const Point& p: 두번째 매개변수로 출력할 Point 객체를 읽기 전용 참조로 받음
    os << "(" << p.x << ", " << p.y << ")";
    return os;  // 반환 타입: ostream& (돌려주는 내용이 cout)
}

int main() {
    Point a(1, 2);
    cout << a << endl;
    // os를 돌려주는 이유를 결과로 알아보자
    // cout << a << endl; == (std::cout << a) << std::endl;
    // 먼저 앞의 cout << a 가 실행되어 (1, 2)가 출력되고 그 값이 뒤의 endl로 이어진다.
    // 그렇게 하기 위해서는 1번 값이 cout가 되어야하는데 함수가 cout(=os)를 돌려준다.
    return 0;
}
