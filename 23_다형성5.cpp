// 23_다형성5.cpp
#include <iostream>
using namespace std;

// 1) 자식이 재정의하는 부모의 멤버 함수가 가상 함수이면,
//    자식의 멤버 함수도 가상함수입니다.

// 2) 부모가 제공하는 멤버 함수가 가상 함수가 아니면,
//    오버라이딩 하면 안됩니다.

// 3) 부모의 멤버 함수를 오버라이딩을 잘못하는 경우를
//    확인할 수 없습니다.

// => 해결방법, C++11: override
//  - 부모가 제공하는 멤버 함수가 가상 함수가 아니면 컴파일 오류 발생!
//  - 부모가 제공하지 않는 멤버 함수에 대해서 컴파일 오류가 발생!
//  => 반드시 사용해야 합니다.

class Animal
{
public:
    virtual void Cry() const { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
public:
    // virtual void Cry() const {}
    // virtual void Cry() const override { cout << "Dog Cry" << endl; }
    void Cry() const override { cout << "Dog Cry" << endl; }
};

int main()
{
}