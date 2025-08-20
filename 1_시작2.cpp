// 1_시작2.cpp
// C언어의 표준과 C++ 안에서의 C의 표준은 다릅니다.
// => MISRA에서도 C와 C++의 규약은 다릅니다.

#if 0
#include <stdio.h>
// C 라이브러리의 표준 입출력 함수

#if 0
void foo(void) {} // C++에서는 void를 명시하지 않아도, 컴파일 오류로 체크할 수 있습니다.
void goo() {}

int main(void)
{
    // foo(10);
    // goo(10);

    printf("Hello, C\n");
    return 0;
}
#endif

int main()
{
    printf("Hello, C++\n");

    // C++에서는 main 함수안에서 return 0를 생략할 수 있습니다.
    // 컴파일러가 자동으로 return 0를 처리합니다.
}
#endif

// C++에서도 표준 입출력 라이브러리가 있습니다.
#include <iostream> // 표준 입출력 라이브러리 헤더 파일
                    // C++ 표준 라이브러리의 헤더 파일은 .h 라는 확장자가 없습니다.

int main()
{
    std::cout << "Hello, C++" << std::endl;
}