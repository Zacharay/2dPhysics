#pragma once
#include "Physics/object.h"

class Simulation{
    Object** objectList;
    int numOfObjects;
    int maxNumOfObjects=100;
public:
    Simulation();
    void createObject(Vector2 pos,int shape);
    ~Simulation();
};
