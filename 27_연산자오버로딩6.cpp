// 27_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 복사 생성자를 제공하지 않으면, 컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.
//     : Point(const Point&)

// 2. 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 멤버를 복사하는 대입 연산자를 제공합니다.
//     : Point &operator=(const Point &rhs)

// => 복사 정책은 "복사 생성자"와 "대입 연산자"를 통해서 결정됩니다.
//   사용자가 복사 생성자를 제공했다면, 반드시 대입연산자도 함께 제공해주어야 합니다.

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    Point(const Point &rhs)
        : x{rhs.x}, y{rhs.y}
    {
        cout << "Point(const Point&)" << endl;
    }

    Point &operator=(const Point &rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this; // 연쇄 호출
    }
};

int main()
{
    Point pt1{10, 20};

    Point pt2{pt1}; // 복사 생성자 - "초기화"

    // pt2 = pt1 = pt2; // 대입 연산자
    pt2 = pt1;

    int n1 = 10;
    int n2 = 20;
    int n3 = 30;
    n3 = n2 = n1;
}