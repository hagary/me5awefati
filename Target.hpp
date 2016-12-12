#pragma once
#include <glut.h>
#include "gameItems\gameItem.hpp"
#include "constants.h"
class Target
{
public:
	Target();
	void draw();
	void grow();
	int redID;
private:
	double min;
	double max;
	double size;
	double growFactor;
	bool growing;
};

