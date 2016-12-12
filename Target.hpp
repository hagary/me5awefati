#pragma once
#include <glut.h>
#include "constants.h"
class Target
{
public:
	Target();
	void draw();
	void grow();
private:
	double min;
	double max;
	double size;
	double growFactor;
	bool growing;
};

