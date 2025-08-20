// 6_함수4.cpp
#include <iostream>

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 기계어로 호출부를 치환합니다.
//    매크로 함수와 같은 미정의 동작이 발생하지 않고,
//    함수 호출의 오버헤드도 최적화할 수 있습니다.
// => C99 표준에서 inline 함수가 도입되었습니다.
//    C 언어에서도 매크로 함수를 통해 함수 호출 오버헤드를 최적화하는 것이 아니라,
//    inline 함수를 사용하는 것이 안전합니다.

// 참고
// 1) 인라인 최적화는 컴파일 최적화 명령입니다.
// 2) 인라인 최적화는 무조건 수행되는 것이 아니라, 컴파일러가 판단합니다.
//    GCC: -O1, -O2, -O3
//   MSVC: /Ob1 /Ob2

// 문제점
// - 인라인 함수로 최적화할 경우, 함수의 구현이 복잡한 경우, 전체적인 코드 메모리의 사용량이 증가할 수 있습니다.
// => 최신 컴파일러는 인라인 함수라고 하더라도, 코드가 복잡한 경우, 인라인 최적화를 수행하지 않습니다.
// - 간결한 함수에 대해서 인라인 최적화를 하는 것이 일반적입니다.

#if 0
int square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;
    int result = square(++x); // 121
    // 인라인 최적화가 수행되지 않은 경우
    /*
        mov     DWORD PTR x$[rsp], eax
        mov     ecx, DWORD PTR x$[rsp]
        call    int square(int)
    */

    // 인라인 최적화가 수행된 경우
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
    */

    printf("%d\n", result);
}
#endif

#if 0
void foo() 
{
    /*
        ...
        ...
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR $T1[rsp], eax
        
        ret
    */
}

int main()
{
    foo();
    // call foo;
    foo();
    // call foo;
    foo();
    // call foo;
    foo();
    // call foo;
    foo();
    // call foo;
}
#endif
