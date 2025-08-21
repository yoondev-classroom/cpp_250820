// 12_stack2.cpp
#include <iostream>
using namespace std;

// 스택의 상태를 사용자 정의 타입(구조체)로 만듭니다.
//  => 데이터 캡슐화

struct Stack
{
    int buff[10];
    int top;
};

void Init(Stack *s)
{
    s->top = 0;
}

void Push(Stack *s, int n)
{
    s->buff[(s->top)++] = n;
}

int Pop(Stack *s)
{
    return s->buff[--(s->top)];
}

// Stack s1;

int main()
{
    Stack s1;
    Init(&s1);

    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
}