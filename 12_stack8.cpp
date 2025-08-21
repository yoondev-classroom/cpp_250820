// 12_stack8.cpp

// C++에는 이미 잘만들어진 stack이 있습니다.
// => STL
#include <iostream>
using namespace std;

#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // STL의 컨테이너는 데이터를 참조하는 연산과, 제거하는 연산이 분리되어 있습니다.
    // - 참조: top()
    // - 제거: pop()

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}