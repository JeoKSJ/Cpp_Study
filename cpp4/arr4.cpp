#include <iostream>

int main() {
    int x = 10;
    int* ptr = &x;

    *ptr = 20;
    std::cout << x << std::endl;    // 20
    return 0;
}