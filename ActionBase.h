//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTIONBASE_H
#define ACTIONBASE_H

//Base class for Action, ActionGroup, and ActionSequence
//Cannot be directly instanciated
class ActionBase
{
public:
  virtual float Update(float dt) = 0;

  bool IsComplete() const;

  bool IsPaused() const;
  void SetPaused(const bool isPaused);

  virtual ~ActionBase() {}

protected:
  ActionBase();
  void SetComplete(const bool isComplete);

private:
  //ActionBase and associated classes are not meant to be copied
  ActionBase & operator=(const ActionBase &) = delete;
  ActionBase(const ActionBase &) = delete;

  bool complete; //Whether the Action has completed its ease
  bool paused;   //Whether the Action will continue to ease on Update
};

#endif //ACTIONBASE_H