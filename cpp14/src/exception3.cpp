#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    try {
        vector<int> v = {1, 2, 3};
        cout << v.at(10);          // out_of_range 발생
    } catch (const out_of_range& e) {
        cout << "범위 오류: " << e.what() << endl;  // 여기서 catch를 받고 실행
    } catch (const exception& e) {
        cout << "기타 오류: " << e.what() << endl;  // 앞에서 예외를 받았으니 여긴 진행 x
    }
}

// 범위 오류: vector::_M_range_check: __n (which is 10) >= this->size() (which is 3)