#include "simulation.h"
#include "iostream"

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
    for(int i=1;i<=30;i++)
    {
        Vector2 pos;
        pos.x = 20*i;
        pos.y = 20*i;
        createObject(pos,circle);
    }
}
void Simulation::applyGravity(Object *obj)
{
        Vector2 gravity;
        gravity.x = 0;
        gravity.y = 9.8f;

        obj->accelerate(gravity);
}
void Simulation::Update(float deltaTime)
{
    //int numberOfSubsteps = 4;
    //float substepSize = deltaTime/numberOfSubsteps;
    //for(int i=0;i<numberOfSubsteps;i++)
    //{

        for(int i=1;i<=numOfObjects;i++)
        {
            Object *obj = objectList[i];
            applyGravity(obj);
        }
        for(int i=1;i<=numOfObjects;i++)
        {
            Object *obj = objectList[i];
            obj->updatePosition(deltaTime);
        }

    //}


}

Simulation::~Simulation()
{
    for(int i=1;i<=numOfObjects;i++)
    {
        delete objectList[i];
    }
    delete [] objectList;
}
