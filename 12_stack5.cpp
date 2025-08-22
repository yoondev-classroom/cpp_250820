// 12_stack5.cpp
#include <iostream>
using namespace std;

// 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
// => 객체를 생성할 때, 생성자의 인자를 통해 사용자로부터 정보를 전달받을 수 있습니다.

class Stack
{
    // int buff[10];
    int *buff;
    int top;

public:
    Stack()
    {
        cout << "Stack()" << endl;
        top = 0;
        buff = new int[10];
    }

    // 생성자는 오버로딩이 가능합니다.
    Stack(size_t size)
    {
        cout << "Stack(int): " << size << endl;
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

int main()
{
    // Stack s1;      // Stack s1{}; -> Stack()
    // Stack s2{100}; // Stack(int)

    Stack s1{30};

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}