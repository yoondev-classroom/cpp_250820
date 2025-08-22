// 22_상속2.cpp
#include <iostream>
using namespace std;

// 1. private: 외부에서 접근이 불가능합니다.
//             자식 클래스도 접근이 불가능합니다.
//             friend 선언된 함수 또는 클래스는 접근이 가능합니다.

// 2. protected: 외부에서 접근이 불가능합니다.
//               자식 클래스는 접근이 가능합니다.

// 3. public: 외부에서 접근이 가능합니다.

#if 0
class Animal
{
protected:
    int age = 42;
};

class Dog : public Animal
{
public:
    void PrintAge() const
    {
        cout << age << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();
}
#endif

// 클래스를 설계할 때, 자식에게 내부의 상태를 담당하는 멤버 데이터를 공개하는 행위는
// 이후에 유지보수에 어려움을 줄 수 있습니다.
class Animal
{
private:
    int age = 42;

protected:
    int GetAge() const { return age; }
};

class Dog : public Animal
{
public:
    void PrintAge() const
    {
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();
}