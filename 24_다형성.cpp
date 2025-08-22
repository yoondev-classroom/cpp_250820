// 24_다형성.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1) 각 도형의 클래스를 설계합니다.
#if 0
class Rect
{
public:
    void Draw() const { cout << "Rect Draw" << endl; }
};

class Circle
{
public:
    void Draw() const { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Rect *> rects;
    vector<Circle *> circles;
}
#endif

// 2) 부모 클래스 도입 => 동종을 보관하는 컨테이너
// 3) 자식의 공통의 기능을 부모의 포인터/참조를 통해 이용하기 위해서는
//    반드시 해당 특징이 부모 클래스로부터 비롯되어야 한다.
//    => LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//       - 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//       "자식의 공통의 기능은 반드시 부모로부터 비롯되어야 한다."

// 4) 자식이 재정의하는 모든 멤버 함수는 반드시 가상함수이어야 합니다.
// 5) 부모 클래스의 소멸자는 반드시 가상이어야 합니다.
class Shape
{
public:
    virtual ~Shape() {} // !!!

    virtual void Draw() const { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
    void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape
{
public:
    void Draw() const override { cout << "Circle Draw" << endl; }
};

class Triangle : public Shape
{
public:
    void Draw() const override { cout << "Triangle Draw" << endl; }
};

int main()
{
    vector<Shape *> shapes;

    while (1)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            shapes.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            shapes.push_back(new Circle);
        }
        else if (cmd == 3)
        {
            shapes.push_back(new Triangle);
        }
        else if (cmd == 9)
        {
            for (Shape *e : shapes)
            {
                e->Draw();
                // e is Rect     -> Rect::Draw
                //   is Circle   -> Circle::Draw
                //   is Triangle -> Triangle::Draw
                // => 다형성은 "OCP"를 만족합니다.
                //    OCP(Open Close Principle, 개방 폐쇄 원칙)
                //     : 확장에는 열려 있어야 하고, 수정에는 닫혀 있어야 한다.
                //       => 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.
            }
        }
        else
        {
            break;
        }
    }

    for (auto e : shapes)
    {
        delete e;
    }
}

// 상속의 목적은 "재사용"이 아니라,
// 상속의 목적은 "다형성" 입니다.