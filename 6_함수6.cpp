// 6_함수6.cpp
#include <iostream>
using namespace std;

template <typename TYPE>
TYPE square(TYPE x) { return x * x; }

// int square(int x) { return x * x; } ; square<int>
// double square(double x) { return x * x; } ; square<double>

#if 0
int main()
{
    square(10); // 10의 타입은 int 입니다.
                //   TYPE -> int 로 결정해서 코드를 생성합니다.
                // : 암묵적인 타입 추론

    square(3.14); // TYPE -> double
                  // : 암묵적인 타입 추론

    short s = 100;
    square<int>(s); // 명시적으로 템플릿 타입 인자를 지정할 수 있습니다.
                    // : 명시적인 타입 지정
}
#endif

template <typename T1, typename T2>
void foo(T1 a, T2 b) {}

int main()
{
    // => 암묵적인 타입 추론
    foo(42, 3.14);
    // T1 -> int
    // T2 -> double

    // => 명시적인 타입 지정
    foo<long, float>(42, 3.14);
    //               ---------
    //                 -> 값 전달(Value parameter)

    foo<long, float>(42, 3.14);
    // -------------
    //   -> 타입 전달(Type parameter)
}
