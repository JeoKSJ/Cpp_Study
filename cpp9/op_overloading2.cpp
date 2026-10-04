#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
public:
    int x; int y;
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const { // bool 비교 연산자
        return x == other.x && y == other.y;
    }
};

int main() {
    Point a(1, 2), b(1, 2);
    if (a == b) cout << "같은 점" << endl;
    return 0;
}