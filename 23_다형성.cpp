// 23_다형성.cpp
#include <iostream>
using namespace std;

class Animal
{
    int age;
};

// * 객체 지향 설계에서 말하는 상속은 C++에서의 public 상속 입니다.
// * 상속은 is-a 관계에서 사용합니다.
//    <자식 클래스> is a(n) <부모 클래스>
class Dog : public Animal
{
};

int main()
{
    Animal a;
    Dog d;

    Animal *pa = &a;
    Animal &ra = a;

    Animal *p = &d; /* OK */
    Animal &r = d;  /* OK */
    // Upcasting
    //  : 자식 객체는 부모 포인터/참조 타입으로의 암묵적인 변환이 허용됩니다.

    // Downcasting은 암묵적인 변환이 허용되지 않습니다.
    // Dog *pd = &a;
    // Dog &rd = a;
}