#pragma once

#ifndef TIME
#define TIME
#include <glut.h>
#include <string>
#include "Vector.h"
#include "constants.h"

void initTimer();
void drawTime();
void decTime(int);
#endif
