## 1. vector가 왜 필요한가

5강에서 배운 배열은 불편한 점이 있었어요.

```cpp
int scores[5] = {90, 85, 100, 70, 95};
```

- **크기가 고정**이라, 6번째 점수를 추가할 방법이 없다
- 함수에 넘기면 **자기 크기를 모르니** `size`를 따로 넘겨야 한다
- 범위를 벗어난 접근을 아무도 막아주지 않는다

**vector는 "크기가 자유롭게 늘고 주는 배열"**입니다. 자기 크기도 알고 있고, 메모리 관리도 알아서 해줘요. 그래서 C++에서는 특별한 이유가 없으면 **배열 대신 vector를 쓰는 게 기본**입니다.

## 2. 만들기

```cpp
#include <vector>   // 헤더 필요!

std::vector<int> a;                  // 빈 vector
std::vector<int> b = {10, 20, 30};   // 값을 넣고 시작
std::vector<int> c(5);               // 0으로 채워진 원소 5개: 0 0 0 0 0
std::vector<int> d(5, 7);            // 7로 채워진 원소 5개: 7 7 7 7 7
std::vector<std::string> names;      // 문자열 vector
```

`<int>`는 "이 vector는 int를 담는다"는 뜻이에요. `<>` 안에 타입을 넣으면 그 타입 전용 vector가 만들어집니다. (이게 10강에서 배울 **템플릿**의 맛보기예요.)

## 3. 자주 쓰는 기능

```cpp
std::vector<int> v = {10, 20, 30};

v.push_back(40);              // 맨 뒤에 추가 → 10 20 30 40
std::cout << v.size();        // 4 (원소 개수)
std::cout << v[0];            // 10 (배열처럼 인덱스 접근)
std::cout << v.at(1);         // 20 (인덱스 접근, 범위 검사 있음)
std::cout << v.front();       // 10 (첫 원소)
std::cout << v.back();        // 40 (마지막 원소)

v.pop_back();                 // 맨 뒤 제거 → 10 20 30
std::cout << v.empty();       // 0 (false, 비어있지 않음)
v.clear();                    // 전부 비우기
```

`v[i]`와 `v.at(i)`의 차이를 알아두세요.

- `v[5]` : 범위를 벗어나도 검사 안 함 → 위험한 동작(5강의 배열과 동일)
- `v.at(5)` : 범위를 벗어나면 **예외를 던져서** 에러를 알려줌 (예외는 12강에서 다뤄요)

## 4. 순회하기

```cpp
std::vector<int> v = {1, 2, 3, 4};

// ① 인덱스 방식
for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
}

// ② 범위 기반 for (5강에서 배운 것)
for (int n : v) {
    std::cout << n << " ";
}
```

범위 기반 for에서 하나 주의할 점이 있어요. `int n : v`는 원소를 **복사해서** n에 담기 때문에, n을 바꿔도 원본은 그대로입니다. 3강의 "값 전달 vs 참조 전달"과 같은 원리예요.

```cpp
for (int n : v)  { n = n * 2; }   // 복사본만 바뀜 → v는 그대로
for (int& n : v) { n = n * 2; }   // 참조 → 원본이 바뀜! (v: 2 4 6 8)
```

복사 비용이 큰 원소(예: 긴 문자열)를 읽기만 할 때는 `const std::string& s : names`처럼 쓰는 게 일반적이에요. 이것도 3강에서 나온 "const 참조"입니다.

## 5. 중간에 넣고 빼기

```cpp
std::vector<int> v = {10, 20, 30, 40};

v.insert(v.begin() + 1, 15);   // 1번 인덱스 자리에 15 삽입 → 10 15 20 30 40
v.erase(v.begin() + 2);        // 2번 인덱스 원소 삭제 → 10 15 30 40
```

`v.begin()`은 "첫 원소의 위치"를 나타내는 **반복자(iterator)**예요. 지금은 "`begin() + 인덱스`로 위치를 지정한다" 정도로만 쓰면 됩니다. 단, 중간 삽입/삭제는 뒤 원소들을 전부 밀거나 당겨야 해서 **느린 작업**이라는 점은 기억해두세요. 맨 뒤 추가/삭제(`push_back`, `pop_back`)가 가장 빠릅니다.

## 6. 함수에 넘기기 (3강 연결)

```cpp
void printAll(const std::vector<int>& v) {   // 읽기만 → const 참조
    for (int n : v) std::cout << n << " ";
}

void addOne(std::vector<int>& v) {           // 수정 → 참조
    v.push_back(1);
}
```

그냥 `std::vector<int> v`로 받으면 **전체가 복사**됩니다. 원소가 많으면 낭비라서, 읽기만 하면 `const &`, 수정할 거면 `&`로 받는 게 거의 습관이에요. 배열과 달리 `size`를 따로 안 넘겨도 되는 점이 편합니다.

## 7. 내부는 어떻게 생겼나 (살짝만)

vector는 내부적으로 **연속된 메모리에 원소를 저장**해요(배열과 같은 구조). 공간이 꽉 차면 **더 큰 공간을 새로 잡고, 기존 원소들을 옮긴 뒤, 옛 공간을 정리**합니다. 이 작업을 vector가 알아서 해주니까 우리가 `new`/`delete`를 신경 쓸 필요가 없는 거예요.

```cpp
std::vector<int> v;
std::cout << v.size() << " " << v.capacity();   // 0 0 (개수 / 미리 확보한 공간)
v.push_back(1);
std::cout << v.size() << " " << v.capacity();   // 1 1 (확보량은 구현마다 다름)
```

- `size()` : 지금 들어있는 원소 개수
- `capacity()` : 다시 확보하지 않고 담을 수 있는 최대 개수

원소를 많이 넣을 걸 미리 알면 `v.reserve(1000);`으로 공간을 미리 잡아두면 재할당이 줄어 빨라집니다. 이 정도는 "있다"만 알아두세요.

## 8. 앞서 나온 `vector<Animal*>` 다시 보기

8강의 이 코드가 이제 읽힐 거예요.

```cpp
std::vector<Animal*> animals;           // "Animal을 가리키는 주소"들을 담는 vector
animals.push_back(new Dog("초코"));     // Dog를 만들고 그 주소를 vector에 추가
animals.push_back(new Cat("나비"));

for (Animal* a : animals) {
    a->makeSound();                     // 각자 실제 타입에 맞게 동작
}
```

**vector가 담고 있는 건 객체가 아니라 객체의 주소**입니다. 왜 객체 자체(`vector<Animal>`)가 아니라 포인터일까요? `vector<Animal>`에 `Dog`를 넣으면 `Animal` 크기에 맞게 **잘려서 복사**되어 Dog의 정체가 사라지고, 다형성이 동작하지 않기 때문이에요. 포인터는 크기가 항상 같아서 어떤 자식이든 가리킬 수 있습니다.

단 이 경우 vector가 정리해주는 건 **주소들**뿐이고, `new`로 만든 객체는 우리가 `delete`해야 합니다. 이 번거로움을 해결하는 게 13강에서 배울 **스마트 포인터**예요.

## 9. 흔한 실수 3가지

```cpp
// ① 빈 vector에 [ ]로 값 넣기
std::vector<int> v;
v[0] = 5;            // 위험! 원소가 아직 없음 → push_back을 써야 함

// ② 중괄호와 소괄호의 차이
std::vector<int> a(3);    // 0 0 0         (원소 3개)
std::vector<int> b{3};    // 3             (값 3 하나)

// ③ size()는 부호 없는 정수라서 이런 반복문은 위험
for (int i = v.size() - 1; i >= 0; i--) { }   // 괜찮지만
// v가 비었을 때 size() - 1 을 unsigned로 계산하면 엄청 큰 수가 되는 함정 존재
```

①번이 가장 흔해요. **원소를 추가하는 건 `push_back`, 이미 있는 원소를 읽고 쓰는 건 `[ ]`**로 역할을 구분하면 됩니다.

---

## 📌 요약

1. `vector`는 **크기가 자유롭게 변하는 배열**이며, `#include <vector>`와 `std::vector<타입>`으로 쓴다.
2. 추가는 `push_back`, 개수는 `size()`, 접근은 `[ ]`(검사 없음) 또는 `at()`(검사 있음), 제거는 `pop_back`/`erase`/`clear`.
3. 순회는 `for (int n : v)`가 편하며, **원본을 바꾸려면 `int&`**, 읽기만 하는 큰 데이터는 **`const &`**로 받는다.
4. 함수에 넘길 때는 복사를 피하려고 `const vector<int>&`(읽기용) 또는 `vector<int>&`(수정용)를 쓴다.
5. 내부적으로 연속 메모리를 쓰며 공간이 부족하면 알아서 늘린다. 맨 뒤 추가/삭제는 빠르고, 중간 삽입/삭제는 느리다.
6. `vector<Animal*>`는 객체가 아니라 **주소를 담는** vector이며, `new`로 만든 객체의 `delete`는 직접 해야 한다.
7. 빈 vector에 `v[0] = ...`로 값을 넣지 말고 `push_back`을 쓴다.

---