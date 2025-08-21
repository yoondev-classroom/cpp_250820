
// 16_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 주의 사항
// 1. 초기화를 통해 멤버 데이터가 초기화되는 순서는 초기화리스트의 순서와 상관없습니다.
// 2. 객체의 멤버가 초기화되는 순서는 멤버가 선언된 순서로 초기화됩니다.
// => 초기화리스트는 멤버가 선언된 순서와 동일하게 작성해야 합니다.

#if 0
class Point
{
    int x;
    int y;

public:
    Point(int n)
        : y{n}, x{y + 10} // 미정의 동작
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt{10};
    pt.Print(); // 11, 10
}
#endif

#if 0
class Point
{
    int y;
    int x;

public:
    Point(int n)
        : y{n}, x{y + 10}
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt{10};
    pt.Print(); // 11, 10
}
#endif

#if 0
class Point
{
    // C++11, 멤버 초기화
    // => 생성자로 초기화되지 않은 멤버 데이터의 기본값으로 사용됩니다.
    int x = 0;
    int y = 0;

public:
    // Point() {}
    Point() = default;

    Point(int a, int b)
        : x{a}, y{b}
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt;
    // Point pt{10, 20};
    pt.Print();
}
#endif

// C++ 에서는 멤버 데이터의 이름을 구분해서 짓습니다.
// 1) mX, mY
// 2) m_x, m_y
// 3) x_, y_ => C++ 표준에서 권장하는 방식
// ---------------

// 4) _x, _y => 사용하면 안됩니다. C++ 표준 라이브러리 구현의 컨벤션이기 때문에
//              충돌 가능성이 있습니다.

class Point
{
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_{x}, y_{y}
    {
    }

    void Print()
    {
        cout << x_ << ", " << y_ << endl;
    }
};

int main()
{
    Point pt {}
}