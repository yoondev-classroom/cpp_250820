// 3_변수3.cpp
#include <iostream>
using namespace std;

// 정수 타입
//   1바이트 정수: -128 - +127
//         signed char  / unsigned char

//   2바이트 정수: -32768 - +32767
//         signed short / unsigned short

//   4바이트 정수: -21억 - +21억 : signed int
//                0   -  42억 : unsigned int
//   8바이트 정수
//         signed long / unsigned long : MSVC(long: 4바이트)
//                                  GCC/Clang(long: 8바이트
//         signed long long / unsigned long long

// => C/C++ 표준에서는 정수 타입의 크기가 지정되어 있지 않습니다.
//    플랫폼과 컴파일러에 따라서 크기가 달라질 수 있습니다.
// => 표준에서 보장하는 정수 타입의 크기는 char 타입은 1바이트 입니다.

// 실수 타입
//  float / double

// 문자 타입
//   char

// 사용자 정의 타입
//  struct / enum / union

// C: stdint.h
#if 0
#include <cstdint>

int main()
{
    int8_t a = 10;

    uint16_t b = 100;
    int16_t c = 100;

    int n = 10; // signed int n = 10;
    unsigned int n2 = 100U;

    // 1바이트 부호 있는 정수
    char n3 = 40;
    // char 타입은 문자 타입입니다.
    // char 타입으로 사용할 경우, signed/unsigned 이지 미지정입니다.
    // => char 타입을 정수 타입으로 사용하기 위해서는 반드시
    //    signed/unsigned을 명시해야 합니다.
}
#endif

// 핵심: C++11에서 도입된 Uniform Initialization을 사용하면
//      정수와 실수간의 암묵적인 변환을 허용하지 않습니다.
#if 0
int main()
{
    double d1 = 3.14;
    // int n1 = (int)d1; // 명시적인 캐스팅

    int n1 = d1;
    // C/C++은 정수와 실수 타입간의 암묵적인 변환을 허용합니다.
    // 현대적인 소프트웨어 개발에서 정수와 실수간의 암묵적인 변환으로 인해
    // 많은 문제가 발생하였습니다.
    //  => C, C++, Java, C# ...

    // - 현대적인 언어들은 암묵적인 변환을 허용하지 않습니다.
    //  => Go, Rust, Kotlin, Swift ...

    // C++11, Uniform Initialization
    double d2{3.14};
    // int n2{d2}; /* 컴파일 오류! */
    int n2{(int)d2}; /* 명시적인 캐스팅은 허용됩니다! */

    double d3 = {3.14};
    int n3 = {(int)d3};
}
#endif

// 핵심: C++11에서 도입된 Uniform Initialization을 사용하면
//      정수와 정수간의 암묵적인 변환도 허용되지 않습니다.
int main()
{
    long n1 = 10000000000000000L;
    int n2 = n1;

    printf("%d\n", n2);

    if (n1 > INT_MAX || n1 < INT_MIN)
    {
        cout << "범위를 벗어납니다." << endl;
    }
    else
    {
        int n3 = {(int)n1};
    }
}