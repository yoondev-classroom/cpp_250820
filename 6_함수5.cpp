// 6_함수5.cpp
#include <iostream>
using namespace std;

// 함수의 인자와 반환 타입만 다르고, 함수의 구현(알고리즘)은 동일합니다.
// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

// => 함수 템플릿(Template)
// 정의: 컴파일 타임에 코드를 생성하는 기술
template <typename TYPE>
TYPE square(TYPE x) { return x * x; }

// C++의 템플릿과 유사한 기능들이 다른 언어에도 제공되고 있습니다.
// => Generic
// => 각 언어와 플랫폼마다 다른 방식으로 구현되어 있습니다.

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

// - C++ 템플릿은 컴파일 타임에 필요한 타입만큼 코드를 생성해야 하기 때문에,
//   코드 블로우트 현상이 발생할 수 있습니다.
//   인라인 최적화가 가능하다면, 해당 문제를 해결할 수 있습니다.

int main()
{
    cout << square(10) << endl;        // TYPE -> int
    cout << square(3.14) << endl;      // TYPE -> double
    cout << square(1000000LL) << endl; // TYPE -> long long
}