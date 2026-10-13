#include "add.h"
#include <iostream>

int main() {
    std::cout << add(6, 6) << std::endl;    // 12
    return 0;
}

/*
/cpp_study/cpp12$ make
g++ -c main.cpp -o main.o
g++ -c define/add.cpp -o add.o
g++ main.o add.o -o myprogram
/cpp_study/cpp12$ ./myprogram
12
*/