// 27_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

class Integer
{
    int value;

public:
    Integer(int n = 0) : value{n} {}

    Integer &operator++()
    {
        ++value;
        return *this; // Chaining: 자기 자신의 참조를 반환
    }

    friend ostream &operator<<(ostream &os, const Integer &v);
};

// 사용자 정의 타입을 표준 라이브러리를 통해 출력하는 방법
ostream &operator<<(ostream &os, const Integer &v)
{
    os << v.value;
    return os;
}

int main()
{
    int n1{10};
    ++ ++ ++n1;
    // ++n1 연산의 결과는 증가된 변수의 참조 입니다.
    cout << n1 << endl;

    Integer n2{10}; // 초기화하지 않으면, 자동으로 0이 됩니다.

    ++ ++ ++n2;
    // n2.operator++().operator++().operator++()
    cout << n2 << endl;
    // cout.operator<<(n2);
    //  => 멤버 함수로 연산자 오버로딩을 제공할 수 없습니다.

    // operator<<(cout, n2).operator(endl)
    //  => 사용자 정의 타입을 cout을 통해 출력하기 위해서는
    //     일반 함수 연산자 오버로딩을 제공해야 합니다.
}