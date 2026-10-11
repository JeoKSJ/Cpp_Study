#include <iostream>
#include <string>
using namespace std;

// 템플릿이란?
// 타입을 빈칸으로 두고 틀만 만들어두는 기능
template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}
// typename T : 타입이 들어갈 빈칸은 T 로 설정
// maxOf(a, b): 컴파일러가 인자를 보고 그 자리를 자동 생성해줌. int, double, string 등등

int main() {
    cout << maxOf(3, 7) << endl;
    cout << maxOf(2.5, 1.5) << endl;
    cout << maxOf<string>("abc", "xyz") << endl;
}

/*
7                                                                                                                                                                                                                                                                                                    
2.5                                                                                                                                                                                                                                                                                                  
xyz
*/