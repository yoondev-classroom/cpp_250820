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

class Car
{
    Camera *camera;

public:
    Car(Camera *p) : camera{p} {}

    void Go()
    {
        camera->StartRecording();
        // ...

        camera->StopRecording();
    }
};

int main()
{
    Camera camera;
    Car car{&camera};

    car.Go();
}