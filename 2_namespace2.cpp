// 2_namespace2.cpp
#include <iostream>

namespace audio
{
    namespace mp3
    {
        void Play() { std::cout << "Audio Play" << std::endl; }
        void Stop() {}
    }
}

// 1) 전체 이름을 명시하는 방법
#if 0
int main()
{
    audio::mp3::Play();
}
#endif

// 2) using 선언
#if 0
using audio::mp3::Play;
using std::cout;
using std::endl;

int main()
{
    Play();

    cout << "Hello, C++" << endl;
}
#endif

// 3) using 지시어
// => 현업에서 사용을 주의해야 합니다.
// => 이름 충돌로 인한 문제가 발생할 가능성이 있습니다.

using namespace audio::mp3;
// 지정된 namespace 안의 모든 요소를 암묵적으로 접근할 수 있습니다.
// using namespace std;
// std 안에는 count 라는 이름의 함수가 존재합니다.

using std::cout;
using std::endl;

int count = 100;

int main()
{
    Play();
    Stop();

    count = 100;
    cout << count << endl;
}