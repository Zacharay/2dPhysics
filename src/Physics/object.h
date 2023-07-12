#pragma once
#include "vector.h"

enum Shape{
    circle=1,
    rectangle=2,
    triangle=3
};

class Object{
public:
    Vector2 position;
    int shape;
public:
    Object(Vector2 pos,int shape);
    Object();
};

