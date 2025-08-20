// 2_namespace3.cpp
#include <iostream>
// C++ 표준 라이브러리 헤더파일은 확장자를 사용하지 않습니다.

#if 0
#include <stdio.h>

int main()
{
    printf("Hello, C++\n");
}
#endif

// * 문제점
// 1) printf를 전역 공간에서 사용하고 있습니다.
// 2) stdio.h -> 확장자가 존재합니다.

// C++에서는 C의 헤더파일을 사용할 때, 확장자 없는 형태로 사용할 수 있습니다.
//   stdio.h   => cstdio
//   stdlib.h  => cstdlib
//   string.h  => cstring
//    ...

#include <cstdio>

int main()
{
    std::printf("Hello, C++\n");
    // C의 모든 함수를 std 이름 공간안에서 사용할 수 있습니다.
}