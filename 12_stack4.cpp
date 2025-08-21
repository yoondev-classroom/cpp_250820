// 12_stack4.cpp
#include <iostream>
using namespace std;

class Stack
{
    // 멤버 데이터
    int buff[10];
    int top;

public:
    // 멤버 함수
    void Init()
    {
        top = 0;
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

// Stack s1;

int main()
{
    Stack s1;
    // 상태와 행위를 가지는 변수
    // => 객체

    s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    // s1.top = 100; // !!!

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}