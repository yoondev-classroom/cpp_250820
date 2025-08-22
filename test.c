// test.c
#include <stdio.h>
#if 0
void foo(void) {}
void goo() {} /* 안됩니다. */

int main(void)
{
    // foo(10); /* 컴파일 오류 */
    goo(10); /* 컴파일러가 오류를 찾지 못합니다. - 미정의 동작! */

    printf("Hello, C\n");
    return 0;
}
#endif

#if 0
// C의 문제점
// - const 타입에 초기화를 하지 않을 경우, 컴파일 오류가 발생하지 않습니다.
int main(void)
{
    const int c; /* 쓰레기값 */
    // c = 42; /* 컴파일 오류 */

    printf("%d\n", c);

    return 0;
}
#endif

#if 0
void foo(int a, int b, int c) {} // _foo
void goo(int a) {}               // _goo
void hoo(int a, double b) {}     // _hoo

int main(void)
{
}
#endif

int main(void)
{
    int n = 0;

    ++n;
    // 연산의 결과는 증가된 값

    printf("%d\n", n);
}