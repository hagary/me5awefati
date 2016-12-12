#include "Wardrobe.hpp"



Wardrobe::Wardrobe() :GameItem("wardrobe/Wardrobe"){
	size = 80;
	scaleModel = 0.002;
	rot = -90;
	centerPoint.x = 40;
	centerPoint.y = -50;
	centerPoint.z = roomSize - 40;
}

