// 25_추상클래스.cpp
#include <iostream>
using namespace std;

// 1) Shape는 객체를 생성하지 않습니다.
// 2) Shape::Draw는 호출되지 않습니다.
// 3) Shape를 상속받는 자식 클래스는 반드시 Draw를 재정의 해야 합니다.

// 순수 가상 함수를 1개 이상 가진 클래스는 객체를 생성할 수 없습니다.
//  => 추상 클래스(Abstract class)
//  : C++은 다른 언어와 달리, 추상 클래스를 만드는 별도의 문법이 존재하지 않습니다.
//       abstract class Shape {}

class Shape
{
public:
    virtual ~Shape() {}

    // 자식 클래스가 반드시 재정의해야하고, 부모는 객체를 생성하지도 않고, 부모의 메소드는 호출되지도 않는다면
    // => 순수 가상 함수(Pure Virtual Function)
    virtual void Draw() const = 0;
};

// 자식 클래스는 부모가 제공하는 순수 가상 함수를 반드시 재정의해야 합니다.
// 재정의하지 않는다면, 자식 클래스도 추상 클래스가 됩니다.
class Rect : public Shape
{
public:
    void Draw() const override { cout << "Rect Draw" << endl; }
};

int main()
{
    // Shape s;
    // - 순수 가상 함수를 가졌으므로(추상 클래스), 객체를 생성할 수 없습니다.

    Rect r;
    r.Draw();

    Shape *p = &r;
    p->Draw();
}