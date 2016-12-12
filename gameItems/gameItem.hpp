#ifndef GAMEITEM
#define GAMEITEM

#include "Model_3DS.h"
#include "GLTexture.h"
#include "constants.h"
#include "Vector.h"
#include <string>

using namespace std;

class GameItem
{
public:
	GameItem() {};
	GameItem(string);

	Model_3DS model;
	Vector centerPoint;
	double scaleModel; // Fitting to Unit Cube
	double size; // Item Scaling
	double rot; // Item Rotation around Y
	double rotX; //rotation around x-axis
	double rotZ; //rotation around z-axis
	void draw();

};
#endif





