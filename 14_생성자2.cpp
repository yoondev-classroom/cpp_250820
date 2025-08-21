// 14_생성자2.cpp
#include <iostream>
using namespace std;

class Object
{
public:
    Object() { cout << "Object()" << endl; }
    ~Object() { cout << "~Object()" << endl; }
};

// 1. malloc을 통해 객체를 생성하면, 생성자가 호출되지 않습니다.
// 2. free를 통해 객체를 해지하면, 소멸자가 호출되지 않습니다.

// 3. 객체를 new를 통해 생성하면, 생성자가 호출됩니다.
// 4. 객체를 delete를 통해 파괴하면, 소멸자가 호출됩니다.

// new 연산
// 1) 메모리 할당
// 2) 생성자 호출

// delete 연산
// 1) 소멸자 호출
// 2) 메모리 해지

#if 0
int main()
{
    // Object *p1 = static_cast<Object *>(malloc(sizeof(Object)));
    // free(p1);

    Object *p2 = new Object;
    delete p2;
}
#endif

#if 0
int main()
{
    Object *p1 = new Object[5];
    // delete p1;

    delete[] p1;
}
#endif

class Point
{
public:
    Point(int a, int b) { cout << "Point(int, int)" << endl; }
    Point() { cout << "Point()" << endl; }
};

int main()
{
    Point *p1 = new Point{10, 20}; // Point(int, int)
    Point *p2 = new Point;         // Point()

    Point *p3 = new Point[3]{{10, 20}, {30, 40}, {}};
    // Point(int, int)
    // Point(int, int)
    // Point()

    delete p1;
    delete p2;
    delete[] p3;
}