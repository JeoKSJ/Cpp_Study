// 선언부
#pragma once
// include guard로 헤더가 두 번 이상 포함되면 같은 클래스나 함수에서 에러가 나기에
// 해당 방식을 막기 위해서 헤더는 한 번만 포함하라는 뜻을 가지고 있음.

// #pragma once는 간단한 방식으로 컴파일러가 대부분 지원
// 예전 방식은 #ifndef POINT_H, #define POINT_H --- #endif 와 같은 매크로 방식을 사용한다.

int add(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);