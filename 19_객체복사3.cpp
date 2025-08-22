// 19_객체복사3.cpp
#include <iostream>
using namespace std;

// * 복사 정책
//   2) 참조 계수(Reference Counting)
//    => 객체 지향 언어에서 가장 보편적으로 사용하는 객체의 복사 정책입니다.

class User
{
    char *name;
    int age;

    int *ref;

public:
    User(const User &rhs)
        : name{rhs.name}, age{rhs.age}, ref{rhs.ref}
    {
        // 핵심: 참조 계수 증가!!
        ++(*ref);
    }

    User &operator=(const User &rhs)
    {
        if (--(*ref) == 0)
        {
            delete[] name;
            delete ref;
        }

        name = rhs.name;
        age = rhs.age;
        ref = rhs.ref;
        ++(*ref);

        return *this;
    }

    User(const char *s, int n)
        : age{n}
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int{1}; // !!!
    }

    ~User()
    {
        // 참조 계수 감소!
        --(*ref);

        // 참조 계수가 0이면, 자원을 정리합니다.
        if (*ref == 0)
        {
            delete[] name;
            delete ref;
        }
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