// 26_접근변경자2.cpp
#include <iostream>
using namespace std;

#include <vector>
// stack을 만들고 싶습니다.
// vector를 재활용해서 stack을 만들어봅시다.

// "재활용" => 상속
//  : 일반적으로 상속을 재사용의 목적으로 하게되면, 불필요한 부모의 함수가 외부에 노출됩니다.
//  C++에서는 "접근 변경자"를 사용하면 문제를 해결할 수 있습니다.
//   : private 상속의 의도
//    => 부모의 구현은 물려받지만, 외부에 공개하지 않겠다.(부모의 인터페이스는 물려 받지 않겠다.)

#if 0
template <typename TYPE>
// class Stack : public vector<TYPE>
class Stack : private vector<TYPE>
{
public:
    void Push(const TYPE &data) { vector<TYPE>::push_back(data); }

    void Pop() { return vector<TYPE>::pop_back(); }

    TYPE &Top() { return vector<TYPE>::back(); }
    const TYPE &Top() const { return vector<TYPE>::back(); }
};

int main()
{
    Stack<int> s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    // s.push_back(10);

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
}
#endif

// 상속은 목적은 재사용이 아닙니다.
// 상속의 목적은 "다형성"입니다.
// 재사용은 "포함"을 통해서 구현하는 것이 좋습니다.

template <typename TYPE>
class Stack
{
    vector<TYPE> v; // 포함

public:
    void Push(const TYPE &data) { v.push_back(data); }

    void Pop() { return v.pop_back(); }

    TYPE &Top() { return v.back(); }
    const TYPE &Top() const { return v.back(); }
};

int main()
{
    Stack<int> s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    // s.push_back(10);

    cout << s.Top() << endl;
    s.Pop();

    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
}
