#include "Bed.hpp"

Bed::Bed() : GameItem("newBed/Bed") {
	size = 60;
	scaleModel = 0.008;
	rot = 90;

	centerPoint.x = -25;
	centerPoint.y = -50;
	centerPoint.z = roomSize - 25;
}
