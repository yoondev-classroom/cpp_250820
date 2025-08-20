// 6_함수7.cpp
#include <iostream>
using namespace std;

// 아래 함수가 실수 타입이 전달되는 경우, 컴파일 오류가 발생하도록 하고 싶습니다.
// => 실수 타입에 대해서 금지하고 싶습니다.
int gcd(int n)
{
    // 최대 공약수를 구하는 함수입니다.
    return 0;
}

// 방법 1. 선언만 합니다. => 링크 오류가 발생합니다.
//   : 의도를 전달하기 어렵습니다.
// double gcd(double n);
/*
Undefined symbols for architecture arm64:
  "gcd(double)", referenced from:
      _main in 6_함수7-cc4c3a.o
ld: symbol(s) not found for architecture arm64
*/

// 방법 2. C++11, delete function
double gcd(double n) = delete;

int main()
{
    cout << gcd(100) << endl;

    // 허용: C++에서는 실수 타입이 정수 타입으로의 암묵적인 변환이 허용됩니다.
    // cout << gcd(3.14) << endl;

    /*
    6_함수7.cpp:31:13: error: call to deleted function 'gcd'
   31 |     cout << gcd(3.14) << endl;
      |             ^~~
    */
}