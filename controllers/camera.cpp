//
//  camera.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "camera.hpp"

Camera::Camera() {
	eye = Vector(0, -roomSize/3.5, 0);
	initDest = dest = Vector(0, -roomSize/3.5, roomSize - roomSize / 10);
	up = Vector(0, 1, 0);
}

void Camera::setUp() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, aspectRatio, zNear, zFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(eye.x, eye.y, eye.z, dest.x, dest.y, dest.z, up.x, up.y, up.z);
}
