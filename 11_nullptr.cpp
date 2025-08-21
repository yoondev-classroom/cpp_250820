// 11_nullptr.cpp
#include <iostream>
using namespace std;

// #define NULL (void*)0

#if 0
int main()
{
    // 포인터 타입은 유효하지 않은 경우, NULL을 지정해야 합니다.
    // int *p1 = 0;
    // 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.
    int *p1 = NULL;

    cout << p1 << endl;
}
#endif

void foo(int n) { cout << "int" << endl; }
void foo(int *p) { cout << "int* " << endl; }

// C++11은 NULL을 대체하는 새로운 값이 추가되었습니다.
// => nullptr

int main()
{
    int *p = nullptr;

    foo(0);
    foo(nullptr);
    // foo(NULL); // NULL은 타입 안정성이 없습니다.

    if (p)
    {
    }

    if (p != nullptr)
    {
    }
}