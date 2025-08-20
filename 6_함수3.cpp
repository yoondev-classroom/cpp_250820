// 6_함수3.cpp
// #include <iostream>
// using namespace std;
#include <cstdio>
using namespace std;

#if 0
int square(int x)
{
    return x * x;
}
/*
square(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi   ; x = edi
        mov     eax, DWORD PTR [rbp-4]   ; eax = x
        imul    eax, eax                 ; eax = eax * eax
        pop     rbp
        ret ; 저장된 복귀 주소로 복귀합니다.

*/

// 함수는 호출의 오버헤드가 있습니다.
int main()
{
    int result = square(10);
    printf("%d\n", result);
    /*
        mov     edi, 10              ; edi = 10
        call    square(int)          ; 복귀 주소를 저장하고, square 함수로 점프합니다.
        mov     DWORD PTR [rbp-4], eax ; result = eax;
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
    */
}
#endif

// 함수를 사용하는 이유
// => 재사용(모듈화) - 유지보수

// C - 매크로 함수
#define SQUARE(x) ((x) * (x))
// - 전처리기 의해서 컴파일 이전에 텍스트 치환됩니다.
// - 매크로 함수와 ++, -- 연산을 함께 사용할 경우, 미정의 동작이 발생합니다.

int main()
{
    // int result = 10 * 10;
    int x = 10;

    int result = SQUARE(++x);
    // int result = ((++x) * (++x)); // 미정의 동작

    printf("%d\n", result);
}

/*
// 전처리 결과
int main()
{

    int x = 10;

    int result = ((x) * (x));
    printf("%d\n", result);
}

*/