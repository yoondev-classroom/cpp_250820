// 헤더 파일이 여러번 포함되어도, 한번만 포함되도록
// 만들어주어야 합니다.
// -> include guard
// -> 심볼이 이미 정의되어 있을 경우, 헤더가 제대로 포함되지 않는
//    문제가 발생할 수 있으므로, 충돌 가능성이 낮은 이름을
//    사용해야 합니다.

#ifndef PROJNAME_ADD_H
#define PROJNAME_ADD_H

struct Point
{
    int x;
    int y;
};

// add.h
int Add(int a, int b, int c = 0, int d = 0);

#endif