//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include "ActionSequence.h"

//ActionSequence Static "Constructor" (public)
//Note: Dynamically allocates an ActionSequence
ActionSequence * ActionSequence::Make()
{
  return new ActionSequence;
}

//ActionSequence Constructor (private)
ActionSequence::ActionSequence() : ActionBase() {}

//ActionSequence Destructor
ActionSequence::~ActionSequence()
{
  while(!actionBases.empty())
  {
    delete actionBases.front();
    actionBases.pop();
  }
}

//Updates the ActionSequence by bringing it closer to the endValue
//dt: Amount to Update the ActionSequence by
//Returns the leftover dt when this ActionSequence completes
float ActionSequence::Update(float dt)
{
  //Return if the Sequence is paused
  if(IsPaused()) 
    return -1.f;

  //Update the ActionBase pointed to by the top of the queue
  //and update while recycling the dt from completed calls to Update
  while(dt > 0.f)
  {
    //Get the top of the ActionBase queue and call Update
    ActionBase * top = actionBases.front();
    dt = top->Update(dt);

    //Pop and delete this ActionBase off of the queue if it's complete
    //Unpause the next Action
    if(top->IsComplete())
    {
      actionBases.pop();
      delete top;
      actionBases.front()->SetPaused(false);
    }

    //If the Sequence is empty, flag it for erasion
    if(actionBases.empty())
    {
      SetComplete(true);
      SetPaused(true);
      return dt;
    }
  }

  return -1.f;
}

//Inserts an ActionBase pointer at the end and sets relevant paused information
//actionBase: Pointer to the ActionBase to add
void ActionSequence::Push(ActionBase * action)
{
  SetPaused(false);
  action->SetPaused(true);
  actionBases.push(action);
}