// 16_초기화리스트3.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b}
    {
    }
};

// 초기화리스트를 반드시 사용해야 하는 경우
// 1) 멤버 데이터가 const 인 경우
// 2) 멤버 데이터가 reference 인 경우
// 3) 멤버 데이터가 기본 생성자를 제공하지 않는 경우

class Rect
{
    Point leftTop;

public:
    // Rect() : leftTop{} {}
    // 원인: 컴파일러가 생성하는 기본 생성자는 멤버 객체의 기본 생성자를 호출하는 코드를 작성합니다.

    // 핵심: 기본 생성자를 제공하지 않는 멤버 객체가 존재하는 경우,
    //      반드시 초기화리스트를 통해 명시적으로 해당 멤버 객체를 초기화하는 코드를 작성해주어야 합니다.
    Rect() : leftTop{0, 0}
    {
    }
};

int main()
{
    Rect rect;
}