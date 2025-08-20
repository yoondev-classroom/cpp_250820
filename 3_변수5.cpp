// 3_변수5.cpp
#include <iostream>
using namespace std;

int main()
{
    // auto는 우항의 타입을 통해 타입이 결정(추론)됩니다.
    // => 항상 동일한 타입으로 결정되는 것은 아닙니다.

    int n = 10;

    // n과 동일한 타입의 변수를 만들고 싶습니다.
    // => C++11에서 주어진 표현식의 타입을 구하는 연산자가 추가되었습니다.
    //    decltype
    // decltype(n) => int

    decltype(n) n2; // int n2;
}

#if 0
int main()
{
    // int n = {10};
    long n{10};

    printf("%zu\n", sizeof(n));
    // printf("%zu\n", 8);

    printf("%zu\n", sizeof(int));
    // printf("%zu\n", 4);
}
#endif