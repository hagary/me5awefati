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
	Vector centerPoint;
	double size;

private:
	double min;
	double max;
	double growFactor;
	bool growing;
};

