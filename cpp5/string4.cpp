#include <iostream>
#include <string>


// 배열을 함수에 넘기기
// 배열을 함수에 넘길 때는 배열의 이름만 전달하면 됩니다.
// 배열의 이름은 배열의 첫 번째 요소의 주소를 나타내므로, 함수에서는 배열의 크기를 별도로 전달해야 합니다.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 다른 방법: std::vector를 사용하여 배열을 함수에 전달할 수도 있습니다. 
// std::vector는 크기를 자동으로 관리하므로, 별도로 크기를 전달할 필요가 없습니다.
#include <vector>
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int size_of_arr = sizeof(arr); // 배열 전체 크기
    int size_of_first_element = sizeof(arr[0]); // 배열의 첫 번째 요소의 크기
    // sizeof: 배열의 전체 크기를 바이트 단위로 반환
    // sizeof(arr): 배열 전체 크기
    // sizeof(arr[0]): 배열의 첫 번째 요소의 크기
    std::cout << "Array size: " << size << std::endl;
    std::cout << "Size of array in bytes: " << size_of_arr << std::endl;
    std::cout << "Size of first element in bytes: " << size_of_first_element << std::endl;
    
    // 배열을 함수에 전달
    // 1. 배열을 함수에 전달할 때는 배열의 이름만 전달하면 됩니다.
    printArray(arr, size);
    // 2. std::vector를 사용하여 배열을 함수에 전달할 수도 있습니다.
    std::vector<int> vec(arr, arr + size);
    printVector(vec);

    return 0;
}

/*
Array size: 5
Size of array in bytes: 20
Size of first element in bytes: 4
1 2 3 4 5 
1 2 3 4 5 
*/