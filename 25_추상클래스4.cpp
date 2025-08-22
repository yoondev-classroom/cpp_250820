// 25_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스 기반 설계의 문제점.
// => 인터페이스에 새로운 기능을 추가하는 것이 어렵습니다.
//  ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
//  : 범용적인 인터페이스보다 세분화된 인터페이스가 좋다.

class Player
{
public:
    virtual ~Player() {}

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;
    // - 인터페이스: 순수 가상 함수만 존재하는 추상 클래스
    //  => 기본 구현을 제공할 수 있습니다.
    //   : defender method
    virtual void PlayOneMinute()
    {
        Play();
        // ...
        Stop();
    }
};

class Person
{
    Player *player; // 위임: 레퍼런스 / 포인터

public:
    Person(Player *p) : player{p} {}

    void PlayMusic()
    {
        player->Play();
        player->Stop();

        player->PlayOneMinute(); // 새로운 기능의 추가를 요구!
    }
};

class Apple : public Player
{
public:
    void Play() override
    {
        cout << "Play" << endl;
    }
    void Stop() override
    {
        cout << "Stop" << endl;
    }

    void PlayOneMinute() override
    {
        //...
    }
};

class Samsung : public Player
{
public:
    void Play() override
    {
        cout << "Play" << endl;
    }
    void Stop() override
    {
        cout << "Stop" << endl;
    }
};

int main()
{
    Apple apple;
    Samsung samsung;
    Person p{&samsung};

    p.PlayMusic();
}

// * 객체지향 5대 원칙 => SOLID
// SRP: 단일 책임 원칙 - 단 하나의 책임을 가져야 한다.
// OCP: 개방 폐쇄 원칙 - 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
// LSP: 리스코프 치환 원칙 - 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//                      자식의 공통의 기능은 부모로부터 비롯되어야 한다. => "다형성"
// ISP: 인터페이스 분리 원칙 - 범용 인터페이스 보다 세분화된 인터페이스가 좋다.
// DIP: 의존관계 역전 원칙  - 구체적인 타입에 의존하는 것이 아니라, 추상 타입(추상클래스, 인터페이스)
//                       에 의존해야 한다.
//                       => 교체 가능한 설계