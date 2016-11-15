//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTIONSEQUENCE_H
#define ACTIONSEQUENCE_H

#include <queue>        //queue
#include <memory>       //unique_ptr
#include "ActionBase.h" //ActionBase

//Holds a number of pointers to ActionBases that are updated sequentially
//Note: Can only be dynamically allocated
class ActionSequence final : public ActionBase
{
public:
  static std::unique_ptr<ActionSequence> Make();

  void Add(std::unique_ptr<ActionBase> action);

private:
  ActionSequence();

  float SpecializedUpdate(float dt) override;

  //ActionSequence and associated classes are not meant to be copied
  ActionSequence & operator=(const ActionSequence &) = delete;
  ActionSequence(const ActionSequence &) = delete;
  
  //Container of pointers to ActionBases to be updated 
  std::queue<std::unique_ptr<ActionBase>> actionBases; 
};

#endif //ACTIONSEQUENCE_H