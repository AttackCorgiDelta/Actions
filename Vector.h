//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vec2
{
  float x, y;

  Vec2(float x = 0, float y = 0) : x(x), y(y) {}

  float & operator[](const unsigned index)
  {
    return *(&x + index);
  }

  float operator[](const unsigned index) const
  {
    return *(&x + index);
  }

} Vec2;

typedef struct Vec3
{
  float x, y, z;

  Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

  float & operator[](const unsigned index)
  {
    return *(&x + index);
  }

  float operator[](const unsigned index) const
  {
    return *(&x + index);
  }

} Vec3;

typedef struct Vec4
{
  float x, y, z, w;

  Vec4(float x = 0, float y = 0, float z = 0, float w = 0) : x(x), y(y), z(z), w(w) {}

  float & operator[](const unsigned index)
  {
    return *(&x + index);
  }

  float operator[](const unsigned index) const
  {
    return *(&x + index);
  }

} Vec4;

#endif