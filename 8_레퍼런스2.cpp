// 8_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Increment(int x)
{
    ++x;
}

void Increment_Pointer(int *px)
{
    // 포인터 변수는 반드시 유효성 여부를 체크해야 합니다.
    if (px)
    {
        ++(*px);
    }
}

void Increment_Reference(int &rx)
{
    // 레퍼런스는 별도의 유효성 체크가 필요하지 않습니다.
    ++rx;
}

int main()
{
    int x = 10;
    Increment(x);           // Call by value - readonly
    Increment_Pointer(&x);  // Call by pointer
    Increment_Reference(x); // Call by reference

    cout << x << endl;
}