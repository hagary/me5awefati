
//
//  room.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "room.hpp"

void Room::draw(double size) {
	
	glPushMatrix();
	glTranslatef(-size / 2, -size / 2, 0);
	glScalef(size, size/aspectRatio, size);

	// Front
	glBindTexture(GL_TEXTURE_2D, wallID);
	drawWall(0, 0, 0, 0, 0, 0, 0);

	// Back Wall
	drawWall(2, 0, 1, 0, 1, 0, 1);

	// Left Wall
	drawWall(1, 0, 1, 0, 0, 0, 1);

	// Right Wall
	drawWall(-1, 0, 1, 0, 1, 0, 0);

	// Bot Wall
	glBindTexture(GL_TEXTURE_2D, floorID);
	drawWall(-1, 1, 0, 0, 0, 0, 1);

	// Up Wall
	glBindTexture(GL_TEXTURE_2D, ceilID);
	drawWall(1, 1, 0, 0, 0, 1, 0);

	glPopMatrix();
}

void drawWall(int dir, bool rotX, bool rotY, bool rotZ, bool transX, bool transY, bool transZ) {

	glPushMatrix();

	glTranslated(transX, transY, transZ);
	glRotated(90 * dir, rotX, rotY, rotZ);

	glBegin(GL_QUADS);

	glNormal3f(0, 0, 1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0, 0);

	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0, 1);

	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(1, 1);

	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(1, 0);

	glEnd();
	glPopMatrix();
}