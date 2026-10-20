#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// 스택 되감기
class Guard {
public:
    Guard() {cout << "자원 획득" << endl;}  // 생성자
    ~Guard() {cout << "자원 정리" << endl;} // 소멸자
};

void work() {
    Guard g;
    throw runtime_error("문제 발생");   // 강제 에러 발생.
}

int main() {
    try{
        work(); // 자원 획득 -> runtime_error -X-> 자원 정리
    } catch (const runtime_error& r){
        cout << "에러: " << r.what() << endl;
    }
    return 0;
}

/*
자원 획득
자원 정리
에러: 문제 발생
*/