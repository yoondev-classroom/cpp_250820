// 26_접근변경자.cpp
#include <iostream>
using namespace std;

class Base
{
public:
    int a;

protected:
    int b;

private:
    int c;
};

// 1. 부모의 private은 자식 클래스에서 접근할 수 없습니다.
//  class Derived : public Base
//     부모(Base)      자식(Derived)
//      - public      =>    public
//      - protected   =>    protected
//      - private     =>    X

//  class Derived : protected Base
//     부모(Base)      자식(Derived)
//      - public      =>    protected
//      - protected   =>    protected
//      - private     =>    X

//  class Derived : private Base
//     부모(Base)      자식(Derived)
//      - public      =>    private
//      - protected   =>    private
//      - private     =>    X

class Derived : private Base
{
};

// 2. 상속 - public 상속(is-a)입니다.
//     "다형성" => Upcasting

int main()
{
    // Derived d;
    // d.a = 10;
    // d.b = 20;

    // Derived d;
    // Base *p = &d; // 오류: public 상속만 Upcasting이 허용됩니다.
    // Base &r = d;
}