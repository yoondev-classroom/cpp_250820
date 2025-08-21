// 13_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. class의 기본 접근지정자는 private 입니다.
//   struct의 기본 접근지정자는 public 입니다.

// 2. public: 외부에서 접근이 가능합니다.
//    private: 외부에서 접근이 불가능합니다.
//             friend 선언되어 있는 함수 또는 클래스는 접근할 수 있습니다.

class User
{
    string name;
    int age;

public:
    // 1. Getter
    // string GetName() { return name; }
    // int GetAge() { return age; }

    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // 2. friend
    // => 캡슐화의 정책을 깨뜨리는 것이 아니라, 캡슐화의 정책을 깨뜨리지 않고, 경계를 확장할 수 있습니다.
    friend void PrintUser(User user);
    friend class UserPrinter;
    // C++에서 friend 선언되어 있는 함수는 private 멤버에 접근할 수 있습니다.
};

class UserPrinter
{
public:
    void PrintUser(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

void PrintUser(User user)
{
    // cout << user.GetName() << ", " << user.GetAge() << endl;
    cout << user.name << ", " << user.age << endl;
}
//---

int main()
{
    User user{"Tom", 42};
    PrintUser(user);

    UserPrinter printer;
    printer.PrintUser(user);
}

// 단위 테스트(Unit Test)
// => 개발자가 직접 자신이 제작한 모듈을 검증해야 하는 책임이 있습니다.