// 19_객체복사4.cpp
#include <iostream>
using namespace std;

// * 복사 정책
//   3) 복사 금지

class User
{
    char *name;
    int age;

public:
    User(const User &rhs) = delete;
    // 복사 금지!!! - C++11, Delete Function

    User(const char *s, int n)
        : age{n}
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user{"Tom", 42};
    // User other{user}; // User(const User&) // !! 컴파일 오류!!!

    user.Print();
}
