#pragma once
#include "vector.h"

enum Shape{
    circle=1,
    rectangle=2,
    triangle=3
};

class Object{
public:
    Vector2 positionCurrent;
    Vector2 positionOld;
    float radius =10;

    int shape;
public:
    Object(Vector2 pos,int shape);
    void updatePosition(float deltaTime);

};

