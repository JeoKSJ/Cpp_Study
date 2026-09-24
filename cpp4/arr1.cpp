#include <iostream>

int main() {
    int scores[5] = {90, 85, 60, 75, 100};
    std::cout << scores[0] << std::endl; // Output: 90
    std::cout << scores[1] << std::endl; // Output: 85

    int arr[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << " "; // Output: 10 20 30
    }
    return 0;
}

// 90
// 85
// 10 20 30 