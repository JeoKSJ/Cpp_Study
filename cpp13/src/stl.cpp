#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
    STL(Standard Template Library) 입문

    STL은 자주 사용하는 자료구조와 기능을 미리 만들어 둔 C++ 라이브러리입니다.
    처음에는 아래 세 가지가 어떻게 함께 쓰이는지 익히면 좋습니다.

      1. 컨테이너(container): 데이터를 저장하는 도구 (예: vector, set, map)
      2. 반복자(iterator): 컨테이너 안의 원소를 가리키는 도구
      3. 알고리즘(algorithm): 반복자를 이용해 데이터를 처리하는 함수 (예: sort, find)

    이 파일은 vector에 데이터를 담고, 반복자로 확인하고, 알고리즘으로 처리하는
    흐름을 먼저 보여줍니다. 마지막에는 set, stack, queue, pair, map도 살펴봅니다.
*/

int main() {
    // 1. vector: 크기가 자동으로 늘어나는 배열
    // <int>는 이 vector가 int 값들을 저장한다는 뜻입니다.
    vector<int> scores{80, 95, 70, 100};

    // push_back은 vector의 맨 뒤에 원소를 추가합니다.
    scores.push_back(85);

    cout << "[vector의 원소]\n";

    // 범위 기반 for문: 컨테이너의 원소를 처음부터 끝까지 하나씩 꺼냅니다.
    // 여기서 score는 scores 안의 원소를 복사한 값입니다.
    for (int score : scores) {
        cout << score << ' ';
    }
    cout << "\n";

    // size()는 현재 원소의 개수, empty()는 비어 있는지 알려줍니다.
    cout << "원소 개수: " << scores.size() << '\n';
    cout << "비어 있는가? " << boolalpha << scores.empty() << "\n\n";

    // =================================================================================
    // 2. 반복자(iterator)
    // =================================================================================
    // begin()은 첫 원소를, end()는 마지막 원소 바로 다음 위치를 가리킵니다.
    // end()는 원소가 아니므로 *scores.end()처럼 역참조하면 안 됩니다.
    cout << "[반복자로 순회]\n";
    for (vector<int>::const_iterator it = scores.cbegin();
         it != scores.cend(); ++it) {
        // 반복자가 가리키는 값을 읽을 때는 *를 붙입니다.
        cout << *it << ' ';
    }
    cout << "\n\n";

    // =================================================================================
    // 3. 알고리즘: sort
    // =================================================================================
    // <algorithm>에 정의된 sort는 두 반복자 사이의 원소를 오름차순으로 정렬합니다.
    // 정렬 결과는 원래 scores에 반영됩니다.
    sort(scores.begin(), scores.end());

    cout << "[오름차순 정렬]\n";
    for (const auto& score : scores) {
        cout << score << ' ';
    }
    cout << "\n\n";

    // =================================================================================
    // 4. 알고리즘: find
    // =================================================================================
    // find는 찾은 원소의 위치를 반복자로 돌려줍니다.
    // 찾지 못하면 end()와 같은 반복자를 돌려줍니다.
    const int target = 95;
    const auto found = find(scores.begin(), scores.end(), target);

    if (found != scores.end()) {
        cout << target << "점을 찾았습니다.\n\n";
    } else {
        cout << target << "점을 찾지 못했습니다.\n\n";
    }

    // =================================================================================
    // 5. 알고리즘: accumulate
    // =================================================================================
    // <numeric>의 accumulate는 범위 안의 값을 차례로 더합니다.
    const int total = accumulate(scores.begin(), scores.end(), 0);
    const double average =
        static_cast<double>(total) / scores.size();

    cout << "[합계와 평균]\n";
    cout << "합계: " << total << '\n';
    cout << "평균: " << average << "\n\n";

    // =================================================================================
    // 6. 람다(lambda)와 count_if
    // =================================================================================
    // 람다는 이름 없이 사용하는 작은 함수입니다.
    // count_if는 조건을 만족하는 원소의 개수를 세어 줍니다.
    const auto minimum_score = 90;
    const auto high_score_count = count_if(
        scores.begin(), scores.end(),
        [minimum_score](int score) { return score >= minimum_score; });

    cout << "90점 이상인 원소 수: " << high_score_count << "\n\n";

    // =================================================================================
    // 7. set: 중복 없이 값을 저장하는 컨테이너
    // =================================================================================
    // set은 값을 자동으로 정렬하고, 같은 값은 한 번만 저장합니다.
    // 따라서 vector처럼 [0] 등의 인덱스로 원소에 접근할 수 없습니다.
    set<string> names{"철수", "영희", "철수", "민수"};

    cout << "[set의 원소: 중복 제거 및 정렬]\n";
    for (const auto& name : names) {
        cout << name << ' ';
    }
    cout << "\n";
    cout << "원소 개수: " << names.size() << '\n';

    // insert는 값을 추가합니다. 이미 있는 값이면 set은 그대로 유지됩니다.
    names.insert("영희");
    names.insert("지민");

    // find는 값을 찾으면 그 위치를, 못 찾으면 end()를 돌려줍니다.
    if (names.find("지민") != names.end()) {
        cout << "지민을 찾았습니다.\n\n";
    }

    // =================================================================================
    // 8. stack: 마지막에 넣은 값을 가장 먼저 꺼내는 자료구조 (LIFO)
    // =================================================================================
    // LIFO는 Last In, First Out의 약자로, 나중에 넣은 값이 먼저 나옵니다.
    // 접시를 쌓아 올린 뒤 맨 위 접시부터 꺼내는 상황과 비슷합니다.
    stack<int> tasks;
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);

    cout << "[stack: 마지막에 넣은 값부터 꺼내기]\n";
    while (!tasks.empty()) {
        // top()으로 맨 위 값을 확인하고, pop()으로 제거합니다.
        cout << tasks.top() << ' ';
        tasks.pop();
    }
    cout << "\n\n";

    // =================================================================================
    // 9. queue: 먼저 넣은 값을 가장 먼저 꺼내는 자료구조 (FIFO)
    // =================================================================================
    // FIFO는 First In, First Out의 약자로, 먼저 넣은 값이 먼저 나옵니다.
    // 줄을 서서 먼저 온 사람부터 처리하는 상황과 비슷합니다.
    queue<string> customers;
    customers.push("민수");
    customers.push("영희");
    customers.push("철수");

    cout << "[queue: 먼저 넣은 값부터 꺼내기]\n";
    while (!customers.empty()) {
        // front()로 맨 앞 값을 확인하고, pop()으로 제거합니다.
        cout << customers.front() << ' ';
        customers.pop();
    }
    cout << "\n\n";

    // =================================================================================
    // 10. pair: 서로 다른 두 값을 한 쌍으로 저장
    // =================================================================================
    // first에는 이름, second에는 나이를 저장합니다.
    const pair<string, int> person{"철수", 25};

    cout << "[pair]\n";
    cout << "이름: " << person.first
              << ", 나이: " << person.second << "\n\n";

    // =================================================================================
    // 11. map: key와 value를 한 쌍으로 저장하는 컨테이너
    // =================================================================================
    // 여기서는 과목 이름(key)으로 점수(value)를 찾습니다.
    // map은 key를 기준으로 정렬된 상태를 유지합니다.
    map<string, int> subject_scores{
        {"수학", 90},
        {"영어", 85},
        {"과학", 95}
    };

    cout << "[map의 원소]\n";
    for (const auto& entry : subject_scores) {
        cout << entry.first << ": " << entry.second << '\n';
    }

    // map의 [] 연산자는 해당 key가 없으면 새 원소를 만듭니다.
    subject_scores["국어"] = 88;
    cout << "국어 점수 추가: " << subject_scores["국어"] << '\n';

    return 0;
}

/*
[vector의 원소]
80 95 70 100 85 
원소 개수: 5
비어 있는가? false

[반복자로 순회]
80 95 70 100 85 

[오름차순 정렬]
70 80 85 95 100 

95점을 찾았습니다.

[합계와 평균]
합계: 430
평균: 86

90점 이상인 원소 수: 2

[set의 원소: 중복 제거 및 정렬]
민수 영희 철수
원소 개수: 3
지민을 찾았습니다.

[stack: 마지막에 넣은 값부터 꺼내기]
30 20 10

[queue: 먼저 넣은 값부터 꺼내기]
민수 영희 철수

[pair]
이름: 철수, 나이: 25

[map의 원소]
과학: 95
수학: 90
영어: 85
국어 점수 추가: 88
*/