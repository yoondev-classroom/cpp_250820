// 8_레퍼런스.cpp
// - 중요합니다.

#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 100;

    int *pn = &n;

    *pn = 42;
    cout << *pn << endl;
    cout << n << endl;

    cout << &n << endl;  // 0x16d19ab8c
    cout << &pn << endl; // 0x16d19ab80
}
#endif

// 1. C++은 레퍼런스 타입이 도입되었습니다.
//  레퍼런스: 기존 메모리에 새로운 이름을 부여합니다.
#if 1
int main()
{
    int n = 100;

    int &rn = n;

    rn = 42;
    cout << rn << endl;
    cout << n << endl;

    // 기존 메모리에 새로운 이름을 부여하는 것이기 때문에,
    // 동일한 주소값이 출력됩니다.
    cout << &n << endl;  // 0x16bd4eb8c
    cout << &rn << endl; // 0x16bd4eb8c
}
#endif