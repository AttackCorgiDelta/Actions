//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionSequence.h"

//ActionSequence Static "Constructor" (public)
//Dynamically allocates an ActionSequence
std::unique_ptr<ActionSequence> ActionSequence::Make()
{
  return std::unique_ptr<ActionSequence>(new ActionSequence);
}

//ActionSequence Constructor (private)
ActionSequence::ActionSequence() : ActionBase() {}

//Updates the ActionSequence by bringing it closer to the endValue
//dt: Amount to Update the ActionSequence by
//Returns the leftover dt when this ActionSequence completes
float ActionSequence::SpecializedUpdate(float dt)
{
  //Update the ActionBase pointed to by the top of the queue
  //and update while recycling the dt from completed calls to Update
  while(dt > 0.f)
  {
    //Get the top of the ActionBase queue and call Update,
    //setting dt to the result of the call
    std::unique_ptr<ActionBase> & top = actionBases.front();
    dt = top->Update(dt);

    //Pop this ActionBase off of the queue if it's complete
    if(top->IsComplete())
      actionBases.pop();

    //If the Sequence is empty, flag it for erasion
    if(actionBases.empty())
    {
      SetComplete(true);
      SetPaused(true);
      return dt;
    }
    else //Unpause the next Action
      actionBases.front()->SetPaused(false);
  }

  return -1.f;
}

//Inserts an ActionBase pointer at the end of the ActionSequence and 
//sets relevant paused/complete information
//action: Pointer to the ActionBase to add
void ActionSequence::Add(std::unique_ptr<ActionBase> action)
{
  SetPaused(false);
  SetComplete(false);
  actionBases.push(std::move(action));
  actionBases.back()->SetPaused(true);
}