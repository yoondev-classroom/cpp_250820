// 10_동적메모리할당.cpp
#include <iostream>
using namespace std;

#if 0
void *malloc(size_t size);
void free(void *ptr);

int main()
{
    int *p = static_cast<int *>(malloc(sizeof(int) * 10));
    if (p == NULL)
    {
        // ...
    }

    p[0] = 10;
    p[1] = 1000;

    free(p); // 반드시 해지해야 합니다.
    p = NULL;
}
#endif

#if 0
// 1. C++에서는 동적 메모리 할당/해지의 연산자를 제공하고 있습니다.
// 2. 단일 메모리 할당 - new / delete
//    연속된 메모리 할당 - new / delete[]
int main()
{
    int *p1 = new int;
    // 별도의 명시적인 캐스팅이 필요하지 않습니다.

    *p1 = 100;
    cout << *p1 << endl;

    delete p1;

    int *p2 = new int[10];
    // ...
    // delete p2; // 미정의 동작
    delete[] p2; // !!!!!
}
#endif

#if 0
int main()
{
    int *p = static_cast<int *>(malloc(sizeof(int)));
    // p가 가르키는 메모리는 쓰레기값을 가집니다. - 초기화되지 않은 메모리입니다.
    *p = 42;

    delete p;
}
#endif

int main()
{
    // int *p = new int;
    // p가 가르키는 메모리는 초기화되지 않습니다.

    // * new를 사용하면, 초기화를 할 수 있습니다.
    int *p = new int{42};
    cout << *p << endl;
    delete p;

    int *p2 = new int[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
    {
        cout << p2[i] << endl;
    }
    delete[] p2;
}