// 6_함수.cpp
#include <iostream>
using namespace std;

// * Default Parameter(파라미터 기본값)
// 정의: 전달되지 않은 함수의 인자를 파라미터 기본값으로 컴파일러가 자동으로 처리합니다.

// * 주의사항
// - 지정되지 않은 파라미터에 대해서, 컴파일러가 자동으로 전달해줍니다.
// - 파라미터 기본값은 마지막 파라미터부터 지정할 수 있습니다.
// - 파라미터 기본값은 선언부에 작성해야 합니다.

// int Add(int a, int b, int c = 0, int d = 0); // 함수 선언부
// => 라이브러리의 제작자가 헤더 파일을 통해 제공합니다.

#include "add.h"

#include "add.h"

int main()
{
    int result = 0;
    result = Add(10, 20, 30, 40);
    cout << result << endl;

    // result = Add(10, 20, 30, 0);
    result = Add(10, 20, 30);
    cout << result << endl;

    // result = Add(10, 20, 0, 0);
    result = Add(10, 20);
    cout << result << endl;
}