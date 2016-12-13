#pragma once
#include <glut.h>
#include <string>
#include "Vector.h"
#include "constants.h"

class Timer{
public:
  Timer();
  static void drawTime();
  static void decTime(int);
  static long timeSinceStart; //millisecs
  //static int currMin;
  //static int currSec;
  //static int durMins;
  //static Vector pos;
};