//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "Action.h"

//Static Constructors (public)
//*****************************************************************************

//Dynamically allocates an Action
//target_: Reference to the variable being modified
//endValue_: The value we want the target variable to end up being
//duration_: How long it takes to get to the endValue
//fn_: The Ease to be used to get the target to the endValue

Action * Action::Make(float & target_, float endValue_, float duration_, const Ease::Function fn_)
{
  return new Action(target_, endValue_, duration_, fn_);
}

Action * Action::Make(Vec2 & target_, const Vec2 & endValue_, float duration_, const Ease::Function fn_)
{
  return new Action(target_, endValue_, duration_, fn_);
}

Action * Action::Make(Vec3 & target_, const Vec3 & endValue_, float duration_, const Ease::Function fn_)
{
  return new Action(target_, endValue_, duration_, fn_);
}

Action * Action::Make(Vec4 & target_, const Vec4 & endValue_, float duration_, const Ease::Function fn_)
{
  return new Action(target_, endValue_, duration_, fn_);
}
  
//*****************************************************************************

//Constructors (private)
//*****************************************************************************

//target: Reference to the variable being modified
//endValue: The value we want the target variable to end up being
//duration: How long it takes to get to the endValue
//fn: The Ease to be used to get the target to the endValue
//Note: All constructors are similar; vecSize is set depending on the type of "endValue_"

Action::Action(float & target_, const float endValue_, const float duration_, const Ease::Function fn_) :
ActionBase(), duration(duration_), currentTime(0.f), vecSize(1), fn(fn_)
{
  target = reinterpret_cast<Vec4 *>(&target_);
  
  startValue[0] = target_;
  endValue[0] = endValue_;

  displacement[0] = std::abs(endValue_ - target_);
  if(endValue_ < target_)
    displacement[0] = -displacement[0];
}

Action::Action(Vec2 & target_, const Vec2 & endValue_, const float duration_, const Ease::Function fn_) :
  ActionBase(), duration(duration_), currentTime(0.f), vecSize(2), fn(fn_)
{
  target = reinterpret_cast<Vec4 *>(&target_);

  std::memcpy(&startValue, &target_, sizeof(Vec2));
  std::memcpy(&endValue, &endValue_, sizeof(Vec2));

  for(size_t i = 0; i < 2; ++i)
  {
    displacement[i] = std::abs(endValue_[i] - target_[i]);
    if(endValue_[i] < target_[i])
      displacement[i] = -displacement[i];
  }
}

Action::Action(Vec3 & target_, const Vec3 & endValue_, const float duration_, const Ease::Function fn_) :
  ActionBase(), duration(duration_), currentTime(0.f), vecSize(3), fn(fn_)
{
  target = reinterpret_cast<Vec4 *>(&target_);

  std::memcpy(&startValue, &target_, sizeof(Vec3));  
  std::memcpy(&endValue, &endValue_, sizeof(Vec3));

  for(size_t i = 0; i < 3; ++i)
  {
    displacement[i] = std::abs(endValue_[i] - target_[i]);
    if(endValue_[i] < target_[i])
      displacement[i] = -displacement[i];
  }
}

Action::Action(Vec4 & target_, const Vec4 & endValue_, const float duration_, const Ease::Function fn_) :
  ActionBase(), duration(duration_), currentTime(0.f), vecSize(4), target(&target_), fn(fn_)
{
  std::memcpy(&startValue, &target_, sizeof(Vec4));
  std::memcpy(&endValue, &endValue_, sizeof(Vec4));

  for(size_t i = 0; i < 4; ++i)
  {
    displacement[i] = std::abs(endValue_[i] - target_[i]);
    if(endValue_[i] < target_[i])
      displacement[i] = -displacement[i];
  }
}

//*****************************************************************************

//Updates the Action by bringing it closer to the endValue
//dt: Amount to Update the Action by
//Returns the leftover dt when this Action completes
float Action::Update(float dt)
{
  //Return if the Action is paused
  if(IsPaused()) 
    return -1.f;
  
  //Increment the current time through the Action
  currentTime += dt; 

  //Update each of the floats inside the Vec
  for(size_t i = 0; i < vecSize; ++i)
    target[i] = (*fn)(currentTime, startValue[i], displacement[i], duration);

  //If the Action has ended
  if(currentTime > duration) 
  {
    //Avoid overstepping if dt is too large
    for(size_t i = 0; i < vecSize; ++i)
      target[i] = endValue[i];  

    //The Action is complete. Flag it for erasion
    SetComplete(true);
    SetPaused(true);

    //Return the leftover dt
    return currentTime - duration;
  }

  return -1.f;
}
