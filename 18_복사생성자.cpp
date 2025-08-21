// 18_복사생성자.cpp
#include <iostream>
using namespace std;

// 1) 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 기본 생성자를 제공합니다.
// 2) 사용자가 생성자를 1개라도 제공하면, 컴파일러는 기본 생성자를 제공하지 않습니다.

// 3) 사용자가 자신과 동일한 타입의 객체를 인자로 전달받는 생성자(복사 생성자)를 제공하지 않는다면,
//    컴파일러가 멤버를 복사하는 복사 생성자를 자동으로 제공합니다.

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b}
    {
    }

    void Print() { cout << x << ", " << y << endl; }

    // 컴파일러가 제공하는 복사 생성자의 형태
    Point(const Point &rhs)
        : x{rhs.x}, y{rhs.y}
    {
        cout << "Point(const Point&)" << endl;
    }
};

int main()
{
    Point pt1{10, 20};

    // 자신과 동일한 타입으로 객체를 초기화하는 경우 호출됩니다.
    Point pt2 = pt1;
    Point pt3 = {pt1};
    Point pt4{pt1};

    // pt2.Print();
}