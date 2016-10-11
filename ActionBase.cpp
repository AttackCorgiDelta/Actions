//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionBase.h"

//ActionBase Constructor (protected)
ActionBase::ActionBase() : complete(false), paused(false) {}

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