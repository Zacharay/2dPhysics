#include "object.h"

Object::Object(Vector2 pos,int shape)
{
    positionCurrent.x = pos.x;
    positionCurrent.y = pos.y;
    positionOld.x = pos.x;
    positionOld.y = pos.y;
    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    this->shape = shape;
}

void Object::updatePosition(float deltaTime)
{
    Vector2 velocity = positionCurrent-positionOld;


    positionOld = positionCurrent;
    positionCurrent = positionCurrent+velocity+acceleration*deltaTime*deltaTime;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;
}
void Object::accelerate(Vector2 acc)
{
    acceleration = acceleration+acc;
}

