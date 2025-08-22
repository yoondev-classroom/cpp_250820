// 23_다형성4.cpp
#include <iostream>
using namespace std;

// * 오버라이딩(Overriding)
// 정의: 부모 클래스가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.

// * 바인딩(Binding)
//  : p->Cry / p.Cry()를 호출할 때, 어떤 클래스의 멤버 함수를 호출할지 결정하는 것
// 1) 정적 바인딩(static binding)
//  : 어떤 클래스의 멤버 함수를 호출할지, 컴파일 시간에 컴파일러가 결정합니다. => 인라인 최적화
//    p->Cry()
//     = p의 타입을 보고 결정합니다.

// 2) 동적 바인딩(dynamic binding)
//  : 어떤 클래스의 멤버 함수가 호출될지, 컴파일러가 실행 시간에 조사해서 호출하는 코드를 삽입합니다.
//    p->Cry()
//     = p가 현재 가르키는 객체의 타입을 조사해서, 호출합니다.

// 가상 함수
//  : 동적 바인딩 기반으로 함수가 호출됩니다.

class Animal
{
public:
    virtual void Cry() const { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
public:
    virtual void Cry() const { cout << "Dog Cry" << endl; }
};

// 상속 관계에서 Upcasting을 활용하기 위해서는
// 반드시 자식이 재정의(Overriding)하는 함수가 가상함수이어야 합니다.
int main()
{
    Animal a;
    Dog d;

    Animal *p1 = &a;
    Animal &r1 = a;
    p1->Cry();
    r1.Cry();

    Animal *p2 = &d;
    Animal &r2 = d;
    p2->Cry();
    r2.Cry();
}

#if 0
int main()
{
    Animal a;
    Dog d;

    a.Cry();
    d.Cry();
}
#endif