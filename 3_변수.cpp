// 3_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입
//  => 사용자가 원하는 변수를 묶어서 새로운 타입을 만들 수 있습니다.
struct Point
{
    // C에서는 Point는 타입명이 아니라 구조체 태그명입니다.
    // C++에서는 Point는 태그명이 아니라 타입명입니다.

    int x;
    int y;
};

int main()
{
    // C
    struct Point pt1;
    pt1.x = 10;
    pt1.y = 200;

    // C++
    Point pt2;
    pt2.x = 10;
    pt2.y = 200;
}