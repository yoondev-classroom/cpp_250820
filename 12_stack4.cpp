// 12_stack4.cpp
#include <iostream>
using namespace std;

// 객체를 생성하면, 객체를 사용할 수 있는 상태가 되어야 합니다.
// => 객체가 메모리에 생성되면, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//    : 생성자(Constructor) 함수

// * 생성자 멤버 함수
//  - 클래스 이름과 동일하고 반환 타입을 명시하지 않습니다.

class Stack
{
    // 멤버 데이터
    int buff[10];
    int top;

public:
    // 생성자 => 초기화
    Stack()
    {
        cout << "Stack()" << endl;
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

int main()
{
    Stack s1;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}