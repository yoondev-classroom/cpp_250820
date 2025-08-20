// 6_함수2.cpp
#include <iostream>
using namespace std;

#if 0
// C 언어는 동일한 이름의 함수를 여러개 제공할 수 없기 때문에,
// 타입에 따라서 다른 이름의 함수를 사용해야 합니다.
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }
long long squarell(long long x) { return x * x; }

int main()
{
    cout << squarei(3) << endl;
    cout << squared(3.14) << endl;
    cout << squarell(100000000LL) << endl;
}
#endif

// 함수 오버로딩
// - 함수의 이름은 동일하지만, 함수의 인자 정보(인자의 개수, 인자의 타입)가 다른 경우,
//   동일한 이름의 함수를 여러개 제공할 수 있습니다.

#if 0
int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

int main()
{
    cout << square(3) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000LL) << endl;
}
#endif

// 원리: 함수의 심볼을 결정할 때, 인자 정보가 포함됩니다.
void foo(int a, int b, int c) {} // __Z3fooiii
void foo(int a) {}               // __Z3fooi
void foo(int a, double b) {}     // __Z3fooid

int main()
{
}