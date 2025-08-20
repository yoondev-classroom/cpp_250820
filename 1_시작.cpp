// 1_시작.cpp

// MISRA

// 1. 확장자
//  - .cpp, .cc(Google), .cxx

// 2. 컴파일러
//  - GCC(GNU C/C++ Compiler)
//  - Microsoft Visual C/C++ Compiler(MSVC)
//  - LLVM Clang

// 3. C++ 표준
//  - 1983년: C++ 탄생

//  - 1998년: C++ 1차 표준안  - C++98
//  - 2003년: C++ 1차 표준안, 개정안 - C++03
//  => C++98/03 => 1.0
//----------------------------------
//  - 2011년: C++ 2차 표준안
//  - 2014년: C++ 2차 표준안, 개정안
//  => C++11/14 => Modern C++
//  - C++17 / C++20 / C++23

// 4. C++에서 C의 모든 기능을 사용할 수 있습니다.
#include <stdio.h>
#if 0
int main(void)
{
    printf("Hello, C\n"); /* aaa */
    return 0;
}
#endif

int a(void)
{
    printf("a\n");
    return 10;
}

int b(void)
{
    printf("b\n");
    return 20;
}

void foo(int a, int b)
{
}

int main(void)
{
    foo(a(), b());
    // C/C++ 표준에서는 인자가 전달된다.

    int a = 10;
    int n;
    scanf("%d", &n);

    printf("result: %d\n", a / n);
    // 정수를 0으로 나누는 행위는 미정의 동작입니다.
}

// 5. C언어의 표준과 C++ 안에서의 C의 표준은 다릅니다.
// 6. 표준
//    - 미지정 동작
//    : 표준의 설명이 부족할 때, 컴파일러의 구현에 의존하는 결과가 나옵니다.
//    - 미정의 동작