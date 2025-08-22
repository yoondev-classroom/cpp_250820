// 27_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

class Image
{
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// 메모리 누수의 원인
//  - 포인터를 직접 다루면, delete가 누락될 수 있습니다.
// => Image*의 역활을 수행하는 클래스를 만들어서 자동으로 메모리 누수가 발생하지 않도록
//    처리해 봅시다.
//  : 객체의 소멸자를 통해, 소유한 자원을 자동으로 정리합니다.

// 스마트 포인터
//  : 자동으로 메모리를 관리해줍니다.
#if 0
class Ptr
{
    Image *obj;

public:
    Ptr(Image *p = nullptr) : obj{p} {}
    ~Ptr()
    {
        // if (obj)
        // {
        //     delete obj;
        // }

        delete obj;
        // obj가 nullptr일 경우, 아무일도 수행하지 않습니다.
    }

    // *p
    Image &operator*() { return *obj; }

    // p->
    Image *operator->() { return obj; }
};
#endif

template <typename TYPE>
class Ptr
{
    TYPE *obj;

public:
    inline Ptr(TYPE *p = nullptr) : obj{p} {}
    inline ~Ptr()
    {
        // if (obj)
        // {
        //     delete obj;
        // }

        delete obj;
        // obj가 nullptr일 경우, 아무일도 수행하지 않습니다.
    }

    // *p
    inline TYPE &operator*() { return *obj; }

    // p->
    inline TYPE *operator->() { return obj; }
};

// C++ 표준 라이브러리에 잘 만들어진 스마트포인터가 제공됩니다.
#include <memory>
// => 복사 정책
// - unique_ptr
//    : 복사 금지

// - shared_ptr
//    : 참조 계수

// 프레임워크에서 자체적으로 스마트포인터를 구현해서 사용하는 경우도 많습니다.
// : Android - sp<>

int main()
{
    shared_ptr<Image> p1{new Image};
    shared_ptr p2{p1}; // 참조 계수 증가

    (*p1).Draw();
    p2->Draw();

    p1 = nullptr; // 참조 계수 감소 : 2 -> 1
    p2 = nullptr; // 참조 계수 감소 : 1 -> 0
    cout << "--------" << endl;
}

// fopen  / open
// fclose / close
//  : RAII - C++에서 생성자와 소멸자를 통해 자원의 초기화/해지를 관리하는 경우가 많습니다.
/*
class File {
public:
    File(const string& filename) { open(filename); }
    ~File() { close(filename); }
};
*/

#if 0
int main()
{
    unique_ptr<Image> p{new Image};

    (*p).Draw();
    p->Draw();
}
#endif

#if 0
int main()
{
    // Image *p; // 쓰레기값
    // Ptr p; // 생성자: 포인터가 유효하지 않은 경우, nullptr 초기화합니다.

    Ptr<Image> p{new Image};

    // 포인터 처럼 사용할 수 있어야 합니다.
    (*p).Draw();
    // - *p
    //    : Image& p.operator*()

    p->Draw();
    //    : Image* p.operator->()
}
#endif

#if 0
int main()
{
    Image *p = new Image;
    p->Draw();

    delete p;
}
#endif