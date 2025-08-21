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

    TYPE Pop()
    {
        return buff[--top];
    }
};

#include <string>

int main()
{
    Stack<string> s;

    s.Push("hello");
    s.Push("world");

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}

#if 0
int main()
{
    Stack<double> s1{30};

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif