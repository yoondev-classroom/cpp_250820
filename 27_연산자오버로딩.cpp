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

    // Point Point::Add(Point* this, const Point &rhs)
    Point Add(const Point &rhs) const
    {
        Point pt{x + rhs.x, y + rhs.y};
        return pt;
    }

    friend Point Add(const Point &lhs, const Point &rhs);
};

Point Add(const Point &lhs, const Point &rhs)
{
    Point pt{lhs.x + rhs.x, lhs.y + rhs.y};
    return pt;
}

int main()
{
    Point pt1{10, 20};
    Point pt2{100, 200};

    pt1.Print();
    pt2.Print();

    // Point를 더하는 기능을 추가하고 싶습니다.
    // 1) 멤버 함수
    Point result = pt1.Add(pt2);
    result.Print();

    // 2) 일반 함수
    Point result2 = Add(pt1, pt2);
    result2.Print();
}