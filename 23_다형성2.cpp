// 23_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog
{
    int age;
    // ...

public:
    int GetAge() const { return age; }
};

class Cat
{
    int age;
    // ...

public:
    int GetAge() const { return age; }
};

void PrintAge(const Dog &d)
{
    cout << d.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

class Animal
{
    int age;

public:
    int GetAge() const { return age; }
};

class Dog : public Animal
{
};

class Cat : public Animal
{
};

// 활용 1. 동종을 처리하는 함수를 만들 수 있습니다.
// => Animal의 자식 클래스는 아래 함수를 이용할 수 있습니다.
void PrintAge(const Animal &d)
{
    cout << d.GetAge() << endl;
}

void PrintAge(const Animal *p)
{
    cout << p->GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);
    PrintAge(&d);

    Cat c;
    PrintAge(c);
    PrintAge(&c);
}