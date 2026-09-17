#include <iostream>

int main() {
    int age = 20;
    bool hasLicense = true;

    if (age >= 18 && hasLicense) {
        std::cout << "You are eligible to drive." << std::endl;
    } else {
        std::cout << "You are not eligible to drive." << std::endl;
    }
    return 0;
}

// && : AND 연산자
// || : OR 연산자
// ! : NOT 연산자
// You are eligible to drive.