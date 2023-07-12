#include "simulation.h"

Simulation::Simulation()
{
    objectList = new Object*[100];
    numOfObjects = 0;
}

void Simulation::createObject(Vector2 pos,int shape)
{
    numOfObjects++;
    objectList[numOfObjects] = new Object(pos,shape);
}

Simulation::~Simulation()
{
    for(int i=0;i<numOfObjects;i++)
    {
        delete objectList[i];
    }
    delete [] objectList;
}
