#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printAll(const vector<int>& v);
void addOne(vector<int>& v);

// Vector에 대해서

int main() {
    vector<int> a; // 빈 vector 생성
    vector<int> b = {1, 2, 3, 4, 5}; // 초기값을 가진 vector 생성
    vector<int> c(5); // 크기가 5인 vector 생성, 초기값은 0
    vector<int> d(5, 10); // 크기가 5인 vector 생성, 초기값은 10 -> [10, 10, 10, 10, 10]
    vector<string> names = {"Alice", "Bob", "Charlie"}; // 문자열 vector 생성

    // vector에 요소 추가
    a.push_back(1); // [1]
    a.push_back(2); // [1, 2]

    // vector의 크기 확인
    cout << "Size of a: " << a.size() << endl; // 2

    // vector의 요소 접근
    cout << "b의 첫번째 요소: " << b[0] << endl; // 1
    cout << "b의 두번째 요소(at 함수 사용): " << b.at(1) << endl; // 2
    cout << "b의 첫번째 요소(front 함수 사용): " << b.front() << endl; // 1
    cout << "b의 마지막 요소(back 함수 사용): " << b.back() << endl; // 5

    // =========================================================================

    // vector 특정 요소 제거
    b.pop_back(); // 마지막 요소 제거, b는 [1, 2, 3, 4]가 됨
    cout << "b의 마지막 요소 제거 후: " << b.back() << endl; // 4
    b.clear(); // 모든 요소 제거, b는 빈 vector가 됨
    b.assign({10, 20, 30}); // 새로운 값으로 vector 재할당, b는 [10, 20, 30]이 됨
    cout << "b의 첫번째 요소 재할당 후: " << b.front() << endl; // 10

    // =========================================================================

    // vector 순회하기
    cout << "c의 요소들: ";
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " "; // 0 0 0 0 0
    }
    cout << endl;

    // range-based for loop 사용
    cout << "d의 요소들(range-based for loop): ";
    for (int n : d) {
        cout << n << " "; // 10 10 10 10 10
    }
    cout << endl;
    
    // range-based for loop를 사용해 vector 요소 변경
    cout << "d의 요소 변경(range-based for loop로 변경. +5): ";
    for (int &n : d) {
        n += 5; // 각 요소에 5를 더함
        cout << n << " "; // 15 15 15 15 15
    }
    cout << endl;

    // =========================================================================

    // vector 중간에 넣고 빼기
    vector<int> v = {1,2,3,4,5};
    v.insert(v.begin() + 1, 10); // 두번째 위치에 10 삽입, v는 [1, 10, 2, 3, 4, 5]가 됨
    cout << "v의 두번째 위치에 10 삽입 후: ";
    for (int n : v) {
        cout << n << " "; // 1 10 2 3 4 5
    }
    cout << endl;
    
    v.erase(v.begin() + 2); // 세번째 위치의 요소 제거, v는 [1, 10, 3, 4, 5]가 됨
    cout << "v의 세번째 위치 요소 제거 후: ";
    for (int n : v) {
        cout << n << " "; // 1 10 3 4 5
    }
    cout << endl;

    // =========================================================================

    // 함수에 vector 넘기기
    cout << "v의 모든 요소 출력: ";
    printAll(v); // v의 모든 요소 출력
    addOne(v); // v에 1 추가
    cout << "\nv에 1 추가 후: ";
    printAll(v); // v의 모든 요소 출력
    cout << endl;
}
    // =========================================================================

    // 함수에 넘기기

    void printAll(const vector<int>& v) {   // 읽기만 → const 참조
        for (int n : v) cout << n << " ";
    }

    void addOne(vector<int>& v) {           // 수정 → 참조
        v.push_back(1);
    }


/*
Size of a: 2
b의 첫번째 요소: 1
b의 두번째 요소(at 함수 사용): 2
b의 첫번째 요소(front 함수 사용): 1
b의 마지막 요소(back 함수 사용): 5
b의 마지막 요소 제거 후: 4
b의 첫번째 요소 재할당 후: 10
c의 요소들: 0 0 0 0 0 
d의 요소들(range-based for loop): 10 10 10 10 10 
d의 요소 변경(range-based for loop로 변경. +5): 15 15 15 15 15 
v의 두번째 위치에 10 삽입 후: 1 10 2 3 4 5 
v의 세번째 위치 요소 제거 후: 1 10 3 4 5 
v의 모든 요소 출력: 1 10 3 4 5 
v에 1 추가 후: 1 10 3 4 5 1 
*/