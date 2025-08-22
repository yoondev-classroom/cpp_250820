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
    Player *player;

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