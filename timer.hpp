#pragma once
#include <glut.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"
class Timer{
public:
  Timer();
  void drawTime();
  void calcTime();
  long timeSinceStart; //millisecs
private:
  int currMin;
  int currSec;
  int durMins;
  Vector pos;
}
