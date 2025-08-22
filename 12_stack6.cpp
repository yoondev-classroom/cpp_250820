// 12_stack6.cpp
#include <iostream>
using namespace std;

// * 객체 내부에서 new를 하였다면, 반드시 객체가 파괴되기 전에, 해당 메모리를 해지해주어야 합니다.
// => C++에서는 객체가 메모리에서 파괴되지 직전에 호출되는 약속된 멤버 함수가 있습니다.
//    : 소멸자(Destructor) 함수

// 소멸자 멤버 함수
// - 함수의 이름은 ~클래스이름
// - 소멸자의 인자는 없습니다.
// - 소멸자는 1개만 제공할 수 있습니다.

// C/C++
// => 자원 관리는 개발자의 책임입니다.
// => Rust/Zig

// Java/C#/Go ...
// => 개발자는 자원을 할당만 하고, 해지는 언어가 담당합니다.
//   : GC
//  1) 객체의 메모리 해지 시점이 명확하지 않습니다.
//  2) GC의 비용이 발생합니다.

class Stack
{
    int *buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff; // !!
    }

    Stack()
    {
        top = 0;
        buff = new int[10];
    }

    // 생성자는 오버로딩이 가능합니다.
    Stack(size_t size)
    {
        top = 0;
        buff = new int[size];
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

// strdup

int main()
{

    char *ps = strdup("hello");
    printf("%s\n", ps);
    free(ps); // !!!

    // Stack s1;      // Stack s1{};
    // Stack s2{100}; // Stack(int)

    Stack s1{30};

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}