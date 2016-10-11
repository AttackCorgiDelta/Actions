//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTIONSEQUENCE_H
#define ACTIONSEQUENCE_H

#include <queue>        //queue
#include "ActionBase.h" //ActionBase

//Holds a number of pointers to ActionBases that are updated sequentially
//Note: Can only be dynamically allocated
class ActionSequence final : public ActionBase
{
public:
  static ActionSequence * Make();

  ~ActionSequence();

  float Update(float dt) override;

  void Push(ActionBase * action);

private:
  ActionSequence();

  //ActionSequence and associated classes are not meant to be copied
  ActionSequence & operator=(const ActionSequence &) = delete;
  ActionSequence(const ActionSequence &) = delete;
  
  //Container of pointers to ActionBases to be updated 
  std::queue<ActionBase *> actionBases; 
};

#endif //ACTIONSEQUENCE_H