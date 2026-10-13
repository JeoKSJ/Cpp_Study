#pragma once
#include <string>
// using namespace std; -- 사용 금지
// 헤더 파일의 선언 내용이 전체에 퍼지기에 모든 파일에 영향이 감.
// 고로 헤더파일은 귀찮더라도 명시를 하고 .cpp에서 없애는 쪽으로 생각하기.

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age);
    void introduce() const;
    int getAge() const;
};