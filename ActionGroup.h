//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTIONGROUP_H
#define ACTIONGROUP_H

#include <list>         //list
#include <memory>
#include "ActionBase.h" //ActionBase

//Holds a number of pointers to ActionBases which are all updated simultaneously
//Note: Can only be dynamically allocated
class ActionGroup final : public ActionBase
{
public:
  static std::unique_ptr<ActionGroup> Make();

  void Add(std::unique_ptr<ActionBase> action);

private:
  ActionGroup();

  float SpecializedUpdate(float dt) override;

  //ActionGroup and associated classes are not meant to be copied
  ActionGroup & operator=(const ActionGroup &) = delete;
  ActionGroup(const ActionGroup &) = delete;

  //Container of pointers to ActionBases to be updated 
  std::list<std::unique_ptr<ActionBase>> actionBases;
};

#endif //ACTIONGROUP_H