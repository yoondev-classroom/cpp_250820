// 18_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// 1) Call by value
#if 0
void foo(Sample s) // 2) Sample(const Sample&)
{
} // 3) ~Sample()

int main()
{
    Sample s; // 1) Sample()

    foo(s); // Call by value -> copy!!!

} // 4) ~Sample()
#endif

// 해결 방법: const T&
// => 객체 타입을 인자로 전달받을 경우, call by value아니라,
//    const T& 형태로 사용해야 합니다.
void foo(const Sample &s)
{
}

int main()
{
    Sample s; // 1) Sample()

    foo(s);

} // 2) ~Sample()