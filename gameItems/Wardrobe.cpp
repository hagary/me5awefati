#include "Wardrobe.hpp"



Wardrobe::Wardrobe() :GameItem("wardrobe/Wardrobe"){
	size = 70;
	scaleModel = 0.002;
	rot = -90;

	centerPoint.x = 45;
	centerPoint.y = -50;
	centerPoint.z = roomSize - 30;
}

