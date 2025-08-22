// 22_상속.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class Animal
{
    int age;

public:
    int GetAge() const { return age; }
};

class Dog
{
    int age;
    int color;

public:
    int GetAge() const { return age; }
};

class Cat
{
    int age;
    string name;

public:
    int GetAge() const { return age; }
};

int main()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;
}
#endif

// 상속: 클래스의 공통의 기능을 부모 클래스로 캡슐화할 수 있습니다.

// 부모 클래스 / Super / Base
class Animal
{
    int age;

public:
    int GetAge() const { return age; }
};

// 자식 클래스 / Sub / Derived
// : 객체 지향 설계에서 의미하는 "상속"은 C++에서 public 상속만 해당합니다.
//   - C++의 private "상속"은 객체 지향 설계의 "상속"과 다릅니다.
class Dog : public Animal // 상속
{
    int color;
};

class Cat : public Animal
{
    string name;
};

int main()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;

    Dog d;
    d.GetAge(); // 부모로부터 age 상태와 GetAge 함수를 물려 받습니다.
}