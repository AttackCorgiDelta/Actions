//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vec2
{
  float array[2];

  Vec2(float x = 0, float y = 0)
  {
    array[0] = x;
    array[1] = y;
  }

  float & operator[](const unsigned index)
  {
    return array[index];
  }

  float operator[](const unsigned index) const
  {
    return array[index];
  }

  float & x() { return array[0]; }
  float & y() { return array[1]; }

} Vec2;

typedef struct Vec3
{
  float array[3];

  Vec3(float x = 0, float y = 0, float z = 0)
  {
    array[0] = x;
    array[1] = y;
    array[2] = z;
  }

  float & operator[](const unsigned index)
  {
    return array[index];
  }

  float operator[](const unsigned index) const
  {
    return array[index];
  }

  float & x() { return array[0]; }
  float & y() { return array[1]; }
  float & z() { return array[2]; }

} Vec3;

typedef struct Vec4
{
  float array[4];

  Vec4(float x = 0, float y = 0, float z = 0, float w = 0)
  {
    array[0] = x;
    array[1] = y;
    array[2] = z;
    array[3] = w;
  }

  float & operator[](const unsigned index)
  {
    return array[index];
  }

  float operator[](const unsigned index) const
  {
    return array[index];
  }

  float & x() { return array[0]; }
  float & y() { return array[1]; }
  float & z() { return array[2]; }
  float & w() { return array[3]; }

} Vec4;

#endif