#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int parseAge(const string& s){
    int num = stoi(s);
    if(num < 0 || num > 150){
        throw out_of_range("범위 오류 - " + to_string(num));
    }else{
        cout << "출력(범위: 0~150): " << num << endl;
    }
    return num;
}

int main() {
    vector<string> inputs = {"25", "Jeo", "200", "25abc", ""};
    // 특이하게도 25age와 "" 과 같은 문자열은 제대로 처리를 못한다.
    // 25age는 앞의 25의 숫자만 읽고 해당 내용을 가져온다. 빈 문자열은 문자열 오류를 내보내준다.
    // 엄격하게 검사를 하고싶다면 stoi(s, &pos)와 같이 어디까지 읽었는지도 확인해야한다.
    for(const string& s : inputs){
        try{
            parseAge(s);
        } catch (const invalid_argument& ia){
            cout << "에러: " << ia.what() << endl;
        } catch (const out_of_range& o){
            cout << "에러: " << o.what() << endl;
        }
    }
}

/*
출력(범위: 0~150): 25
에러: stoi
에러: 범위 오류 - 200
*/