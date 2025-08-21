// 21_상수멤버함수3.cpp
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

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

#if 0
class Rect
{
    Point leftTop;

public:
    Rect() : leftTop{0, 0} {}

    // Point leftTop() const { return leftTop; }
    // 불필요한 복사 생성의 비용이 발생합니다.

    // 상수 멤버 함수에서는 멤버를 일반 레퍼런스로 타입으로 반환하는 것이 허용되지 않습니다.
    const Point &GetLeftTop() const { return leftTop; }
    Point &GetLeftTop() { return leftTop; }

    // C++에서는 상수 멤버 함수와 비상수 멤버 함수를 모두 제공할 수 있습니다.

    // 핵심: 내부 멤버의 참조/포인터를 반환할 때,
    //      상수 멤버 함수만 제공하면, const타입으로만 제공해야 합니다.
    //   => 비상수 멤버 함수도 같이 제공하는 것이 좋습니다.
};

// * 상수 멤버 함수와 비상수 멤버 함수를 모두 제공한 경우
//      Point&   -> 비상수 멤버 함수
// const Point&  -> 상수 멤버 함수
//      Point*   -> 비상수 멤버 함수
// const Point*  -> 상수 멤버 함수
//      Point    -> 비상수 멤버 함수
// const Point   -> 상수 멤버 함수

// * 상수 멤버 함수만 제공하는 경우
//      Point&   -> 상수 멤버 함수
// const Point&  -> 상수 멤버 함수
//      Point*   -> 상수 멤버 함수
// const Point*  -> 상수 멤버 함수
//      Point    -> 상수 멤버 함수
// const Point   -> 상수 멤버 함수

// * 비상수 멤버 함수만 제공하는 경우
//      Point&   -> 비상수 멤버 함수
// const Point&  -> X
//      Point*   -> 비상수 멤버 함수
// const Point*  -> X
//      Point    -> 비상수 멤버 함수
// const Point   -> X

int main()
{
    Rect r; // 값을 변경할 수 있는 객체
    Point &pt = r.GetLeftTop();
    pt.SetX(100);
    pt.Print();
    // 상수 멤버 함수가 제공하는 const&를 통해서는 일반 레퍼런스로 처리할 수 없습니다.

    const Rect c;
    const Point &pt2 = c.GetLeftTop();
}
#endif

class Rect
{
    Point leftTop;

public:
    Rect() : leftTop{0, 0} {}

    Point GetLeftTop() const { return leftTop; }
    // 보안 코딩(Secure Coding)
    // => 객체 내부의 상태를 Getter로 제공할 때, 참조로 제공하는 것은 위험합니다.
    // => 내부의 상태를 반환할 때, 복사본을 반환해라.

    // Point &GetLeftTop() { return leftTop; }

    void Print() const
    {
        leftTop.Print();
    }
};

int main()
{
    Rect r; // 값을 변경할 수 있는 객체
    // Point &pt = r.GetLeftTop();

    Point pt = r.GetLeftTop();
    pt.SetX(1000);

    r.Print();
}