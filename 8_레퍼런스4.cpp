// 8_레퍼런스4.cpp
#include <iostream>
#include <string>
using namespace std;

struct User
{
    string name;
    int age;

    string address;

    char data[1024];
};

#if 0
void SetAddress(User user, std::string address)
{
    user.address = address;
}
#endif

#if 0
void SetAddress(User *user, std::string address)
{
    if (user) // user가 유효한지 체크해야 합니다.
    {
        // (*user).address = address;
        user->address = address;
        // 포인터 멤버 접근 연산자.
    }
}
#endif

void SetAddress(User &user, const std::string &address)
{
    user.address = address;
}

// 사용자 정의 타입에 대해서, 함수를 통해 값을 읽는 경우에도 포인터 또는 레퍼런스를 이용해야 합니다.
//  => const T& / const T*
void PrintUser(const User &user)
{
    // user.name = "Bob"; - 허용되지 않습니다.

    cout << user.name << ", " << user.age << ", " << user.address;
}

int main()
{
    cout << sizeof(User) << endl;

    User user;
    user.name = "Tom";
    user.age = 42;
    user.address = "Seoul";

    SetAddress(user, "Suwon");

    PrintUser(user);
    // 사용자 정의 타입의 크기가 커질 수록, Call by value의 성능이 떨어집니다.
}