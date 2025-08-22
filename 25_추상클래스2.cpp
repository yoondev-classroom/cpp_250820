// 25_추상클래스2.cpp
#include <iostream>
using namespace std;

// SRP(Single Reponsibility Principle, 단일 책임 원칙)
// : 클래스는 단 하나의 책임을 가져야 합니다.

class Camera
{
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class FHDCamera
{
public:
    void StartRecording() { cout << "[1080p]Start Recording" << endl; }
    void StopRecording() { cout << "[1080p]Stop Recording" << endl; }
};

// 원인
//  - Car 클래스가 Camera의 구체적인 타입에 의존하고 있습니다.
//  => 교체가 불가능합니다.
//    "강한 결합"

// 방법
//  - 느슨한 결합 / 약한 결합

class Car
{
    FHDCamera *camera;

public:
    Car(FHDCamera *p) : camera{p} {}

    void Go()
    {
        camera->StartRecording();
        // ...

        camera->StopRecording();
    }
};

int main()
{
    // Camera camera;
    FHDCamera camera;
    Car car{&camera};

    car.Go();
}