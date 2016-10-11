//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTION_H
#define ACTION_H

#include <cstddef>      //size_t
#include <cmath>        //abs
#include <cstring>      //memcpy
#include "ActionBase.h" //ActionBase
#include "Ease.h"       //Ease::Function
#include "Vector.h"     //Vec2, Vec3, Vec4

//The main Action class. Eases a value into another value given a duration of time and another value
//Note: Can only be dynamically allocated
class Action final : public ActionBase
{
public:  
  static Action * Make(float & target_, const float endValue_, const float duration_, const Ease::Function fn_);
  static Action * Make(Vec2 & target_, const Vec2 & endValue_, const float duration_, const Ease::Function fn_);
  static Action * Make(Vec3 & target_, const Vec3 & endValue_, const float duration_, const Ease::Function fn_);
  static Action * Make(Vec4 & target_, const Vec4 & endValue_, const float duration_, const Ease::Function fn_);

  float Update(float dt) override;

private:
  Action(float & target_, const float endValue_, const float duration_, const Ease::Function fn_);
  Action(Vec2 & target_, const Vec2 & endValue_, const float duration_, const Ease::Function fn_);
  Action(Vec3 & target_, const Vec3 & endValue_, const float duration_, const Ease::Function fn_);
  Action(Vec4 & target_, const Vec4 & endValue_, const float duration_, const Ease::Function fn_);

  //Action and associated classes are not meant to be copied
  Action & operator=(const Action &) = delete;
  Action(const Action &) = delete;

  float duration;    //How long it takes target to get to endValue in seconds
  float currentTime; //Current time through the easing process
  size_t vecSize;    //The size of the vector being passed in
  Vec4 * target;     //Pointer to the value to tween
  Ease::Function fn; //The function used for easing

  Vec4 displacement; //Displacement from target's initial value to endValue
  Vec4 startValue;   //The initial value of target
  Vec4 endValue;     //What the target will end up being
};

#endif //ACTION_H