#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// RAII: Resource Acquisition Is Initialization
// 설계 원칙으로 생성자에서 자원 얻고 -> 소멸자의 자원 반납 후 -> 객체가 사라지면 자원도 자동으로 정리되는 방식
// 스마트 포인터: 포인터를 들고 있다가, 자기가 사라질 때 delete 를 대신 호출해주는 객체

int main() {
    auto p = make_unique<int>(10);  // new int(10)과 같지만 delete 불필요
    cout << *p << endl;             // 10 (일반 포인터처럼 * 사용)
    /*
    auto a = make_unique<Dog>("초코");
    a->makeSound;                   // 앞에서 배운 형식도 이렇게 포인터처럼 사용이 가능함.
    */
    // 대신 저렇게 만든 형식은 복사 금지다.
    auto a = make_unique<int>(5);
    // auto b = a;
    auto b = std::move(a);
    // 이렇게 하면 b에게 소유권을 넘기게 됨.(이동이 아니라)

    // ===========================================================
    // 공유 포인터(shared_ptr)
    auto c = make_shared<int>(10);
    auto d = c; // 복사 가능! 같은 내용을 가리킴
    cout << c.use_count() << endl;  // 소유자 수: 2

    d.reset();  // 복사권 상실
    cout << c.use_count() << endl;  // 소유자 수: 1
}

/* 함수에 넘기는 경우
void use(const Dog& d) { }        // 소유권이 필요 없으면: 참조로 받기 (권장)
use(*a);                          // *a는 가리키는 객체 자체

void take(unique_ptr<Dog> d) { }  // 소유권을 넘길 때만 unique_ptr 사용
take(std::move(a));
*/