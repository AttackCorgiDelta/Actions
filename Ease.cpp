//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

//Based on Robert Penner's Easing functions
//http://robertpenner.com/easing/

//For diagrams of each Easing function's motion, visit:
//http://zero.digipen.edu/Tutorials/Scripting/UsingCustomEaseInActionsTutorial.html

#include "Ease.h"

namespace Ease
{

const float Pi = 4.f * std::atan(1.f);

//c: change in value
//t: current time
//d: duration
//b: start value

//No acceleration
float Linear(float t, float b, float c, float d)
{
  return c * t / d + b;
}

//Accelerate from 0 velocity
float InQuad(float t, float b, float c, float d)
{
  t /= d;
  return c * t * t + b;
}

//Decelerate to zero velocity
float OutQuad(float t, float b, float c, float d)
{
  t /= d;
  return -c * t * (t - 2.f) + b;
}

//Accelerate to halfway, then decelerate
float InOutQuad(float t, float b, float c, float d)
{
  if ((t /= d / 2.f) < 1.f)
    return ((c / 2.f) * (t * t)) + b;
  --t;
  return -c / 2.f * (((t - 2.f) * t) - 1.f) + b;
}

//Accelerate from zero velocity
float InCubic(float t, float b, float c, float d)
{
  t /= d;
  return c * t * t * t + b;
}

//Decelerate to zero velocity
float OutCubic(float t, float b, float c, float d)
{
  t /= d;
  return c * ((t - 1.f) * t * t + 1.f) + b;
}

//Accelerate to halfway, then decelerate
float InOutCubic(float t, float b, float c, float d)
{
  t /= d / 2.f;
  if(t < 1.f)
    return c / 2.f * t * t * t + b;
  t -= 2.f;
  return c / 2.f * (t * t * t + 2.f) + b;
}

//Accelerate from zero velocity
float InQuart(float t, float b, float c, float d)
{
  t /= d;
  return c * t * t * t * t + b;
}

//Decelerate to zero velocity
float OutQuart(float t, float b, float c, float d)
{
  t /= d - 1.f;
  return -c * (t * t * t * t - 1.f) + b;
}

//Accelerate to halfway, then decelerate
float InOutQuart(float t, float b, float c, float d)
{
  t /= d / 2.f;
  if(t < 1.f)
    return c / 2 * t * t * t * t + b;
  t -= 2.f;
  return -c / 2.f * (t * t * t * t - 2.f) + b;
}

//Accelerate from zero velocity
float InQuint(float t, float b, float c, float d)
{
  t /= d;
  return c * t * t * t * t * t + b;
}

//Decelerate to zero velocity
float OutQuint(float t, float b, float c, float d)
{
  t /= d - 1.f;
  return c * (t * t * t * t * t + 1.f) + b;
}

//Accelerate to halfway, then decelerate
float InOutQuint(float t, float b, float c, float d)
{
  t /= d / 2.f;
  if(t < 1.f)
    return c / 2.f * t * t * t * t * t + b;
  t -= 2.f;
  return c / 2.f * (t * t * t * t * t + 2.f) + b;
}

//Accelerate from zero velocity
float InSine(float t, float b, float c, float d)
{
  return -c * std::cos(t / d * (Pi / 2.f)) + c + b;
}

//Decelerate to zero velocity
float OutSine(float t, float b, float c, float d)
{
  return c * std::sin(t / d * (Pi / 2.f)) + b;
}

//Accelerate to halfway, then decelerate
float InOutSine(float t, float b, float c, float d)
{
  return -c / 2.f * (std::cos(Pi * t / d) - 1.f) + b;
}

//Accelerate from zero velocity
float InExpo(float t, float b, float c, float d)
{
  return c * std::pow(2.f, 10.f * (t / d - 1.f)) + b;
}

//Decelerate to zero velocity
float OutExpo(float t, float b, float c, float d)
{
  return c * (-std::pow(2.f, -10.f * t / d) + 1.f) + b;
}

//Accelerate to halfway, then decelerate
float InOutExpo(float t, float b, float c, float d)
{
  t /= d / 2.f;
  if(t < 1.f)
    return c / 2.f * std::pow(2.f, 10.f * (t - 1.f)) + b;
  t--;
  return c / 2.f * (-std::pow(2.f, -10.f * t) + 2.f) + b;
}

//Accelerate from zero velocity
float InCirc(float t, float b, float c, float d)
{
  t /= d;
  return -c * (std::sqrt(1.f - t * t) - 1.f) + b;
}

//Decelerate to zero velocity
float OutCirc(float t, float b, float c, float d)
{
  t /= d;
  --t;
  return c * std::sqrt(1.f - t * t) + b;
}

//Accelerate to halfway, then decelerate
float InOutCirc(float t, float b, float c, float d)
{
  t /= d / 2.f;
  if(t < 1.f)
    return -c / 2.f * (std::sqrt(1.f - t * t) - 1.f) + b;
  t -= 2.f;
  return c / 2.f * (std::sqrt(1.f - t * t) + 1.f) + b;
}

//Accelerate up a little, down a bit, up some more, down a lot, up a huge amount
float InElastic(float t, float b, float c, float d)
{
  if (!t)
    return b;
  t /= d;
  if(t / 2.f == 1.f)
    return b + c;
  float p = d * .3f;
  float a = c;
  float s = p / 4.f;
  float postFix = a * std::pow(2.f, 10.f * (t -= 1.f));
  return -(postFix * std::sin((t * d - s) * (2.f * Pi) / p)) + b;
}

//Accelerate up a huge amount, down a lot, up some more, down a bit, up a little
float OutElastic(float t, float b, float c, float d)
{
  if (!t)
    return b;
  t /= d;
  if(t / 2.f == 1.f)
    return b + c;
  float p = d * .3f;
  float a = c;
  float s = p / 4.f;
  return a * std::pow(2.f, -10.f * t) * std::sin((t * d - s) * (2.f * Pi) / p) + c + b;
}

//Accelerate up a little, down a bit, up a huge amount, down a bit, up a little
float InOutElastic(float t, float b, float c, float d)
{
  if(!t)
    return b;

  if((t /= d / 2.f) == 2.f)
    return b + c;
  float p = d * (.3f * 1.5f);
  float a = c;
  float s = p / 4.0f;

  if (t < 1.f)
  {
    float postFix = a * std::pow(2.f, 10.f * (t -= 1.f));
    return -(postFix * std::sin((t * d - s) * (2.f * Pi) / p)) + b;
  }
  float postFix = a * std::pow(2.f, -10.f * (t -= 1.f));
  return -(postFix * std::sin((t * d - s) * (2.f * Pi) / p)) + b;
}

//Accelerate below zero, then up
float InBack(float t, float b, float c, float d)
{
  float s = 1.70158f;
  float postFix = t /= d;
  return c * (postFix)*t * ((s + 1.f) * t - s) + b;
}

//Accelerate past full, then down to full
float OutBack(float t, float b, float c, float d)
{
  float s = 1.70158f;
  t /= d - 1.f;  
  return c * (t * t * ((s + 1.f) * t + s) + 1.f) + b;
}

//Accelerate below zero, then past full, then down to full
float InOutBack(float t, float b, float c, float d)
{
  float s = 1.70158f;
  t /= d / 2.f;
  if(t < 1.f)
    return c / 2.f * (t * t * ((s * 1.525f + 1.f) * t - s)) + b;
  float postFix = t -= 2.f;
  return c / 2.f * ((postFix) * t * ((s * 1.525f + 1.f) * t + s) + 2.f) + b;
}

//Accelerate up and down a bit, then a little up and down, then more up and down, then to full
float InBounce(float t, float b, float c, float d)
{
  return c - OutBounce(d - t, 0.f, c, d) + b;
}

//Accelerate up a huge amount, then accelerate down and up some more, then a little down and up, then a bit down and up
float OutBounce(float t, float b, float c, float d)
{
  if((t /= d) < 1.f / 2.75f)
    return c * (7.5625f * t * t) + b;
  else if(t < 2.f / 2.75f)
  {
    float postFix = t -= 1.5f / 2.75f;
    return c * (7.5625f * postFix * t + .75f) + b;
  }
  else if(t < 2.5f / 2.75f)
  {
    float postFix = t -= 2.25f / 2.75f;
    return c * (7.5625f * postFix * t + .9375f) + b;
  }
  else
  {
    float postFix = t -= 2.625f / 2.75f;
    return c * (7.5625f * postFix * t + .984375f) + b;
  }
}

//Accelerate up and down a bit, then up and down a bit more, then accelerate to full(with curve),
//then accelerate down and up a bit, then down and up a little
float InOutBounce(float t, float b, float c, float d)
{
  if(t < d / 2.f)
    return InBounce(t * 2.f, 0.f, c, d) * .5f + b;
  return OutBounce(t * 2.f - d, 0.f, c, d) * .5f + c * .5f + b;
}

} //namespace Ease