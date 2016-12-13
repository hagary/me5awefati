//
//  mainScene.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "mainScene.hpp"

mainScene::mainScene() {

}

void mainScene::drawHolder() {
	glPushMatrix();
	glTranslated(0, -roomSize/3.5, 2);
	glColor3f(0.5,  0.5, 0.5);
	gluCylinder(holder, 2, 2, 10, 10, 10);
	glPopMatrix();
}

void mainScene::loadImages() {
	firstRoom.floorID = loadTexture("main-floor.jpg");
	firstRoom.wallID = loadTexture("main-wall.jpg");
	firstRoom.ceilID = loadTexture("main-wall.jpg");

	door1.texID = loadTexture("door-blue.png");
	door2.texID = loadTexture("door-pink.png");
	door3.texID = loadTexture("door-grey.png");
}

void mainScene::draw() {

	GLfloat l0Diffuse[] = { 0.5, 0.5, 0.5 };
	GLfloat l0Ambient[] = { ambient_mainScene , ambient_mainScene , ambient_mainScene, 1.0f };
	GLfloat l0Position[] = { 0, -10, 5 , 1 };
	GLfloat l0Direction[] = { 0.0f, -30.0f, 50 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, l0Position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l0Direction);

	////Light fot the door
	//GLfloat l2Diffuse[] = { 0.5, 0.5, 0.5 };
	//GLfloat l2Ambient[] = { 0.1 , 0.1, 0.1, 1.0f };
	//GLfloat l2Position[] = { 0, -20, 4, 1 };
	//GLfloat l2Direction[] = { 0.0f, -30.0f, 5.0f };
	//glLightfv(GL_LIGHT2, GL_DIFFUSE, l2Diffuse);
	//glLightfv(GL_LIGHT2, GL_AMBIENT, l2Ambient);
	//glLightfv(GL_LIGHT2, GL_POSITION, l2Position);
	//glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30);
	//glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 1.0f);
	//glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l2Direction);
	
	firstRoom.draw(roomSize);

	door1.draw(15.0);
	door2.draw(3.0);
	door3.draw(-10.0);
}