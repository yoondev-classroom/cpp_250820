// 27_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

class Integer
{
    int value;

public:
    Integer(int n = 0) : value{n} {}

    // ++n
    Integer &operator++()
    {
        ++value;
        return *this; // Chaining: 자기 자신의 참조를 반환
    }

    // n++ => operator++(int) => 오버로딩이 불가능하기 때문에, 더미 인자가 있습니다.
    Integer operator++(int)
    {
        Integer temp{value};
        ++value;

        return temp;
        // 1) 값으로 반환 -> 임시 객체 복사 생성 비용 => RVO
        // 2) 현재 상태에 대한 객체 생성 비용
    }

    friend ostream &operator<<(ostream &os, const Integer &v);
};

// 사용자 정의 타입을 표준 라이브러리를 통해 출력하는 방법
ostream &operator<<(ostream &os, const Integer &v)
{
    os << v.value;
    return os;
}

// 연산자 재정의를 제공할 때
// => 기본 타입이 동작하는 방식과 유사하게 제공하는 것이 좋습니다.

#if 0
int main()
{
    int n1{10};
    // ++ ++ ++n1;
    ++n1;
    // ++n1 연산의 결과는 증가된 변수의 참조 입니다.

    n1++;
    // - 변경되기 이전의 값으로 평가됩니다.

    cout << n1 << endl;

    Integer n2{10}; // 초기화하지 않으면, 자동으로 0이 됩니다.

    // ++ ++ ++n2;
    ++n2;
    n2++;
    // n2.operator++().operator++().operator++()
    cout << n2 << endl;
    // cout.operator<<(n2);
    //  => 멤버 함수로 연산자 오버로딩을 제공할 수 없습니다.

    // operator<<(cout, n2).operator(endl)
    //  => 사용자 정의 타입을 cout을 통해 출력하기 위해서는
    //     일반 함수 연산자 오버로딩을 제공해야 합니다.
}
#endif

int main()
{
    int x = 10;
    ++x;
    /*
        mov     DWORD PTR x$[rsp], 10
        mov     eax, DWORD PTR x$[rsp]
        inc     eax
        mov     DWORD PTR x$[rsp], eax
    */

    Integer v{10};
    ++v;
    /*
        - 인라인 최적화 X
        mov     edx, 10
        lea     rcx, QWORD PTR v$[rsp]
        call    Integer::Integer(int)                    ; Integer::Integer
        lea     rcx, QWORD PTR v$[rsp]
        call    Integer & Integer::operator++(void)                ; Integer::operator++
    */
    /*
         - 인라인 최적화 O
         mov     DWORD PTR v$[rsp], 10
         mov     eax, DWORD PTR v$[rsp]
         inc     eax
         mov     DWORD PTR v$[rsp], eax
    */
}

/*
// C Style
for (int i = 0 ; i < n; i++)
{
}

// C++ Style
//  : C++에서는 전위 연산이 후위 연산보다 빠른 경우(객체의 경우)가 있기 때문에,
//    루프에서 ++을 전위로 사용합니다.
for (int i = 0 ; i < n; ++i)
{
}


*/