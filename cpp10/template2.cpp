#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 그러면 컴파일러가 하는 행동 -> 템플릿의 진짜 타입으로 변환해 함수를 만든다.
// maxOf(3, 7)      →  컴파일러가 int maxOf(int, int)를 생성
// maxOf(2.5, 1.2)  →  컴파일러가 double maxOf(double, double)를 생성

// 서로 타입이 안맞으면 maxOf(3, 6.4) 이런식일 때 에러가 난다.
// 해결 방법은 두가지
template <typename T>
T maxOf(T a, T b){
    return (a > b) ? a : b;
}

// 해결방법 2: 템플릿 안의 연산을 선언해준다.
// 필요한 연산을 Point 클래스로 선언해주어 타입을 받을 수 있게 해준다.
class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    bool operator>(const Point& other) const{
        return x > other.x && y > other.y;
    }
};

ostream& operator<<(ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point a(4, 5), b(3, 4);
    cout << maxOf<double>(3, 2.5) << endl;  // 해결방법 1: double로 선언할 경우 maxOf(3.0, 2.5) 으로 사용됨.
    cout << maxOf(a, b) << endl;
    return 0;
}

/*
3                                                                                                                                                                                                                                                                                                    
(4, 5)   
*/