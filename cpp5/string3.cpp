#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "Hello";

    for (int i = 0; i < word.length(); i++) {
        cout << word[i] << " ";  // H e l l o
    }

    // 범위 기반 for문(range-based for)
    for (char c : word) {   // for 타입 변수 이름 : 컨테이너(문자열을 담고있는 변수 이름)
        cout << c << " ";        // H e l l o
    } // word 문자열 내에 인덱스 없이 문자 하나하나를 c에 대입하고 출력

    int scores[5] = {100, 90, 96, 78, 84};
    for (int score : scores) {
        cout << score << " ";
    }

    return 0;
}
// H e l l o H e l l o 100 90 96 78 84