//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionGroup.h"

//ActionGroup Static "Constructor" (public)
//Dynamically allocates an ActionGroup
std::unique_ptr<ActionGroup> ActionGroup::Make()
{
  return std::unique_ptr<ActionGroup>(new ActionGroup);
}

//ActionGroup Constructor (private)
ActionGroup::ActionGroup() : ActionBase() {}

//Updates the ActionGroup by bringing it closer to the endValue
//dt: Amount to Update the ActionGroup by
//Returns the leftover dt from the last call to ActionBase::Update
float ActionGroup::SpecializedUpdate(float dt)
{
  //The leftover dt to return
  //Will be set to the last call to ActionBase::Update
  //(-1.f if ActionGroup isn't complete, 0 < leftoverDt < dt if complete)
  float leftoverDt = -1.f;

  //Update ActionBases via pointer in the list. Erase element if it is complete
  std::list<std::unique_ptr<ActionBase>>::iterator it = actionBases.begin();
  while(it != actionBases.end())
  {
    std::unique_ptr<ActionBase> & action = *it;
    if(action->IsComplete())
      it = actionBases.erase(it);
    else
    {
      leftoverDt = action->Update(dt);
      ++it;
    }
  }

  //If the Group is empty, flag it for erasion
  if(actionBases.empty())
  {
    SetComplete(true);
    SetPaused(true);
  }

  return leftoverDt;
}

//Pushes an ActionBase pointer into the ActionGroup 
//and sets relevant paused/complete information
//action: Pointer to the ActionBase to add
void ActionGroup::Add(std::unique_ptr<ActionBase> action)
{
  SetPaused(false);
  SetComplete(false);
  actionBases.push_back(std::move(action));
  actionBases.back()->SetPaused(false);
}