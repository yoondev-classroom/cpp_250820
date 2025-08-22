// 17_this.cpp
// 중요합니다!
#include <iostream>
using namespace std;

class Point
{
    int x = 0;
    int y = 0;

public:
    // * thiscall
    // void Set(Point* this, int a, int b)
    void Set(int a, int b)
    {
        // 멤버함수의 this: 함수를 호출한 객체의 주소

        x = a;
        // this->x = a;
        y = b;
        // this->y = b;
    }
};

void Set(int a, int b)
{
}

// 일반함수와 멤버함수(thiscall)의 차이점
// => 멤버 함수는 함수를 호출한 객체의 주소를 첫번째 인자 this로 암묵적으로 전달합니다.

int main()
{
    Set(10, 20);
    /*
    mov     edx, 20
    mov     ecx, 10
    call    void Set(int,int)                     ; Set
    */

    Point pt;
    pt.Set(10, 20);
    /*
    mov     r8d, 20
    mov     edx, 10
    lea     rcx, QWORD PTR pt$[rsp] ; rcx = &pt
    call    void Point::Set(int,int)
    */

    // Point pt1;
    // Point pt2;

    // pt1.Set(10, 20);
    // pt2.Set(100, 200);
}