//
//  scareScene.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "scareScene.hpp"

ScareScene::ScareScene() {

	toys[0] = Toy("toy1/toy1", Vector(10, -50, roomSize - 40));
	toys[1] = Toy("toy2/Robot", Vector(0, -50, roomSize - 20));
	toys[2] = Toy("toy2/Robot", Vector(-10, -50, roomSize - 15));
	toys[3] = Toy("toy1/toy1", Vector(20, -50, roomSize - 30));

}

void ScareScene::loadImages() {
	room.ceilID = loadTexture("boy-wall.jpg");
	room.wallID = loadTexture("boy-wall.jpg");
	room.floorID = loadTexture("room-floor.jpg");
	target.redID = loadTexture("red.jpg");
}

void ScareScene::draw() {
	room.draw(roomSize);
	bed.draw();
	kid.draw();

	for (size_t i = 0; i < NUM_TOYS; i++)
	{
		toys[i].draw();
	}
	wardrobe.draw();
	monster.draw();
	target.draw();
}

bool ScareScene::isToyCollision() {

	for (size_t i = 0; i < NUM_TOYS; i++)
	{
		int lowerBoundX = toys[i].centerPoint.x - toys[i].size;
		int upperBoundX = toys[i].centerPoint.x + toys[i].size;
		int lowerBoundZ = toys[i].centerPoint.z - toys[i].size;
		int upperBoundZ = toys[i].centerPoint.z + toys[i].size;

		if (monster.centerPoint.x >= lowerBoundX
			&& monster.centerPoint.x <= upperBoundX
			&& monster.centerPoint.z >= lowerBoundZ
			&& monster.centerPoint.z <= upperBoundZ)
			return true;
	}

	return false;
}

bool ScareScene::isTargetCollision() {

	int lowerBoundX = target.centerPoint.x - target.size;
	int upperBoundX = target.centerPoint.x + target.size;
	int lowerBoundZ = target.centerPoint.z - target.size;
	int upperBoundZ = target.centerPoint.z + target.size;

	if (monster.centerPoint.x >= lowerBoundX
		&& monster.centerPoint.x <= upperBoundX
		&& monster.centerPoint.z >= lowerBoundZ
		&& monster.centerPoint.z <= upperBoundZ)
		return true;

	return false;
}

bool ScareScene::isObjectCollision() {

	int lowerBoundX = bed.centerPoint.x - bed.size;
	int upperBoundX = bed.centerPoint.x + bed.size;
	int lowerBoundZ = bed.centerPoint.z - bed.size;
	int upperBoundZ = bed.centerPoint.z + bed.size;

	if (monster.centerPoint.x >= lowerBoundX
		&& monster.centerPoint.x <= upperBoundX
		&& monster.centerPoint.z >= lowerBoundZ
		&& monster.centerPoint.z <= upperBoundZ)
		return true;

	 lowerBoundX = wardrobe.centerPoint.x - wardrobe.size;
	 upperBoundX = wardrobe.centerPoint.x + wardrobe.size;
	 lowerBoundZ = wardrobe.centerPoint.z - wardrobe.size;
	 upperBoundZ = wardrobe.centerPoint.z + wardrobe.size;

	if (monster.centerPoint.x >= lowerBoundX
		&& monster.centerPoint.x <= upperBoundX
		&& monster.centerPoint.z >= lowerBoundZ
		&& monster.centerPoint.z <= upperBoundZ)
		return true;

	return false;
}
