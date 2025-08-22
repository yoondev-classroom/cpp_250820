// 23_다형성6.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal() { cout << "Animal()" << endl; }

    // 부모의 소멸자는 반드시 가상이어야 합니다.
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal
{
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
    // 자식의 소멸자에 override 키워드를 사용하였을 때, 부모의 소멸자가 가상이 아니면
    // 컴파일 오류가 발생합니다.
};

/*
* 문제
- 부모의 포인터를 통해 관리되는 객체의 소멸자가 호출되었을 때,(delete)
  자식의 소멸자가 호출되지 않는 문제가 발생하고 있습니다.
Animal()
Dog()
~Animal()
*/

class User final // 상속 금지
{
};
// class Admin : public User /* 컴파일 오류! */
// {
// };

class Shape
{
public:
    virtual void Draw() const final {} // 반드시 이 함수를 사용해야 합니다.
};
class Rect : public Shape
{
public:
    // void Draw() const override {}
    // : final로 지정된 메소드는 오버라이딩할 수 없습니다.
};

int main()
{
    Animal *p = new Dog;

    delete p;
    // 원인: 소멸자의 호출도 정적 바인딩 기반으로 결정되기 때문입니다.
    // 해결방법: 소멸자도 가상으로 만들어야 합니다.
}

// * 클래스를 설계할 때, 상속을 고려해서 설계하지 않았다면,
//   해당 클래스를 상속할 수 없도록 해줘야 합니다.
//  => C++11: final