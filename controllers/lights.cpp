//
//  lights.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "lights.hpp"

void Lights::setUp() {

	GLfloat l0Diffuse[] = { 0, 0, 0.4 };
	GLfloat l0Ambient[] = { ambient , ambient ,ambient, 1.0f };
	GLfloat l0Position[] = { 0, 30, 30 , 1 };
	GLfloat l0Direction[] = { 0.0f, -50.0f, 30.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, l0Position);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0f);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, l0Direction);
}