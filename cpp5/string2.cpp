#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello, World!";

    cout << s.length() << endl;         // 13 (문자열 길이)
    cout << s.size() << endl;           // 13 (문자열 길이 = 사이즈)
    cout << s[0] << endl;               // H (문자열의 첫번째 내용)
    cout << s.substr(7, 5) << endl;     // World (문자열 7번째 부터 5개의 내용)
    cout << s.find("World") << endl;    // 7 (World 글자의 시작 위치)

    s += "!!";
    cout << s << endl;                  // Hello, World!!! (문자열 + 문자열)

    s.replace(0, 5, "Bye");
    cout << s << endl;                  // Bye, World!!! (문자열 0~5까지의 내용을 Bye로 치환)
    return 0;
}

// 13
// 13
// H
// World
// 7
// Hello, World!!!
// Bye, World!!!