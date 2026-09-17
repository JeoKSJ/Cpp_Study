#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3; // 정수형 변수 a와 b를 선언하고 초기화

    cout << "a + b = " << a + b << endl; // 덧셈 연산
    cout << "a - b = " << a - b << endl; // 뺄셈 연산
    cout << "a * b = " << a * b << endl; // 곱셈 연산
    cout << "a / b = " << a / b << endl; // 나눗셈 연산 (정수 나눗셈)
    cout << "a % b = " << a % b << endl; // 나머지 연산 (정수 나눗셈의 나머지)
    return 0;
}

// a + b = 13
// a - b = 7
// a * b = 30
// a / b = 3
// a % b = 1
// 주의점 : 나눗셈에 int / int 연산은 정수 나눗셈이므로 소수점 이하가 버려진다.
// 10 / 3 = 3.3333... 이지만, int / int 연산에서는 3만 출력된다.
// 만약 double / int 연산을 수행하면, 결과는 double형으로 출력된다. (예: 10.0 / 3 = 3.3333...)
// --> double result = <double>a / b; 는 3.3333...을 출력한다.
// 추가적으로 값이 바뀌면 안 되는 데이터는 const 키워드를 사용하여 상수로 선언할 수 있다.
// --> const double PI = 3.14159; 상수 PI를 선언하고 초기화하며, 이후 PI의 값은 변경할 수 없다.
