## 1. STL이란?

**STL(Standard Template Library)**은 C++ 표준 라이브러리 중 **템플릿으로 만든 자료구조와 알고리즘 모음**이에요. 크게 세 부분입니다.

| 구성 | 역할 | 예 |
|---|---|---|
| **컨테이너** | 데이터를 담는 그릇 | `vector`, `map`, `set` |
| **반복자(iterator)** | 컨테이너를 훑는 포인터 비슷한 도구 | `v.begin()` |
| **알고리즘** | 정렬, 검색 등 | `sort`, `find` |

오늘은 컨테이너 중심으로, 반복자와 알고리즘은 맛보기만 합니다. 앞서 "반복자 때 `++`가 쓰인다"고 했던 그 약속도 여기서 회수돼요.

## 2. 어떤 컨테이너를 쓸까 (한눈에)

| 컨테이너 | 한 줄 설명 | 파이썬 대응 |
|---|---|---|
| `vector` | 크기 가변 배열 (11강 전 보충에서 배움) | `list` |
| `string` | 문자열 | `str` |
| `map` | **키 → 값** 쌍, 키 기준 정렬 | `dict` (정렬된) |
| `unordered_map` | 키 → 값, 정렬 없이 **더 빠름** | `dict` |
| `set` | **중복 없는** 값 모음, 정렬됨 | `set` (정렬된) |
| `unordered_set` | 중복 없는 값, 정렬 없음 | `set` |
| `pair` | 값 두 개 묶음 | 튜플 `(a, b)` |
| `stack`, `queue` | 후입선출 / 선입선출 | 리스트로 흉내 |

**고민되면 기본은 `vector`**, 키로 찾는 용도면 `map`/`unordered_map`, 중복 제거면 `set`입니다.

## 3. pair: 값 두 개 묶기

`map`을 이해하려면 먼저 필요해요.

```cpp
#include <utility>
#include <string>

std::pair<std::string, int> p("철수", 25);

std::cout << p.first << std::endl;    // 철수
std::cout << p.second << std::endl;   // 25
```

`first`, `second`로 접근합니다. 10강의 `Pair<T>` 실습과 같은 발상이고, 다른 타입 두 개를 묶을 수 있다는 점이 다릅니다.

## 4. map: 키로 값을 찾는 사전

```cpp
#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, int> score;    // 키: 문자열, 값: 정수

    score["철수"] = 90;        // 추가
    score["영희"] = 85;
    score["민수"] = 70;

    std::cout << score["영희"] << std::endl;   // 85 (키로 값 조회)

    score["영희"] = 95;                        // 같은 키에 대입 → 값 수정
    std::cout << score.size() << std::endl;    // 3 (원소 개수)
    return 0;
}
```

- `map<키타입, 값타입>`: 템플릿 인자가 **두 개**예요 (10강의 `template <typename A, typename B>`)
- 같은 키는 **하나만** 존재하고, 대입하면 덮어씁니다
- 내부적으로 **키 순서대로 정렬**되어 저장돼요 (문자열이면 사전순)

### ⚠️ `[]`의 함정

```cpp
std::cout << score["없는사람"] << std::endl;   // 0 출력 (!)
std::cout << score.size() << std::endl;        // 4 (없던 키가 생겨버림)
```

`[]`는 **없는 키를 조회하면 새로 만들어버립니다**(값은 0 같은 기본값). 존재 확인은 `[]`가 아니라 아래 방법을 쓰세요.

```cpp
if (score.count("철수") > 0) { ... }      // 있으면 1, 없으면 0
if (score.find("철수") != score.end()) { ... }   // find는 반복자 반환 (5번에서 설명)
```

범위 검사가 있는 조회는 `score.at("철수")`이고, 없으면 예외가 나요(다음 14강).

## 5. 반복자(iterator) 맛보기

`find`가 돌려주는 건 **원소 위치를 가리키는 반복자**예요. 포인터와 비슷하게 `*`로 값을 꺼내고 `++`로 다음 칸으로 갑니다. 이게 9강에서 "반복자 때 `++`를 쓴다"고 한 그 장면입니다.

```cpp
auto it = score.find("철수");

if (it != score.end()) {                 // end()는 "마지막 다음" 위치 = 못 찾음을 의미
    std::cout << it->first << ": " << it->second << std::endl;   // 철수: 90
}
```

- `auto`: 타입을 컴파일러가 **알아서 추정**해주는 키워드예요. 반복자 타입 이름은 아주 길어서 `auto`를 많이 씁니다
- `it->first`, `it->second`: 반복자도 포인터처럼 `->`로 멤버에 접근해요 (8강의 `->`와 같은 모양)
- `end()`는 마지막 원소가 아니라 **그 다음 자리**라서, `it == end()`면 못 찾은 겁니다

## 6. map 순회하기

```cpp
// 범위 기반 for (가장 편함)
for (const auto& kv : score) {
    std::cout << kv.first << ": " << kv.second << std::endl;
}
// 민수: 70
// 영희: 95
// 철수: 90      ← 키(사전순) 정렬 순서

// C++17 구조적 바인딩 (더 읽기 쉬움)
for (const auto& [name, point] : score) {
    std::cout << name << ": " << point << std::endl;
}
```

원소가 `pair`라서 `kv.first`가 키, `kv.second`가 값입니다. `const auto&`는 "복사하지 않고 읽기만"(3강, vector 때 본 `const &`)이에요. 구조적 바인딩 `[name, point]`은 `first`, `second`에 이름을 붙여 읽기 편하게 해주는 문법이고, `-std=c++17`이 필요합니다(12강 Makefile에 이미 있죠).

## 7. map의 삭제와 기타

```cpp
score.erase("철수");          // 키로 삭제
score.clear();                // 전부 삭제
score.empty();                // 비었는지
score.insert({"지수", 88});   // 삽입 (이미 있는 키면 무시됨)
```

`[]` 대입은 "있으면 수정, 없으면 추가"이고, `insert`는 "있으면 무시"라는 차이가 있어요.

## 8. unordered_map: 정렬 대신 속도

```cpp
#include <unordered_map>

std::unordered_map<std::string, int> m;
m["a"] = 1;     // 사용법은 map과 똑같음
```

| | `map` | `unordered_map` |
|---|---|---|
| 정렬 | **키 순서대로** | 순서 없음 |
| 조회 속도 | 느림(원소 수의 로그에 비례) | **빠름**(보통 상수 시간) |
| 용도 | 정렬된 출력이 필요할 때 | **순서 무관, 속도 중시** |

사용법은 똑같아서, **정렬이 필요 없으면 `unordered_map`**을 쓰는 경우가 많아요. 파이썬의 `dict`와 느낌이 가장 비슷한 것도 이쪽입니다.

## 9. set: 중복 없는 모음

```cpp
#include <set>

std::set<int> s = {5, 1, 3, 3, 1};    // 중복 제거 + 정렬

for (int n : s) std::cout << n << " ";   // 1 3 5

s.insert(4);                // 추가
s.erase(1);                 // 삭제
std::cout << s.count(3);    // 1 (있음) / 0 (없음)
std::cout << s.size();      // 3
```

- 같은 값을 여러 번 넣어도 **하나만** 저장됩니다
- 자동으로 **오름차순 정렬**돼요 (정렬 필요 없으면 `unordered_set`)
- "이미 본 값인가?"를 확인하는 용도로 아주 유용합니다

```cpp
// 중복 제거 예: vector → set → vector
std::vector<int> v = {3, 1, 3, 2, 1};
std::set<int> unique(v.begin(), v.end());   // 구간으로 set 생성
// unique: 1 2 3
```

## 10. stack과 queue

```cpp
#include <stack>
#include <queue>

std::stack<int> st;      // 후입선출(LIFO): 쌓았다가 위에서부터 꺼냄
st.push(1); st.push(2); st.push(3);
std::cout << st.top();   // 3 (맨 위 확인)
st.pop();                // 3 제거 (pop은 값을 돌려주지 않음!)

std::queue<int> q;       // 선입선출(FIFO): 줄 서기
q.push(1); q.push(2); q.push(3);
std::cout << q.front();  // 1 (맨 앞 확인)
q.pop();                 // 1 제거
```

`pop()`은 **제거만 하고 값을 돌려주지 않아요**. 값을 쓰려면 `top()`/`front()`로 먼저 읽고 `pop()`하세요.

## 11. 알고리즘 맛보기: sort와 find

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 2, 8, 1};

std::sort(v.begin(), v.end());             // 오름차순: 1 2 5 8
std::sort(v.begin(), v.end(), std::greater<int>());   // 내림차순: 8 5 2 1

auto it = std::find(v.begin(), v.end(), 5);   // 값 5 찾기
if (it != v.end()) std::cout << "있음";
```

- `begin()`, `end()`로 **구간**을 넘기는 게 STL 알고리즘의 공통 방식이에요
- 직접 만든 클래스를 `sort`하려면 **`operator<`**가 필요합니다. 9강에서 "`<`는 정렬에 필요해서 만든다"고 한 게 바로 이 장면이에요

## 12. 컨테이너 선택 가이드

| 하고 싶은 일 | 선택 |
|---|---|
| 그냥 목록, 인덱스 접근 | `vector` |
| 이름으로 값 찾기 (순서 상관 없음) | `unordered_map` |
| 이름으로 값 찾기 + **정렬 출력** | `map` |
| 중복 제거 / 포함 여부 확인 | `set` / `unordered_set` |
| 되돌리기(undo), 괄호 검사 | `stack` |
| 대기열, 순서대로 처리 | `queue` |

---

## 📌 오늘의 요약

1. STL은 템플릿으로 만든 **컨테이너 + 반복자 + 알고리즘** 모음이다.
2. `map<키, 값>`은 키로 값을 찾는 사전이며 **키 순서대로 정렬**된다. `unordered_map`은 정렬 없이 더 빠르다.
3. `map`의 `[]`는 **없는 키를 조회해도 새로 만들어버리므로**, 존재 확인은 `count`나 `find`를 쓴다.
4. `find`는 **반복자**를 돌려주고, `end()`와 같으면 못 찾은 것이다. 반복자는 `*`, `->`, `++`를 포인터처럼 쓴다.
5. `set`은 **중복 없이 정렬된** 값 모음이고, `stack`(LIFO)과 `queue`(FIFO)는 `pop()`이 값을 돌려주지 않는다.
6. `sort`, `find` 같은 알고리즘은 `begin()`/`end()` 구간을 넘겨서 쓰고, 직접 만든 클래스는 `operator<` 등이 필요하다.
7. 컨테이너가 헷갈리면 **기본은 `vector`**, 키 검색은 `(unordered_)map`, 중복 제거는 `set`.

---