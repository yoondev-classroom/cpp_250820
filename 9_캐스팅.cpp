// 9_캐스팅.cpp
#include <iostream>
using namespace std;

// 캐스팅이 필요한 경우
// 1) 정수 타입과 실수 타입간의 변환 => static_cast
// 2) 정수 타입간의 변환 => static_cast
// 3) void*를 구체적인 포인터 타입으로의 변환 => static_cast

// 4) 메모리 재해석 - 다른 포인터 타입을 원하는 포인터 타입으로의 변환 -* 위험!!!
// 5) const T* -> T*
//    const T& -> T&
//     => 타입 불일치 문제를 해결하기 위해서, 명시적인 캐스팅이 필요할 수 있습니다.

// => C++은 용도와 목적에 맞게 캐스팅 연산자를 별도로 제공합니다.
// 1) static_cast
// 2) reinterpret_cast
// 3) const_cast
// 4) dynamic_cast

// 옛날 함수
void Print(char *str)
{
    printf("%s\n", str);
}

int main()
{
    double d{3.14};
    // int n{(int)d};
    int n{static_cast<int>(d)};

    long long x = 10000LL;
    // int n2{(int)x};
    int n2{static_cast<int>(x)};

    // void*
    // - 가르키는 타입의 정보가 존재하지 않습니다.
    // - 모든 타입의 주소를 저장할 수 있습니다.
    // - 포인터 참조 연산은 불가능합니다.
    void *pv = NULL;
    pv = &n;
    pv = &x;

    // *(long long *)pv = 42LL;
    *static_cast<long long *>(pv) = 42LL;
    // long long *llp = (long long *)pv;
    long long *llp = static_cast<long long *>(pv);

    //----
    int data = 0x12345678;
    // char *pc = (char *)&data;
    // char *pc = static_cast<char *>(&data);
    char *pc = reinterpret_cast<char *>(&data);
    printf("%x %x %x %x\n", pc[0], pc[1], pc[2], pc[3]);

    // long long *llp2 = (long long *)&data;
    // *llp2 = 1000000000000LL; // 미정의 동작

    const char *s = "hello";
    // Print((char *)s); // const char* -> char*
    // Print(static_cast<char *>(s));
    // Print(reinterpret_cast<char *>(s));
    Print(const_cast<char *>(s));
}