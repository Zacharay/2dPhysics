#include "simulation.h"
#include "globals.h"
#include "iostream"
#include <math.h>
Simulation::Simulation()
{
    objectList = new Object*[100];
    numOfObjects = 0;
    Vector2 pos;
    spawnObjects();
}

void Simulation::createObject(Vector2 pos,int shape)
{
    numOfObjects++;
    objectList[numOfObjects] = new Object(pos,shape);

}
void Simulation::spawnObjects()
{
    for(int i=1;i<= 30;i++)
    {
        Vector2 pos;
        pos.x = 10*i;
        pos.y = 10*i;
        createObject(pos,circle);
    }
}
void Simulation::Update(float deltaTime){
        for(int i=1;i<=numOfObjects;i++)
        {
            Object *obj = objectList[i];
            findCollisions();
            obj->updatePosition(deltaTime);
        }


}
bool Simulation::collide(Object *obj1,Object *obj2)
{
    //distance from one circle center to
    //another is smaller than sum of their radiuses
    double distanceFromCenters = sqrt(
    pow((obj1->positionCurrent.x-obj2->positionCurrent.x),2)+
    pow((obj1->positionCurrent.y-obj2->positionCurrent.y),2));
    double sumOfRadiuses = obj1->radius+obj2->radius;
    if(distanceFromCenters<sumOfRadiuses){

        Vector2 collision_axis;
        collision_axis.x = obj1->positionCurrent.x - obj2->positionCurrent.x;
        collision_axis.y = obj1->positionCurrent.y - obj2->positionCurrent.y;
        Vector2 n;
        n.x = collision_axis.x / distanceFromCenters;
        n.y = collision_axis.y / distanceFromCenters;
        obj1->positionCurrent = obj1->positionCurrent+ n*0.5;

        obj2->positionCurrent = obj2->positionCurrent- n*0.5;
        std::cout<<n.x<<" "<<n.y<<std::endl;
        return true;
    }
    else return false;
}
void Simulation::findCollisions()
{
    for(int i=1;i<=numOfObjects;i++)
    {
        Object *obj1 = objectList[i];
        for(int j=i+1;j<=numOfObjects;j++)
        {
            Object *obj2 = objectList[j];
            if(collide(obj1,obj2))
            {

            }
        }
    }
}

Simulation::~Simulation()
{
    for(int i=1;i<=numOfObjects;i++)
    {
        delete objectList[i];
    }
    delete [] objectList;
}
