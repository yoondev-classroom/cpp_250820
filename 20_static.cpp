// 20_static.cpp
#include <iostream>
using namespace std;

#if 0
class Car
{
    int cnt = 0;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1; // c1.cnt -> 1
    Car c2; // c2.cnt -> 1

    cout << c1.GetCount() << endl;
    cout << c1.GetCount() << endl;
}
#endif

#if 0
int cnt = 0; // 전역 변수
// 프로그램이 시작할 때, 초기화되고, 프로그램이 끝날 때 사라집니다.
// 문제점
// => 클래스의 접근 제어를 사용할 수 없습니다.

class Car
{
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1; // c1.cnt -> 1
    Car c2; // c2.cnt -> 1

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;

    cnt = 100;
    cout << c1.GetCount() << endl;
}
#endif

// * 클래스의 상태 => 객체가 공유하는 상태 => 정적 멤버 데이터
//   객체의 상태 => 멤버 데이터
// * 클래스의 행위 => 정적 멤버 함수
//   객체의 행위 => 멤버 함수

class Car
{
    static int cnt; // 정적 멤버 데이터 선언

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    static int GetCount() { return cnt; } // 정적 멤버 함수
    // => 전역 함수와 동일하게, this가 전달되지 않습니다.
    //                      "객체를 생성하지 않고 호출할 수 있습니다."
    //    전역 함수와 다르게, 클래스의 접근 제어를 사용할 수 있습니다.
};

// 정의
int Car::cnt = 0;
// 정적 멤버 데이터의 수명은 전역 변수와 동일합니다.
// 정적 멤버 데이터는 전역 변수와 달리 클래스의 접근 제어를 사용할 수 있습니다.

int main()
{
    // 정적 멤버 함수는 클래스 이름을 통해서도 호출이 가능합니다.
    cout << Car::GetCount() << endl;

    Car c1; // c1.cnt -> 1
    Car c2; // c2.cnt -> 1

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
    // 멤버 함수는 객체를 생성해야지만 사용할 수 있습니다.
    cout << Car::GetCount() << endl;

    // Car::cnt = 1000;
    // cout << Car::cnt << endl;
}