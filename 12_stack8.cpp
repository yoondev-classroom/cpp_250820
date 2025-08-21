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

    // => 참조 하는 연산에서 값으로 반환하는 것이 아니라, 레퍼런스로 반환하기 위해서 분리되어 있습니다.

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}