#include <vector>
#include <iostream>
#include <string>

// Vector 형식으로 배열을 함수에 전달할 수도 있습니다.
// std::vector는 크기를 자동으로 관리하므로, 별도로 크기를 전달할 필요가 없습니다.
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    nums.push_back(4); // 벡터에 요소 추가
    std::cout << nums.size() << std::endl; // 벡터의 크기 출력: 4

    for (int n : nums) {
        std::cout << n << " "; // 벡터의 요소 출력: 1 2 3 4
    }
    std::cout << std::endl;
    return 0;
}

/*
4
1 2 3 4 
*/