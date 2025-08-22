// 27_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

#if 0
namespace xstd
{
    class ostream
    {
    public:
        void operator<<(const char *str)
        {
            printf("%s", str);
        }

        void operator<<(int n)
        {
            printf("%d", n);
        }
    };

    ostream cout;
}

int main()
{
    xstd::cout << "hello";
    // xstd::cout.operator<<("hello");

    int n = 42;
    xstd::cout << n;
}
#endif

namespace xstd
{
    class istream
    {
    public:
        void operator>>(int &n)
        {
            scanf("%d", &n);
        }

        void operator>>(double &n)
        {
            scanf("%lf", &n);
        }
    };

    istream cin;
}

int main()
{
    int n;
    xstd::cin >> n;
    // xstd::cin.operator>>(n)

    std::cout << n << std::endl;
}

// 1. std::cout -  표준 출력 객체
//    std::cin  -  표준 입력 객체
//       => 연산자 오버로딩을 통해 입출력을 사용하고 있었습니다.

// 2. std::cout / std::cin은 함수 오버로딩을 통해 제공하고 있습니다.
//    변수의 타입이 변경되어도, 입출력의 코드는 변경할 필요가 없습니다.

// 3. std::cin은 call by reference를 기반으로 변수의 값을 함수를 통해
//    변경하고 있습니다.
//    => 주소를 전달하지 않아도, 값을 변경할 수 있습니다.