// 21_상수멤버함수2.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }

    // 객체의 상태를 변경하지 않는 모든 멤버 함수는 반드시 "상수 멤버 함수" 이어야 합니다.
    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    // 일반 가변 객체는 멤버 함수도 호출할 수 있고, 상수 멤버 함수도 호출할 수 있습니다.
    Point pt{10, 20}; // 가변 객체
    pt.SetX(100);
    pt.SetX(200);
    pt.Print();

    const Point *p = &pt;
    // const T*를 통해서는 오직 상수 멤버 함수만 호출할 수 있습니다.
    // p->SetX(100); /* 오류 */
    // p->SetY(100); /* 오류 */
    p->Print();

    const Point &r = pt;
    // const T&를 통해서는 오직 상수 멤버 함수만 호출할 수 있습니다.
    // r.SetX(100); /* 오류 */
    // r.SetY(100); /* 오류 */
    r.Print();

    // 상수 객체는 일반 멤버 함수는 호출할 수 없고, 오직 상수 멤버 함수만 호출할 수 있습니다.
    const Point c{10, 20}; // 상수 객체(불변 객체)
    // c.SetX(100); /* 오류 */
    // c.SetY(200); /* 오류 */
    c.Print();
}