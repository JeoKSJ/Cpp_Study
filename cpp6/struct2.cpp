#include <string>
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    // 구조체를 배열로 선언하고 초기화할 수 있습니다.
    Person p[3] = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    for (int i = 0; i < 3; i++) {
        cout << p[i].name << ", " << p[i].age << endl;
    }
    return 0;
}

/*
Alice, 30
Bob, 25
Charlie, 35
*/