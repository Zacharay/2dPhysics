#include "object.h"

Object::Object(Vector2 pos,int shape)
{
    position.x = pos.x;
    position.y = pos.y;
    this->shape = shape;
}
Object::Object()
{
    position.x = 0;
    position.y = 0;
}
