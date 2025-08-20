// 3_변수6.cpp
#include <iostream>
using namespace std;

// C/C++에는 기존 타입의 별칭을 제공할 수 있는 문법이 있습니다.
// - typedef
// - 변수를 만들 듯이 타입의 별칭을 만들 수 있습니다.

#if 0
int main()
{
    typedef int WEIGHT_TYPE;
    // int = WEIGHT_TYPE

    int n1;
    WEIGHT_TYPE n2;

    typedef int ARR_TYPE[3];
    // int[3] = ARR_TYPE

    ARR_TYPE x;
    x[0] = 10;
    x[1] = 20;

    cout << x[1] << endl;
}
#endif

// C++11 이후에는 타입의 별칭을 지정하는 새로운 문법이 도입되었습니다.
//  - using
//     * namespace
//         1. using 선언
//         2. using 지시어
//     * Type aliasing : C++11
int main()
{
    // typedef int WEIGHT_TYPE;
    using WEIGHT_TYPE = int;

    // typedef int ARR_TYPE[3];
    using ARR_TYPE = int[3];

    ARR_TYPE x;
    x[0] = 10;
    x[1] = 20;

    cout << x[1] << endl;
}
