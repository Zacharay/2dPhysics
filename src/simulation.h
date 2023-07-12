#pragma once
#include "Physics/object.h"

class Simulation{
public:
    Object** objectList;
    int numOfObjects;
private:
    int maxNumOfObjects=100;
public:
    Simulation();
    void createObject(Vector2 pos,int shape);
    void spawnObjects();
    ~Simulation();
};
