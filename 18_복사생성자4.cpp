// 18_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// C++23 이전에는 컴파일 오류가 발생하지 않습니다.
// 지역 객체의 메모리에 대한 참조를 반환하는 것은, 미정의 동작이 발생합니다.
// => 지역 객체를 함수에서 반환할 때는 값으로 반환해야 합니다.
//  : C++ 컴파일러는 지역 객체를 값으로 반환할 때, 임시 객체를 생성해서 반환하지 않고,
//    자동으로 최적화해줍니다.
//     - RVO(Return Value Optimization)
Sample foo()
{
    Sample s;

    return s;
}

int main()
{
    foo();
}