//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionBase.h"

//ActionBase Constructor (protected)
ActionBase::ActionBase() : callBack(nullptr), delay(0.f), complete(false), paused(false) {}

//Calls the SpecializedUpdate method of the derived class
//Accounts for pausing and delaying
float ActionBase::Update(float dt)
{
  //We don't want to update if the ActionBase is paused
  if(paused)
    return -1.f;

  if(delay > 0.f)
  {
    //Decrement the delay by dt and check to see if it still hasn't gone off 
    delay -= dt;
    if(delay > 0.f)
      return -1.f;
    
    //When we call SpecializedUpdate, we want to use the leftover dt
    dt = 0.f - delay;
  }

  //Call the SpecializedUpdate, saving its return value for after checking if complete
  float ret = SpecializedUpdate(dt);

  //If the last SpecializedUpdate call completed the ActionBase, invoke the callback
  if(complete)
    if(callBack != nullptr)
      callBack();

  return ret;
}

void ActionBase::SetCallBack(CALLBACK callBack_)
{
  callBack = callBack_;
}

ActionBase::CALLBACK ActionBase::GetCallBack()
{
  return callBack;
}

float ActionBase::GetDelay() const
{
  return delay;
}

void ActionBase::SetDelay(const float delay_)
{
  delay = delay_;
}

//Returns whether the ActionBase has completed its easing
bool ActionBase::IsComplete() const
{
  return complete;
}

//Sets whether the ActionBase has completed its easing
void ActionBase::SetComplete(const bool isComplete)
{
  complete = isComplete;
}

//Returns whether Action is paused or running
bool ActionBase::IsPaused() const
{
  return paused;
}


//Sets the Action to paused or running
void ActionBase::SetPaused(const bool isPaused)
{
  paused = isPaused;
}