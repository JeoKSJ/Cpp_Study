#include <iostream>
#include <string>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point operator-(const Point& other) const{
        return Point(x - other.x, y - other.y);
    }

    Point operator+(const Point& other) const{
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const{
        return(x == other.x && y == other.y);
    }

    Point operator*(int n) const{   // a * 3
        return Point(x * n, y * n);
    }

    Point& operator++(){         // 전위: ++a
        x++;
        y++;
        return *this;           // 올린 뒤에 자기 자신을 반환
    }

    Point operator++(int){      // 후위: a++
        Point old = *this;
        x++;
        y++;
        return old;             // 올리기 전의 자기 자신을 반환
    }
};

Point operator*(int n, const Point& p){ // 3 * a
    return Point(p.x * n, p.y * n);
}

ostream& operator<<(ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point a(5, 7);
    Point b(2, 3);
    Point c(7, 3);

    cout << (a + b) << endl;  // (7, 10)
    cout << (a - b) << endl;  // (3, 4)
    cout << a * 3 << endl;    // (15, 21)
    cout << 3 * a << endl;    // (15, 21)
    cout << (++a) << endl;
    cout << (a++) << endl;
    cout << a << endl;
    
    if(a == c) cout << "같은 점" << endl;
    if(!(a == c)) cout << "다른 점" << endl;

    return 0;
}

/*
(7, 10)
(3, 4)
(15, 21)
(15, 21)
(6, 8)
(6, 8)
(7, 9)
다른 점
*/