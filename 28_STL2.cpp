// 28_STL2.cpp
#include <iostream>
using namespace std;

// C++은 구간을 사용할 때, 반개 구간을 사용합니다.

// begin         end      => 반복자(Iterator)
//  |             |
//  1, 2, 3, 4, 5
//  : [begin, end)

#include <vector>

#if 0
int main()
{
    //           p1              p2(Past the end)
    //            |              |
    // int arr[5] = {1, 2, 3, 4, 5};
    vector<int> arr = {1, 2, 3, 4, 5};

    auto p1 = std::begin(arr);
    auto p2 = std::end(arr);

    // 반복자는 포인터의 연산을 인터페이스로 사용합니다. - 연산자 오버로딩
    while (p1 != p2)
    {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

#include <list>

#if 0
template <typename Iter>
void Print(Iter begin, Iter end)
{
    auto p = begin;
    while (p != end)
    {
        cout << *p << endl;
        ++p;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Print(std::begin(v), std::end(v));

    list<int> l = {10, 20, 30};
    Print(std::begin(l), std::end(l));
}
#endif

// * Java, C# ...
//  vector.sort()
//    list.sort()

// * C++                          <algorithm> - 일반함수
//   vector                          find
//   list        - Iterator -        sort
//   ...                             shuffle
//                                   ...
//  => 내가 설계한 컨테이너가 이터레이터의 C++규칙(인터페이스)를 구현한다면,
//     C++가 표준라이브러리가 제공하는 모든 알고리즘 함수를 그대로 이용할 수 있습니다.
//   - https://devdocs.io

#if 0
#include <algorithm>
#include <vector>

int main()
{
    // int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    vector<int> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    sort(std::begin(arr), std::end(arr));

    for (auto e : arr)
    {
        cout << e << endl;
    }
}
#endif

#include <vector>
#include <algorithm>

// C++20 - range
int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    // sort(std::begin(v), std::end(v)); // C++98

    // g++ 28_STL2.cpp -std=c++20
    std::ranges::sort(v); // C++20

    for (auto e : v)
    {
        cout << e << endl;
    }
}

#if 0
int main()
{
    //           p1              p2(Past the end)
    //            |              |
    // int arr[5] = {1, 2, 3, 4, 5};
    vector<int> arr = {1, 2, 3, 4, 5};

    auto p1 = std::begin(arr);
    auto p2 = std::end(arr);

    // 반복자는 포인터의 연산을 인터페이스로 사용합니다. - 연산자 오버로딩
    while (p1 != p2)
    {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif