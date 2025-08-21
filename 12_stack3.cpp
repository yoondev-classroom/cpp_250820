// 12_stack3.cpp
#include <iostream>
using namespace std;

// C++에서는 데이터(상태)와 데이터를 조작하는 함수(메소드)를
// 같이 캡슐화 할수 있습니다.

// - 객체의 상태는 객체가 제공하는 메소드를 통해서만 접근할 수 있어야 합니다.
//  => 정보 은닉(Information Hiding)
//  => 접근 제어 - 접근 지정자
//    1) public
//         : public 으로 지정되어 있는 멤버 함수 또는 멤버 데이터는 외부에서 접근이 가능합니다.
//    2) private
//         : 외부에서 접근이 불가능합니다. 오직 멤버 함수를 통해서만 접근이 가능합니다.

// - struct는 기본 접근 제어가 public 입니다. => 데이터 캡슐화
// - class는 기본 접근 제어가 private 입니다. => 데이터 + 행위 캡슐화

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