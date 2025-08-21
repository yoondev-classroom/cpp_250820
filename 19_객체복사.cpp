// 19_객체복사.cpp
#include <iostream>
using namespace std;

// 클래스 내부에 포인터 멤버가 존재하는 경우,
// 컴파일러가 제공하는 복사 생성자를 사용할 경우,
// 동일한 자원을 공유해서, 두번 이상 파괴되는 문제가 발생합니다.
//  => 얕은 복사(Shallow Copy) 문제

// * 해결방법: 반드시 복사 생성자를 직접 제공해서,
//           문제를 해결해야 합니다.
// * 복사 정책
//   1) 깊은 복사
//   2) 참조 계수
//   3) 복사 금지

class User
{
    char *name;
    int age;

public:
    // 컴파일러가 만들어주는 복사 생성자
    User(const User &rhs)
        : name{rhs.name}, age{rhs.age}
    {
    }

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