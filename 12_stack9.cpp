// 12_stack7.cpp
#include <iostream>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.
template <typename TYPE>
class Stack
{
    TYPE *buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack()
    {
        top = 0;
        buff = new TYPE[10];
    }

    Stack(size_t size)
    {
        top = 0;
        buff = new TYPE[size];
    }

    // TYPE -> User
    // => call by value: 템플릿 인자는 객체도 전달받을 수 있기 때문에, const&를 사용해야 합니다.

    // TYPE -> int
    //  void Push(const int& n)
    //  : 일반적이지 않지만, 문제는 없습니다.
    void Push(const TYPE &n)
    {
        buff[top++] = n;
    }

    // 참조하는 연산과 제거하는 연산이 분리되어야, 레퍼런스로 반환할 수 있습니다.
    void Pop()
    {
        --top;
    }

    TYPE &Top()
    {
        return buff[top - 1];
    }

    // 상수 멤버 함수와 비상수 멤버 함수를 모두 제공하는 것이 C++의 일반적인 스타일입니다.
    const TYPE &Top() const
    {
        return buff[top - 1];
    }
};

#include <string>

int main()
{
    Stack<string> s;

    s.Push("hello");
    s.Push("world");

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();
}
