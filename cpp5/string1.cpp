#include <iostream>
#include <string>
using namespace std;

int main() {
    char name[6] = "Kim"; // 실제로는 'K','i','m','\0','\0','\0' 순으로 저장됨
    cout << name << endl;

    string name_s = "Kim";      // 문자열 선언
    string greeting = "안녕, " + name_s;    // 문자열 합침으로 편리
    cout << greeting << endl;   // 안녕, Kim

    return 0;
}