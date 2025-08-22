// 19_객체복사2.cpp
#include <iostream>
using namespace std;

// * 복사 정책
//   1) 깊은 복사

class User
{
    char *name;
    int age;

public:
    // 깊은 복사 정책을 구현한 복사 생성자
    //----
    User(const User &rhs)
        : age{rhs.age}
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    User &operator=(const User &rhs)
    {
        // 대입 연산자는 이미 소유한 자원이 존재하는 경우,
        // 정리가 필요합니다.
        if (name)
        {
            delete[] name;
        }

        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        age = rhs.age;

        return *this;
    }

    //-----

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
    User other{user}; // User(const User&)

    user.Print();
    other.Print();
}

/*
// 미정의 동작
a.out(49379,0x1fdfa20c0) malloc: Double free of object 0x12de05fa0
a.out(49379,0x1fdfa20c0) malloc: *** set a breakpoint in malloc_error_break to debug
zsh: abort      "/Users/ourguide/Desktop/cpp_250820/"./a.out
*/