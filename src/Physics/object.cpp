#include "object.h"
#include "../globals.h"
Object::Object(Vector2 pos,int shape)
{
    positionCurrent.x = pos.x;
    positionCurrent.y = pos.y;
    positionOld.x = pos.x;
    positionOld.y = pos.y;


    this->shape = shape;
}

void Object::updatePosition(float deltaTime)
{
    Vector2 velocity = positionCurrent-positionOld;
    float bounce = 0.9f;
    float gravity = 0.5f;
    float friction = 0.999f;

    velocity.x*=friction;
    velocity.y*=friction;

    positionOld = positionCurrent;
    positionCurrent = positionCurrent+velocity;
    positionCurrent.y +=gravity;

    if(positionCurrent.x>WINDOW_WIDTH-radius*2)
    {
        positionCurrent.x = WINDOW_WIDTH-radius*2;
        positionOld.x = positionCurrent.x + velocity.x*bounce;
    }
    else if(positionCurrent.x<0)
    {
        positionCurrent.x  = 0;
        positionOld.x  = positionCurrent.x + velocity.x*bounce;
    }
    else if(positionCurrent.y<0)
    {
        positionCurrent.y  = 0;
        positionOld.y  = positionCurrent.y + velocity.y*bounce;
    }
    else if(positionCurrent.y>WINDOW_HEIGHT-radius*2)
    {

        positionCurrent.y  = WINDOW_HEIGHT-radius*2;
        positionOld.y = positionCurrent.y + velocity.y*bounce;
    }
}



