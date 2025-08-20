// 4_const.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 10;
    // 변수(Variable): 실행 시간에 변하는 값
    n = 100; /* OK */

    const int c = 10;
    // 상수(Constant Variable): 실행 시간에 값을 변경할 수 없습니다.

    // c = 1000; /* 컴파일 오류! */
}
#endif

// 1. C++ 에서는 const 변수를 초기화하지 않은 경우, 컴파일 오류가 발생합니다.
//    반드시 초기값을 지정해야 합니다.

// 2. C의 const와 C++의 const는 다릅니다.
//    C++ 컴파일러가 const의 값을 컴파일 시간에 판단할 수 있을 경우
//    상수 표현식으로 취급합니다.
//    C는 상수 표현식으로 평가하지 않습니다.
//  * 런타임 상수
//  * 컴파일 타임 상수: 상수 표현식

#if 0
int main()
{
    int n1 = 10;

    const int c = n1; // 런타임 상수
    printf("%d\n", c);
    // 컴파일러는 c의 메모리를 읽어서 처리합니다.
}
#endif

#if 0
int main()
{
    const int n = 10;
    // 컴파일러는 n의 값이 10이고, 실행 시간에 값이 변경되지 않는
    // 사실을 알 수 있습니다.
    // => 컴파일러는 n을 상수 표현식으로 취급합니다.
    printf("%d\n", n);
    // n을 컴파일 시간에 10으로 바꿉니다.

    printf("%d\n", n);
    // * n이 변수인 경우
    // n의 메모리를 읽어서, 값을 레지스터로 로드합니다.
    // printf의 인자로 레지스터를 전달합니다.
}
#endif

#if 0
int main()
{
    int n = 10 + 20;
    // 10+20이 컴파일 시간에 계산될까요?
    //          실행 시간에 계산될까요?

    // 상수 표현식
    // - 컴파일러가 컴파일 시간에 미리 계산할 수 있는 표현식
}
#endif

#if 0
int main()
{
    // const int c; /* 컴파일 오류 */
    const int c = 42;
}
#endif

// C++ 언어의 철학
// => Zero Overhead

// C++11 - constexpr(상수 표현식에서 사용하는 키워드입니다.)
int main()
{
    // constexpr const int c1 = 100; /* OK */
    constexpr int c1 = 100;
    // 일반적으로 const 키워드는 생략합니다.
    //  - c1의 타입은 const int 입니다.

    int n = 100;
    const int c2 = n;
    /* 런타임 상수이기 때문에, 컴파일 오류가 발생합니다.*/
    //  - c2의 타입은 const int 입니다.
}