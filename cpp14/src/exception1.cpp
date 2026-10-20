#include <iostream>
#include <stdexcept>
using namespace std;

// 파이썬의 try ~ excpet 와 똑같은 형태
// 예외처리: 에러 발생 시 현재 흐름 중단 및 처리단계로 진행

double divide(int a, int b){
    if(b == 0){
        throw runtime_error("0으로는 나눗셈을 할 수 없습니다.");
    }
    return static_cast<double>(a) / b;
}

int main() {
    try{
        cout << divide(10, 2) << endl;
        cout << divide(10, 0) << endl;
        cout << "실행되지 않는 줄" << endl;
    } catch(const runtime_error& e){    // 던져진 예외(const runtime_error& e)를 받아서 처리
        cout << "에러 발생: " << e.what() << endl;  // 예외에 담긴 메세지 문자열을 돌려준다.
    }

    cout << "프로그램 계속 진행" << endl;
    return 0;
}

/*
5
에러 발생: 0으로는 나눗셈을 할 수 없습니다.
프로그램 계속 진행
*/