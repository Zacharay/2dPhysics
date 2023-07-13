#pragma once

struct Vector2{
    float x;
    float y;
    Vector2 operator+(const Vector2&other)const;
    Vector2 operator-(const Vector2&other)const;
    Vector2 operator*(const float num)const;
};
