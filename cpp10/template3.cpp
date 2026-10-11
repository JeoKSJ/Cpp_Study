#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 타입 매개변수 여러개 한번에 선언
template <typename A, typename B>
void printPair(A name, B count){
    cout << name << ": " << count << "개" << endl;
}

int main() {
    printPair("사과","100");
    printPair("배","50");
}

/*
사과: 100개                                                                                                                                                                                                                                                                                          
배: 50개     
*/