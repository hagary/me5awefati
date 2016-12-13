//
//  door.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright Â© 2016 Hagar Yasser Omar. All rights reserved.
//

#include "door.hpp"
#include "controllers\room.hpp"

Door::Door() {
	size = 1;
	scaleModel = 0.001;
	rot = 180;

	centerPoint.x = 0;
	centerPoint.y = -roomSize / 2.5;
	centerPoint.z = 25;
}

void Door::draw(double xTrans) {
	centerPoint.x = xTrans;
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID);
	glTranslatef(xTrans, centerPoint.y, centerPoint.z);
	glPushMatrix();
	glScalef(7, 14, 2);
	glRotated(180, 0, 1, 0);
	glPushMatrix();
	//glPushMatrix();
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
	glPopMatrix();
	glPopMatrix();
}
