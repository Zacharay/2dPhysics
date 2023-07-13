#include "simulation.h"
#include "globals.h"
#include "iostream"

Simulation::Simulation()
{
    objectList = new Object*[100];
    numOfObjects = 0;
    Vector2 pos;
    //pos.x = 0;
    //pos.y = WINDOW_HEIGHT-10;
    //createObject(pos,circle);
    spawnObjects();
}

void Simulation::createObject(Vector2 pos,int shape)
{
    numOfObjects++;
    objectList[numOfObjects] = new Object(pos,shape);

}
void Simulation::spawnObjects()
{
    for(int i=1;i<= 50;i++)
    {
        Vector2 pos;
        pos.x = 10*i;
        pos.y = 500;
        createObject(pos,circle);
    }
}
void Simulation::Update(float deltaTime){
        for(int i=1;i<=numOfObjects;i++)
        {
            Object *obj = objectList[i];
            obj->updatePosition(deltaTime);
        }


}
void Simulation::checkBoundaries()
{


}
Simulation::~Simulation()
{
    for(int i=1;i<=numOfObjects;i++)
    {
        delete objectList[i];
    }
    delete [] objectList;
}
