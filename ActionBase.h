//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#ifndef ACTIONBASE_H
#define ACTIONBASE_H

//Base class for Action, ActionGroup, and ActionSequence
//Cannot be directly instanciated
class ActionBase
{
  typedef void(*CALLBACK)();
public:
  virtual ~ActionBase() {}

  float Update(float dt);

  void SetCallBack(CALLBACK callBack);
  CALLBACK GetCallBack();

  float GetDelay() const;
  void SetDelay(const float delay_);

  bool IsComplete() const;
  void SetComplete(const bool isComplete);

  bool IsPaused() const;
  void SetPaused(const bool isPaused);

protected:
  ActionBase();

private:
  //Called by Update. Brings the ActionBase closer to completion
  //Classes inheriting this method must define what "complete" means
  //E.g. their container of ActionBases being complete, or completion of
  //an Easing function
  //dt: the amount to update the ActionBase by
  virtual float SpecializedUpdate(float dt) = 0;

  //ActionBase and associated classes are not meant to be copied
  ActionBase & operator=(const ActionBase &) = delete;
  ActionBase(const ActionBase &) = delete;

  CALLBACK callBack; //Function called once the ActionBase is complete
  float delay;       //The delay before the ActionBase will be unpaused
  bool complete;     //Whether the ActionBase has completed its Ease
  bool paused;       //Whether the ActionBase will continue to Ease on Update
};

#endif //ACTIONBASE_H