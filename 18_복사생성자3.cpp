// 18_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// 2) 함수에서 객체를 값으로 반환할 때

#if 0
Sample s; // 전역 객체
Sample foo()
{
    return s;
    // 반환용 임시 객체를 복사 생성을 통해 만들어서, 전달합니다.
    //  : Sample(const Sample&)
}

int main()
{
    cout << "---------------" << endl;
    foo();
    // 반환용 임시 객체가 파괴됩니다: ~Sample()
    cout << "---------------" << endl;
}
#endif

Sample s; // 전역 객체
Sample &foo()
{
    return s;
}

int main()
{
    cout << "---------------" << endl;

    foo();

    cout << "---------------" << endl;
}