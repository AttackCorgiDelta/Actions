//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

#include <cstdio>           //printf
#include <chrono>           //high_resolution_clock, time_point, duration, duration_cast
#include "Action.h"         //Action
#include "ActionSequence.h" //ActionSequence
#include "ActionGroup.h"    //ActionGroup
#include "Ease.h"           //Ease::Function typedef, any Ease functions

typedef std::chrono::high_resolution_clock testClock;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> timePoint;
typedef std::chrono::duration<float> fSeconds;

void TestEase(Ease::Function fn, bool realTime = true);

int main()
{
  TestEase(Ease::OutQuad, true);
}

//Creates a single variable Action which tweens a float from startVal to endVal
//fn: Function used for easing
//startVal: Initial value of eased value
//endVal: End value of eased value
void TestEase(Ease::Function fn, bool realTime)
{
  float x = 0;
  Action * action = Action::Make(x, 100.f, 1.f, fn);
  
  float time = 0.f;
  float timeLast;
  float dt;
  timePoint epoch = testClock::now();
  int num = 1;

  std::printf("%9.4f %7.4f\n", x, time);
  while(time < 1.f)
  {
    if(static_cast<int>(time * 100.f) % 2 == num)
    {
      if(num == 0)
        num = 1;
      else
        num = 0;
      std::printf("%9.4f %7.4f\n", x, time);  
    }

    timeLast = time;
    if(realTime)
    {
      time += std::chrono::duration_cast<fSeconds>(testClock::now() - epoch).count();
      epoch = testClock::now();
      dt = time - timeLast;
    }
    else
      dt = 1.f/60.f;

    action->Update(dt);
  }

  std::printf("%9.4f %7.4f\n", x, time);

  delete action;
}