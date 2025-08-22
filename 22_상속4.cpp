// 22_상속4.cpp
#include <iostream>
using namespace std;

// 초기화리스트를 반드시 제공해야 하는 4가지 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자가 없는 멤버 객체
// 4) 기본 생성자가 없는 부모

#if 0
class Animal
{
    int age;

public:
    Animal(int n) : age{n} {}
};

class Dog : public Animal
{
public:
    // Dog() : Animal{} {}
    // Dog() : Animal{1} {}

    // 자식 클래스는 부모 클래스의 생성자에 필요한 인자를
    // 전달해야 하는 책임이 있습니다.
    Dog(int n) : Animal{n} {}
};

int main()
{
    Dog d{42};
}
#endif

#include <string>

class Animal
{
    int age;

public:
    Animal(int n) : age{n} {}
};

class Dog : public Animal
{
    string name;

public:
    Dog(int age, const string &s) : Animal{age}, name{s} {}
};

int main()
{
}