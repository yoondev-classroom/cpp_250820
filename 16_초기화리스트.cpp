// 16_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.
// - 초기화: 변수를 메모리에 할당하면서, 초기값을 지정하는 행위
// -  대입: 이미 할당된 메모리의 값을 변경하는 행위
#if 0
int main()
{
    int n;
    n = 10; // 대입

    int c = 10; // 초기화
}
#endif

// 반드시 초기화해야 하는 2가지 경우
// 1) const
// 2) reference
#if 0
int main()
{
    const int c = 100;

    int n = 10;
    int &rn = n;
}
#endif

// 핵심: 생성자에서 멤버를 초기화하기 위해서는 "초기화 리스트"를 이용해야 합니다.
class Point
{
    const int x;
    const int y;

public:
    Point(int a, int b)
        : x{a}, y{b} // 초기화 리스트
    {
        // x = a; // 대입
        // y = b; // 대입
    }
};

int main()
{
    Point pt{10, 20};
}