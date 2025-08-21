// 7_제어문.cpp
#include <iostream>
using namespace std;

// Control Statement
// - if, if-else, if-else if-else
// - while, do-while, for
// - switch

#if 0
int main()
{
    double x[5] = {10.5, 20, 30, 40, 50}; // 컨테이너, 컬렉션

    constexpr int len = sizeof(x) / sizeof(x[0]); // C++11
    for (int i = 0; i < len; ++i)
    {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x)
    {
        cout << e << endl;
    }
}
#endif

// 컨테이너
//  - 정적 배열: 컴파일 시간에 길이가 고정됩니다.
//  - 동적 배열: vector
//  - 연결 리스트: list

#if 1
#include <vector>
#include <list>
// C++에는 템플릿 기반의 수많은 컨테이너를 제공하고 있습니다.
// => STL(Standard Template Library)

int main()
{
    vector<int> v = {10, 20, 30};
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    for (auto e : v)
    {
        cout << e << endl;
    }
}
#endif

// 함수의 결과가 실패할 경우, 0이 아닌 값을 반환하는 함수입니다.
// => 함수가 실패 가능성이 존재하는 경우, 반드시 반환값을 통해 성공/실패 여부를 판단해야 합니다.
int Process1()
{
    // ...
    return 0; /* 성공 */
}

int Process2()
{
    // ...
    return 1; /* 실패 */
}

// C++17, If Statement with Initializer
// => Swift에서 먼저 도입되었습니다.
int main()
{

    if (int ret = Process1(); ret != 0)
    {
        // ...
    }

    if (int ret = Process2(); ret != 0)
    {
        // ...
    }
}

#if 0
int main()
{
    int ret = 0;

    ret = Process1();
    if (ret != 0)
    {
        // ...
    }

    ret = Process2();
    if (ret != 0)
    {
        // ...
    }
}
#endif