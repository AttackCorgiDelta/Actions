//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionGroup.h"

//ActionGroup Static "Constructor" (public)
//Note: Dynamically allocates an ActionGroup
ActionGroup * ActionGroup::Make()
{
  return new ActionGroup;
}

//ActionGroup Constructor (private)
ActionGroup::ActionGroup() : ActionBase() {}

//Updates the ActionGroup by bringing it closer to the endValue
//dt: Amount to Update the ActionGroup by
float ActionGroup::Update(float dt)
{
  //Return if the Group is paused
  if(IsPaused())
    return -1.f;


  //We have leftover dt if we have finished the last ActionBase
  float leftoverDt = -1.f;
  if(actionBases.size() == 1)
  {
    leftoverDt = actionBases.front()->Update(dt);
  }

  //Update ActionBases via pointer in the list. Erase element if it is complete
  std::list<ActionBase *>::iterator it = actionBases.begin();
  while(it != actionBases.end())
  {
    ActionBase * action = *it;
    if(action->IsComplete())
    {
      delete *it; 
      it = actionBases.erase(it);
    }
    else
    {
      action->Update(dt);
      ++it;
    }
  }

  //If the Group is empty, flag it for erasion
  if(actionBases.empty())
    SetComplete(true);

  return leftoverDt;
}