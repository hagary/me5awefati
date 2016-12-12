//
//  monster.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "monster.hpp"
Monster::Monster() : GameItem("mared/mared") {
	size = 25;
	scaleModel = 0.2;
	initP.x = centerPoint.x = -1;
	initP.y = centerPoint.y = -0.51 * roomSize;
	initP.z = centerPoint.z = roomSize / 3;
	rot = -53 + dir;
	step = 1;
}
void Monster::moveF(){
	centerPoint.z += step;
	if (centerPoint.z > roomSize - 5)
		centerPoint.z = roomSize - 5;
	dir = 0;
	rot = -53 + dir;
}
void Monster::moveB() {
	centerPoint.z -= step;
	if (centerPoint.z < initP.z)
		centerPoint.z = initP.z;
	dir = 180;
	rot = -53 + dir;
}
void Monster::moveL() {
	centerPoint.x += step;
	if (centerPoint.x > roomSize/2 - 5)
		centerPoint.x = roomSize/2 - 5;
	dir = -270;
	rot = -53 + dir;
}
void Monster::moveR() {
	centerPoint.x -= step;
	if (centerPoint.x < -roomSize / 2 + 5)
		centerPoint.x = -roomSize / 2 + 5;
	dir = -90;
	rot = -53 + dir;
}

void Monster::reset() {
	centerPoint = initP;
	rot = -53;
}