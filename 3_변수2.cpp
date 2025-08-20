// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = {10, 20, 30};
    Point pt1 = {10, 20};

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3]{10, 20, 30};
    Point pt2{10, 20};
}
#endif

#if 1
// C++11 - Uniform Initialization
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = {42};
    int x1[3] = {10, 20, 30};
    Point pt1 = {10, 20};

    // Direct Initialization(직접 초기화)
    int n2{42};
    int x2[3]{10, 20, 30};
    Point pt2{10, 20};
}
#endif

#if 0
int main()
{
    // int n1;
    // 초기화되지 않은 지역 변수의 값은 미지정입니다.
    // 알수 없습니다.
    // => 반드시 초기값을 제공하는 것이 좋습니다.

    int n1;
    n1 = 100; // 초기화가 아니라 대입입니다.

    int n2 = 100; // 초기화
}
#endif