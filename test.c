// test.c

#include <stdio.h>

void foo(void) {}
void goo() {} /* 안됩니다. */

int main(void)
{
    // foo(10); /* 컴파일 오류 */
    goo(10); /* 컴파일러가 오류를 찾지 못합니다. - 미정의 동작! */

    printf("Hello, C\n");
    return 0;
}