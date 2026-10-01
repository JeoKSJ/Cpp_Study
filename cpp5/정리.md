## 1. C++ 문자열, 두 가지 방식

C++에는 문자열을 다루는 방법이 두 가지 있습니다. C에서 물려받은 **C-스타일 문자열**과, 훨씬 다루기 편한 **`std::string`**입니다. 오늘은 왜 `std::string`을 주로 쓰는지 이해하는 게 목표입니다.

### C-스타일 문자열 (char 배열)

```cpp
char name[6] = "Kim";   // 실제로는 'K','i','m','\0','\0','\0' 순으로 저장됨
```

- 문자열은 사실 `char`의 배열이고, 끝에 **널 문자(`'\0'`)**가 붙어서 "여기서 문자열이 끝난다"는 걸 표시합니다.
- 크기를 다루거나 두 문자열을 합치는 게 번거롭고 실수하기 쉬워서, 요즘은 잘 안 씁니다. (다만 오래된 C 코드나 일부 라이브러리에서 여전히 등장하니 존재 정도는 알아두세요.)

### std::string (권장)

```cpp
#include <string>

std::string name = "Kim";
std::string greeting = "안녕, " + name;   // 문자열끼리 + 로 합치기 가능!

std::cout << greeting << std::endl;  // 안녕, Kim
```

`std::string`은 크기 걱정 없이 자동으로 관리되고, 다양한 기능(멤버 함수)을 제공합니다. 앞으로는 특별한 이유가 없으면 **항상 `std::string`을 쓰세요.**

## 2. std::string 주요 기능

```cpp
std::string s = "Hello, World!";

std::cout << s.length() << std::endl;     // 13 (문자열 길이)
std::cout << s.size() << std::endl;       // 13 (length()와 동일, 취향껏 사용)
std::cout << s[0] << std::endl;           // 'H' (인덱스로 문자 접근, 배열처럼)
std::cout << s.substr(7, 5) << std::endl; // "World" (7번 인덱스부터 5글자)
std::cout << s.find("World") << std::endl; // 7 (찾는 문자열의 시작 인덱스, 없으면 매우 큰 수 반환)

s += "!!";                                 // 뒤에 이어붙이기
std::cout << s << std::endl;               // "Hello, World!!!"

s.replace(0, 5, "Bye");                    // 0번부터 5글자를 "Bye"로 교체
std::cout << s << std::endl;               // "Bye, World!!!"
```

이 외에도 `s.empty()`(비어있는지 확인), `s.append()`(이어붙이기) 등 다양한 함수가 있는데, 필요할 때마다 검색해서 찾아 쓰는 정도로 충분합니다. 모든 함수를 외울 필요는 없어요.

## 3. 문자열 순회하기

`std::string`도 배열처럼 인덱스로 접근하거나, `for`문으로 순회할 수 있습니다.

```cpp
std::string word = "Hello";

for (int i = 0; i < word.length(); i++) {
    std::cout << word[i] << " ";
}
// 출력: H e l l o
```

**범위 기반 for문(range-based for)**을 쓰면 더 깔끔합니다.

```cpp
for (char c : word) {
    std::cout << c << " ";
}
// 출력: H e l l o (위와 동일한 결과, 인덱스 없이 문자 하나하나를 c에 대입)
```

`for (타입 변수이름 : 컨테이너)` 형태로, "컨테이너 안의 원소를 하나씩 꺼내서 변수에 담아 반복하라"는 뜻입니다. 배열에도 똑같이 쓸 수 있습니다.

```cpp
int scores[5] = {90, 85, 100, 70, 95};

for (int score : scores) {
    std::cout << score << " ";
}
```

## 4. 다차원 배열

배열 안에 배열을 넣으면 표(행렬) 형태의 데이터를 다룰 수 있습니다.

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

std::cout << matrix[0][2] << std::endl;  // 3 (0행 2열)
std::cout << matrix[1][0] << std::endl;  // 4 (1행 0열)
```

중첩 `for`문으로 전체를 순회합니다. (2강에서 배운 구구단 예제와 구조가 똑같습니다.)

```cpp
for (int i = 0; i < 2; i++) {        // 행
    for (int j = 0; j < 3; j++) {    // 열
        std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
}
// 1 2 3
// 4 5 6
```

## 5. 배열을 함수에 넘기기

배열을 함수에 넘기면, 4강에서 배운 대로 배열 이름이 사실상 포인터처럼 동작하기 때문에 **항상 참조처럼 전달**됩니다(원본이 그대로 넘어감).

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int nums[4] = {1, 2, 3, 4};
    printArray(nums, 4);   // 배열과 크기를 함께 넘김
    return 0;
}
```

⚠️ 배열은 함수 안에서 **자기 크기를 스스로 모릅니다** (포인터로 넘어가기 때문에). 그래서 크기를 별도 매개변수(`int size`)로 꼭 같이 넘겨줘야 합니다. 3강에서 배운 `& `참조와 달리, 배열은 `[]`를 써도 자동으로 원본이 넘어간다는 점이 특이합니다.

## 6. std::vector 살짝 맛보기

배열은 크기가 고정되어 있어서, 나중에 크기를 늘리거나 줄이고 싶으면 불편합니다. 이런 문제를 해결한 것이 **`std::vector`**입니다 (크기가 자유자재로 변하는 배열).

```cpp
#include <vector>

std::vector<int> nums = {1, 2, 3};
nums.push_back(4);            // 뒤에 원소 추가
std::cout << nums.size() << std::endl;  // 4

for (int n : nums) {
    std::cout << n << " ";
}
// 1 2 3 4
```

지금은 "이런 게 있구나" 정도만 알아두세요. 다음에 컨테이너를 본격적으로 다룰 때 자세히 짚고 넘어갈게요.

---

## 📌 오늘의 요약

1. C++에서는 `std::string`을 사용하는 것이 기본이며, C-스타일 문자열(`char` 배열 + `'\0'`)은 존재 정도만 알아두면 된다.
2. `std::string`은 `.length()`, `.substr()`, `.find()`, `+=` 등 유용한 기능을 제공하며, 필요할 때 찾아 쓰면 된다.
3. `for (타입 변수 : 컨테이너)` 형태의 **범위 기반 for문**은 인덱스 없이 원소를 순회할 때 편리하다.
4. 다차원 배열(`arr[행][열]`)은 중첩 반복문으로 순회한다.
5. 배열을 함수에 넘기면 포인터처럼 동작해 원본이 그대로 전달되며, 크기 정보는 따로 넘겨줘야 한다.
6. 크기가 가변적인 배열이 필요하면 `std::vector`를 사용하며, 자세한 내용은 추후 다룬다.

---