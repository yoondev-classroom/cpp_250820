// 2_namespace.cpp
#include <iostream>

namespace audio
{
    // audio.cpp
    void Init() { std::cout << "Audio Init" << std::endl; }
}

namespace video
{
    // video.cpp
    void Init() { std::cout << "Video Init" << std::endl; }
}

// 컴파일의 단위는 각 파일입니다.
//  - g++ audio.cpp -c           => audio.o
//  - g++ video.cpp -c           => video.o

// 링킹의 과정에서 동일한 심볼이 존재하면, 실패합니다.
//  => duplicate symbol 'Init()'
//  => C 언어에서는 이름 충돌을 막는 문법이 제공되지 않기 때문에,
//     라이브러리를 만드는 제작자가 접두를 통해 이름충돌을 회피합니다.
//  => namespace

// * 핵심
// 1) C++에서는 이름 충돌을 예방하기 위해서, namespace를 사용합니다.
// 2) C++의 모든 표준 라이브러리는 std 이름 공간안에 존재합니다.
// 3) namespace는 소문자로 사용하는 것이 일반적입니다.
// 4) namespace를 통해 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.

namespace audio
{
    void Play() {}
}

namespace video
{
    namespace mp3
    {
        void Play() {}
    }

    namespace mp4
    {
        void Play() {}
    }
}

int main()
{
    audio::Play();
    audio::Init();

    video::Init();
    video::mp3::Play();
    video::mp4::Play();
}