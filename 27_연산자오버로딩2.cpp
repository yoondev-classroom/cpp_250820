// 27_연산자오버로딩.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    void Print() const { cout << x << ", " << y << endl; }

    // Point operator+(const Point &rhs) const
    // {
    //     Point pt{x + rhs.x, y + rhs.y};
    //     return pt;
    // }

    friend Point operator+(const Point &lhs, const Point &rhs);
    friend Point operator-(const Point &lhs, const Point &rhs);
};

Point operator+(const Point &lhs, const Point &rhs)
{
    Point pt{lhs.x + rhs.x, lhs.y + rhs.y};
    return pt;
}

Point operator-(const Point &lhs, const Point &rhs)
{
    Point pt{lhs.x - rhs.x, lhs.y - rhs.y};
    return pt;
}

int main()
{
    Point pt1{10, 20};
    Point pt2{100, 200};

    pt1.Print();
    pt2.Print();

    // 멤버함수 - pt1.Add(pt2);
    // 일반함수 - Add(pt1, pt2);
    // Point result = pt1 + pt2;
    //  : C++에서는 객체를 대상으로 연산자를 사용할 경우,
    //    약속된 멤버 함수 또는 일반 함수를 호출합니다.
    //    => 연산자 오버로딩

    Point result = pt1 + pt2;
    //  1) 멤버 함수: pt1.operator+(pt2)
    //  2) 일반 함수: operator+(pt1, pt2)
    result.Print();

    Point result2 = pt1 - pt2;
    result2.Print();
}

// Java -> Kotlin(연산자 오버로딩이 있습니다.)