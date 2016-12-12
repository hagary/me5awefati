//
//  scareScene.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "scareScene.hpp"

ScareScene::ScareScene() {

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
	toy.draw();
	wardrobe.draw();
	monster.draw();
	target.draw();
}
