#include "Bed.hpp"

Bed::Bed() : GameItem("newBed/Bed") {
	size = 70;
	scaleModel = 0.008;
	rot = 90;

	centerPoint.x = 0;
	centerPoint.y = -50;
	centerPoint.z = roomSize - 30;
}
