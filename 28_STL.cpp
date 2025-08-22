// 28_STL.cpp
#include <iostream>
using namespace std;

// Standard Template Library(STL)
// - 1998년 1차 표준안

// STL 핵심 구성 요소
// 1) 컨테이너: 자료 구조
// 2) 알고리즘: 함수의 집합 => 컨테이너를 대상으로 연산을 수행합니다.
// 3) 반복자

// 컨테이너
// - vector, list, deque
// - stack, queue
// - map, set: (이진 트리)
//   unorderd_map, unordered_set (해시) - C++11
// ....
// 1) 템플릿 기반입니다.
// => 타입에 상관없이 해당하는 컨테이너를 이용할 수 있습니다.
// 2) 멤버 함수의 이름이 유사합니다.
// => 사용자는 컨테이너를 다른 컨테이너로 쉽게 전환할 수 있습니다.

//      |-------------------------------|
// push_front                        push_back
//  pop_front                         pop_back
//    front                            back
#if 0
#include <vector>
#include <list>
#include <deque>

int main()
{
    // vector<int> v = {10, 20, 30, 40, 50};
    // list<int> v = {10, 20, 30, 40, 50};
    deque<int> v = {10, 20, 30, 40, 50};
    v.push_back(10);
    v.push_back(20);

    for (auto e : v)
    {
        cout << e << endl;
    }
}
#endif

#include <vector>
#include <list>

// => 컨테이너의 구조에 따라서 지원되는 연산의 범위가 다릅니다.
//    "성능 이슈"

int main()
{
    // vector<int> v = {10, 20, 30, 40, 50};

    // cout << v[3] << endl;
    // vector는 연속된 메모리이기 때문에, 임의 접근 연산을 사용할 수 있습니다.
    // list는 해당 연산을 제공하지 않습니다.

    vector<int> v = {10, 20, 30, 40, 50};
    // v.push_front(100);
    // list는 데이터를 앞에 삽입할 수 있습니다.
    // vector는 연속된 메모리이기 때문에, 앞에 삽입이 불가능합니다.

    v.push_back(10);
    v.push_back(20);

    for (auto e : v)
    {
        cout << e << endl;
    }
}