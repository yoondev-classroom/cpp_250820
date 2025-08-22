// 22_상속3.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal() { cout << "Animal()" << endl; }
    ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal
{
public:
    // Dog() { cout << "Dog()" << endl; }

    // 컴파일러가 부모의 기본 생성자를 호출하는 코드를
    // 생성자의 초기화리스트에 추가합니다.
    Dog() : Animal{}
    {
        cout << "Dog()" << endl;
    }

    ~Dog()
    {
        cout << "~Dog()" << endl;

        // 자식의 소멸자의 마지막에 부모의 소멸자를 호출하는 코드를
        // 컴파일러가 자동으로 처리합니다.
        // Animal::~Animal()
    }
};

/*
Animal()
Dog()
~Dog()
~Animal()
*/

int main()
{
    Dog d;
    // Dog::Dog() 호출

} // Dog::~Dog() 호출