#include <iostream>
#include <stdexcept>
using namespace std;

// 예외가 전달되는 흐름: catch로 던져진 곳까지 이어져감.
// c에서 던지면 b, a를 건너뛰고 main의 catch로 올라가게 됨.
// 던져진 곳 이외의 곳에는 건너뛰고 프로그램을 강제종료하는게 장점.
void d() {cout << "여긴 안거침" << endl;}
void c() {throw runtime_error("C에서 에러"); cout << "C거침" << endl; d();}
void b() {cout << "B거침" << endl; c();}
void a() {cout << "A거침" << endl; b();}

int main() {
    try{a();}
    catch (const exception& e) {cout << e.what();}
    return 0;
}
/*
A거침
B거침
C에서 에러
*/