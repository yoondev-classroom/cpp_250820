// 8_레퍼런스5.cpp
#include <iostream>
using namespace std;

// C/C++에서 함수로 배열을 전달할 때,
// 배열의 전체가 복사되는 것이 아니라, 배열의 첫번째 원소의 주소가 전달됩니다.

// void PrintArray(int x[3])
#if 0
void PrintArray(const int *x, int n)
{
    cout << sizeof(x) << endl; // 8
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << endl;
    }

    // x[0] = 10000;
}

int main()
{
    int x[3] = {10, 20, 30};
    // x의 타입은? int[3]

    PrintArray(x, sizeof(x) / sizeof(x[0]));
    // 배열의 식별자(x)는 배열의 첫번째 원소의 시작 주소로 해석됩니다. - Decay

    cout << sizeof(x) << endl; // 12
    cout << x[0] << endl;

    int y[10] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    PrintArray(y, 10);
}
#endif

#if 1
// int(&)[3]
#if 0
void PrintArray(int (&x)[3])
{
    // cout << sizeof(x) << endl;
    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i)
    {
        cout << x[i] << endl;
    }
}
// C++은 함수 오버로딩이 가능합니다.
void PrintArray(int (&x)[5])
{
    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i)
    {
        cout << x[i] << endl;
    }
}
#endif

// 함수의 알고리즘(구현)이 동일하고, 인자와 반환타입만 다를 경우,
// 컴파일 타임에 코드를 생성하는 템플릿으로 제공할 수 있습니다.
template <typename TYPE>
void PrintArray(const TYPE &x)
{
    // 아래 처럼 만들면, 배열밖에 사용할 수 없습니다.
    // - vector / list는 사용할 수 없습니다.
    /*
    constexpr int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i)
    {
        cout << x[i] << endl;
    }
    */
    for (auto e : x)
    {
        cout << e << endl;
    }
}

#include <vector>

int main()
{
    int x[3] = {10, 20, 30};
    PrintArray(x);
    // 레퍼런스는 decay 수행되지 않습니다.

    int y[5] = {1, 2, 3, 4, 5};
    PrintArray(y);

    vector<int> arr = {1, 2, 3, 4, 5};
    PrintArray(arr);
}
#endif