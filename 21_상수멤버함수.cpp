// 21_상수멤버함수.cpp
#include <iostream>
#include <string>
using namespace std;

// C++에서 객체의 상태를 변경하지 않는 모든 멤버 함수는
// 반드시 "상수 멤버 함수"로 만들어야 합니다.

class User
{
    string name;
    int age;

public:
    User(const string &s, int n)
        : name{s}, age{n}
    {
    }

    // 상수 멤버 함수: 멤버 함수에서 내부의 상태를 변경할 수 없습니다.
    // => 원리: 상수 멤버 함수 안에서는 this를 const* 취급합니다.
    // => const*는 *를 통해서 값을 변경할 수 없습니다.
    void Print() const
    {
        // name = "Bob"; // !!!
        // this->name = "Bob";

        cout << name << ", " << age << endl;
    }
    // Swift, Kotlin, Rust 등의 언어는 멤버 함수를 만들면, 기본이 상수 멤버 함수입니다.
};

// const&는 레퍼런스를 통해 객체의 상태를 변경할 수 없습니다.
// => const& / const* 를 통해서는 상수 멤버 함수만 호출할 수 있습니다.
void Print(const User &user)
{
    user.Print();
}

int main()
{
    User user{"Tom", 42};

    Print(user);
}