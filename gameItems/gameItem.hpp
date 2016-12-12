#include "Model_3DS.h"
#include "GLTexture.h"
#include "constants.h"
#include <string>

class GameItem
{
public:
	GameItem();
	GameItem(std::string);
	Model_3DS model;
	double scaleModel; // Fitting to Cube
	double size; // Cube Scaling

	void draw();

};

