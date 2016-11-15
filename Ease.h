//Author: Griffin Downs
//All content copyright (C) Griffin Downs 2016. All rights reserved.

//Based on Robert Penner's Easing functions
//http://robertpenner.com/easing/

//For diagrams of each Easing function's motion, visit:
//http://zero.digipen.edu/Tutorials/Scripting/UsingCustomEaseInActionsTutorial.html

#ifndef EASE_H
#define EASE_H

#include <cmath> //atan, sin, cos, pow, sqrt

namespace Ease {

//The form the functions in the Ease namespace take
typedef float(* Function)(float, float, float, float);

//t: current time
//b: start value
//c: change in value (total)
//d: duration (total)

float Linear(float t, float b, float c, float d);

float InQuad(float t, float b, float c, float d);
float OutQuad(float t, float b, float c, float d);
float InOutQuad(float t, float b, float c, float d);

float InCubic(float t, float b, float c, float d);
float OutCubic(float t, float b, float c, float d);
float InOutCubic(float t, float b, float c, float d);

float InQuart(float t, float b, float c, float d);
float OutQuart(float t, float b, float c, float d);
float InOutQuart(float t, float b, float c, float d);

float InQuint(float t, float b, float c, float d);
float OutQuint(float t, float b, float c, float d);
float InOutQuint(float t, float b, float c, float d);

float InSine(float t, float b, float c, float d);
float OutSine(float t, float b, float c, float d);
float InOutSine(float t, float b, float c, float d);

float InExpo(float t, float b, float c, float d);
float OutExpo(float t, float b, float c, float d);
float InOutExpo(float t, float b, float c, float d);

float InCirc(float t, float b, float c, float d);
float OutCirc(float t, float b, float c, float d);
float InOutCirc(float t, float b, float c, float d);

float InElastic(float t, float b, float c, float d);
float OutElastic(float t, float b, float c, float d);
float InOutElastic(float t, float b, float c, float d);

float InBack(float t, float b, float c, float d);
float OutBack(float t, float b, float c, float d);
float InOutBack(float t, float b, float c, float d);

float InBounce(float t, float b, float c, float d);
float OutBounce(float t, float b, float c, float d);
float InOutBounce(float t, float b, float c, float d);

} //namespace Ease

#endif 