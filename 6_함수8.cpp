// 6_함수8.cpp
#include <iostream>
using namespace std;

// 반환타입 함수이름(함수 인자 정보)
int add(int a, int b)
{
    return a + b;
}

#if 0
int main()
{
    int n = 10;

    int *pn = &n;
    // 주소를 통해 메모리에 접근해서 값을 읽거나 변경할 수 있습니다.

    cout << &n << endl;
    cout << pn << endl;

    *pn = 42;
    cout << n << endl;
    n = 100;

    cout << *pn << endl;
}
#endif

#if 0
int x[3];

int (*foo())[3]
{
    return &x; // int (*)[3]
}

// int (*foo())[3]

//  foo()
//  : foo는 인자 없는 함수입니다. 함수의 반환 타입은?
//  (*foo())
//  : 함수의 반환 타입은 포인터 입니다. 포인터가 가르키는 타입은?
//  (*foo())[3]
//  : 포인터가 가르키는 타입은 3개의 길이를 가지는 배열입니다.
//    배열 원소의 타입은?
//  int (*foo())[3]
//  : 배열의 원소의 타입은 int 입니다.

int main()
{
    int x[3] = {10, 20, 30};
    // x: int[3]

    // int[3]* px = &x;
    // - [3] 배열의 크기를 지정하는 기호는 식별자의 오른쪽에 위치해야 합니다.

    // int* px[3];
    // px는 3개의 길이를 가지는 배열입니다.
    //  : [ * ][ * ][ * ]
    //      |    |    |
    //    int   int  int

    // int (*px)[3];
    // px -----> [ int ][ int ][ int ]
}
#endif
int x[3];
// C++11에서는 함수를 정의하는 새로운 문법이 도입되었습니다.
// => Trailing Return Type

// int add(int a, int b)
auto add(int a, int b) -> int
{
    return a + b;
}

// 1) 복잡한 반환 타입을 가독성 있게 작성할 수 있습니다.
// int (*foo())[3]
auto foo() -> int (*)[3]
{
    return &x; // int (*)[3]
}

// 2) 컴파일러가 return을 보고 반환 타입을 결정합니다.
//    반환타입을 추론할 수 있습니다.
auto foo2()
{
    return &x;
}

// 3) decltype을 통해 인자 타입을 기반으로 반환 타입을 결정할 때,
//    기존의 함수의 방식은 사용이 불가능합니다.
// template <typename T1, typename T2>
// decltype(a+b) add(T1 a, T2 b)
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

// add(3.14, 42);
//  : T1 -> double
//    T2 -> int

// Rust, Swift, Kotlin, Go
// => 모두 Trailing Return Type 기반으로 함수를 작성합니다.
