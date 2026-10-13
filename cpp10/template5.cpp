// 과제 풀이
// 함수 템플릿의 min0f와 sum0f를 만들어서,
// int double string으로 각자 호출해보기.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
T min0f(T a, T b) {
    return (a > b) ? b : a; 
}
template <typename F>
F sum0f(F a, F b) {
    return a + b;
}

int main() {
    cout << min0f(3, 7) << endl;
    cout << sum0f<double>(2, 4.4) << endl;
    cout << sum0f<string>("3","은 숫자") << endl;
    return 0;
}

/*
3
6.4
3은 숫자
*/