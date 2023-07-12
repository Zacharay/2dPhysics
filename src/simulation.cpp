#include "simulation.h"

Simulation::Simulation()
{
    objectList = new Object*[100];
    numOfObjects = 0;
    spawnObjects();
}

void Simulation::createObject(Vector2 pos,int shape)
{
    numOfObjects++;
    objectList[numOfObjects] = new Object(pos,shape);
}
void Simulation::spawnObjects()
{
    for(int i=1;i<maxNumOfObjects;i++)
    {
        Vector2 pos;
        pos.x = 10*i;
        pos.y = 10*i;
        createObject(pos,circle);
    }
}

Simulation::~Simulation()
{
    for(int i=0;i<numOfObjects;i++)
    {
        delete objectList[i];
    }
    delete [] objectList;
}
