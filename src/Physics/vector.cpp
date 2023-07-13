#include "vector.h"
Vector2 Vector2::operator+(const Vector2&other)const{
    Vector2 newVector2;
    newVector2.x = x+other.x;
    newVector2.y = y+other.y;
    return newVector2;
}
Vector2 Vector2::operator-(const Vector2&other)const{
    Vector2 newVector2;
    newVector2.x = x-other.x;
    newVector2.y = y-other.y;
    return newVector2;
}
Vector2 Vector2::operator*(float num)const{
    Vector2 newVector2;
    newVector2.x = x*num;
    newVector2.y = y*num;
    return newVector2;
}
