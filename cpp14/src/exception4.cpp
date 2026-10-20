#include <iostream>
#include <stdexcept>
using namespace std;

class NegativeAgeError : public runtime_error {
public:
    NegativeAgeError(int age) : runtime_error("나이는 음수일 수 없습니다: " + to_string(age)) {}
};

void setAge(int age){
    if (age < 0) throw NegativeAgeError(age);
}

int main() {
    int age = 0;
    try{
        cout << "나이를 입력하세요: ";
        cin >> age;
        setAge(age);
        cout << "나이 확인: " << age << endl;
    }
    catch (const NegativeAgeError& e) {cout << e.what();}
}

/*
[제대로 입력 시]
나이를 입력하세요: 5
나이 확인: 5

[오류로 입력 시]
나이를 입력하세요: -5
나이는 음수일 수 없습니다: -5
*/