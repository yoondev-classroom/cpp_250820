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

// std::cout: 표준 출력

#if 0
int main()
{
    std::cout << "Hello, C++" << std::endl;

    int n = 42;
    std::cout << n << std::endl;
}
#endif

#if 0
int main()
{
    // C - printf/scanf
    double n1;
    scanf("%lf", &n1);
    printf("%lf\n", n1);
    // 문제점: 변수의 타입이 변경되면, 서식도 변경되어야 합니다.

    // C++ - std::cout/std::cin
    // -> 변수의 타입을 기반으로 입출력이 수행됩니다.
    //    변수의 타입을 변경하여도, 기존 std::cout / std::cin에 대한 코드를
    //    변경할 필요가 없습니다.
    double n2;
    std::cin >> n2;
    std::cout << n2 << std::endl;
}
#endif

#if 0
int main()
{
    // C - printf/scanf
    double n1;
    scanf("%lf", &n1);
    printf("n=%lf\n", n1);

    // C++ - std::cout/std::cin
    double n2;
    std::cin >> n2;
    std::cout << "n=" << n2 << std::endl;
    // 출력의 결과를 조합하는데 어려움이 있습니다.
}
#endif

// C++23 - 새로운 출력 함수가 도입되었습니다.
#include <print>
// g++ 1_시작2.cpp -std=c++23

int main()
{
    double n = 3.14;

    std::print("n={}", n);
    std::println("n={}", n);
}
