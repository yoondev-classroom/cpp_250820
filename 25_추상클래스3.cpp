// 25_추상클래스3.cpp
#include <iostream>
using namespace std;

// * 강한 결합: 구체적인 타입에 의존하는 것
//  Car -------<> Camera

// * 약한 결합 / 느슨한 결합 => OCP를 만족합니다!!!
//   : 구체적인 타입이 아니라, 추상 타입에 의존하는 것
//  Car -------<> <<BlackBox>>
//                      |
//                   -------
//                   |     |
//                Camera  FHDCamera ...
//  - DIP(Dependency Inversion Principle, 의존관계 역전 원칙)
//   : 구체적인 타입이 아니라 추상 타입(추상클래스/인터페이스)에 의존해야 합니다.

// 1) 카메라의 제작자와 자동차의 제작자가 카메라의 사용 방법을 약속합니다.
//  => 인터페이스 / 프로토콜
//   : C++에서는 인터페이스를 위한 별도의 문법이 존재하지 않습니다.
//     순수 가상 함수로만 이루어진 클래스 => 인터페이스
class BlackBox
{
public:
    virtual ~BlackBox() {} // 가상 소멸자!!

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 BlackBox 인터페이스를 이용하는 자동차를 구현합니다.
class Car
{
    BlackBox *camera;

public:
    Car(BlackBox *p) : camera{p} {}

    void Go()
    {
        camera->StartRecording();
        // ...
        camera->StopRecording();
    }
};

// 3) 카메라의 제작자는 BlackBox를 기반으로 카메라를 구현해야 합니다.
//   "Camera가 BlackBox를 상속한다" 라고 하지 않고,
//   "Camera가 BlackBox 인터페이스를 구현한다" 라고 합니다.
class Camera : public BlackBox
{
public:
    void StartRecording() override
    {
        cout << "Start Recording" << endl;
    }
    void StopRecording() override
    {
        cout << "Stop Recording" << endl;
    }
};

class FHDCamera : public BlackBox
{
public:
    void StartRecording() override
    {
        cout << "[1080p]Start Recording" << endl;
    }
    void StopRecording() override
    {
        cout << "[1080p]Stop Recording" << endl;
    }
};

int main()
{
    FHDCamera camera;
    Car car{&camera};

    car.Go();
}

// Design Pattern(디자인 패턴, 1995) - 에릭 감마 : 23가지
//  => 에릭감마 외 3명
//  => 변화에 대응하기 위한 설계!
//   : 설계에서 실패하는 원인 - 변화에 대한 예측이 실패하는 경우가 많습니다.
//  최대한 단순하게 설계하고, 이후에 요구사항이 변경되거나 추가되었을 때, 리팩토링을 통해
//  개선하는 것이 좋습니다.

// 리팩토링 2판(마틴파울러)
//   => Javascript(OOP + FP)