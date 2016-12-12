
//
//  room.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "room.hpp"

void Room::draw() {
	
	int size = roomSize;
	glPushMatrix();
	glTranslated(-size / 2, -size / 2, 0);

	// Front
	glBindTexture(GL_TEXTURE_2D, wallID);
	drawWall(size, 0, 0, 0, 0, 0, 0, 0);

	// Back Wall
	drawWall(size, 2, 0, 1, 0, 1, 0, 1);

	// Left Wall
	drawWall(size, 1, 0, 1, 0, 0, 0, 1);

	// Right Wall
	drawWall(size, -1, 0, 1, 0, 1, 0, 0);

	// Bot Wall
	glBindTexture(GL_TEXTURE_2D, floorID);
	drawWall(size, -1, 1, 0, 0, 0, 0, 1);

	// Up Wall
	glBindTexture(GL_TEXTURE_2D, ceilID);
	drawWall(size, 1, 1, 0, 0, 0, 1, 0);

	glPopMatrix();
}

void drawWall(float size, int dir, bool rotX, bool rotY, bool rotZ, bool transX, bool transY, bool transZ) {

	glPushMatrix();

	glTranslated(size * transX, size * transY, size * transZ);
	glRotated(90 * dir, rotX, rotY, rotZ);

	glBegin(GL_QUADS);

	glNormal3f(0, 0, 1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0, 0);

	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0, size);

	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(size, size);

	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(size, 0);

	glEnd();
	glPopMatrix();
}