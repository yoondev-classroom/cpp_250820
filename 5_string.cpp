// 5_string.cpp
#include <iostream>
using namespace std;

// 1. C 문자열: '\0' 문자로 종료되는 char 배열
// 2. C 문자열 문제점
//   1) 널 문자로 종료되어야 합니다.
//      - 누락될 경우, 미정의 동작의 원인이 됩니다.
//   2) 문자열 연산을 수행할 때, 별도의 라이브러리 함수를 사용해야 합니다.
//      - 메모리 관리를 개발자가 직접 해야 합니다.
//      - 미정의 동작의 원인이 됩니다.

#if 0
#include <cstring> // string.h

int main()
{
    // char str[5] = {'h', 'e', 'l', 'l', 'o'};
    char str1[] = "hello";
    printf("%s\n", str1);

    char str2[] = "hello";

    if (strcmp(str1, str2) == 0)
    {
        cout << "같음" << endl;
    }

    char str3[10];
    strcpy(str3, str2); // 문자열 복사
    cout << str3 << endl;

    char str4[20];
    strcpy(str4, str3);
    strcat(str4, str3); // 문자열 연결
    cout << str4 << endl;
}
#endif

// C++의 문자열 타입
//  - std::string
//  1) 문자열 연산을 별도의 함수가 아니라, 연산자를 통해서 직관적으로 수행할 수 있습니다.
//  2) 메모리 관리를 라이브러리가 자동적으로 수행합니다.
//  => SSO(Simple String Optimization)
//   - 짧은 문자열은 스택을 통해 빠르게 처리하고, 긴문자열은 동적 할당을 통해 처리합니다.

int main()
{
    std::string s1 = "hello";
    std::string s2{"hello"};

    cout << s1 << endl;
    cout << s2 << endl;

    if (s1 == s2)
    {
        cout << "같음" << endl;
    }

    std::string s3 = {s2};
    std::string s4 = {s2 + s3};

    cout << s3 << endl;
    cout << s4 << endl;
}