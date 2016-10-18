//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include <cstdio>           //printf
#include "Action.h"         //Action
#include "ActionSequence.h" //ActionSequence
#include "ActionGroup.h"    //ActionGroup
#include "Ease.h"           //Ease::Function typedef, any Ease functions

void TestEase(Ease::Function fn);
void TestGroup();

int main()
{
  //TestEase(Ease::OutQuad);
  TestGroup();
}

//Creates a single variable Action which tweens a float from startVal to endVal
//fn: Function used for easing
void TestEase(Ease::Function fn)
{
  //Create a value, and an action to ease it to a target
  float x = 0;
  Action * action = Action::Make(x, 100.f, 1.f, fn);
  
  const float dt = 1.f/60.f;
  float time = 0.f;

  while(time < 0.99f)
  {
    //Print out the current value of x and the time
    std::printf("%9.4f %7.4f\n", x, time);

    time += dt;

    //Increment x closer to its destination
    action->Update(dt);
  }

  std::printf("%9.4f %7.4f\n", x, time);

  //Make sure we clean up our Action after creating it
  delete action;
}

void TestGroup()
{
  float n1 = 0.f, n2 = 0.f;

  //Create an ActionGroup that is in charge of easing n1 and n2
  ActionGroup * group = ActionGroup::Make();
  group->Add(Action::Make(n1, 100.f, 1.f, Ease::Linear));
  group->Add(Action::Make(n2, 100.f, 1.f, Ease::InQuad));

  const float dt = 1.f/60.f;
  float time = 0.f;

  while(time < 0.99f)
  {
    //Print out the current value of n1, n2, and the time
    std::printf("%9.4f %9.4f %7.4f\n", n1, n2, time);

    time += dt;

    //Increment n1 and n2 closer to their destination
    group->Update(dt);
  }

  std::printf("%9.4f %9.4f %7.4f\n", n1, n2, time);
  
  //Because deletion of the two child Actions is handled by the ActionGroup, we
  //don't have to worry about deleting the two Actions
  delete group;
}