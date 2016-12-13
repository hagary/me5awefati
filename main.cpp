//
//  main.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include <irrKlang\irrKlang.h>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib")

#include "scenes\mainScene.hpp"
#include "scenes\scareScene.hpp"
#include "controllers\camera.hpp"
#include "controllers\lights.hpp"
#include "timer.hpp"

// Game Variables
mainScene firstScene;
ScareScene scareScene;
Camera cam;
Lights light;
Vector oldMouse;
ISoundEngine* soundEngine = createIrrKlangDevice();


// Timer
long timeSinceStart; //millisecs
int currMin;
int currSec;
int durMins = 2;
Vector pos;
bool isTimeUp;


void initTimer() {
	durMins = durationMins;
	currMin = durMins;
	currSec = 0;
	pos.x = -30; pos.y = roomSize / 2 - 10; pos.z = -roomSize / 2 + 10;
}
void decTime(int value) {
	if (currSec == 0 && currMin == 0)
	{
		//TODO DO SOMETHING -> UPDATE GAME MODE
		isTimeUp = true;

		return;
	}
	if (currSec == 0) {
		currSec = 59;
		currMin--;
	}
	else
		currSec--;
	glutTimerFunc(1000, decTime, 0);
}

void drawTime() {
	std::string secs = std::to_string(currSec);
	std::string mins = std::to_string(currMin);
	std::string time = mins + " : " + secs;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glRasterPos3f(pos.x, pos.y, pos.z);
	for (unsigned int i = 0; i<time.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time[i]);
	}
	glPopMatrix();
}

//int which_room = 0;
int game_mode;
#define SELECT_DOOR 0;
#define SCARE_ROOM  1;

void initGame(){
    //initialize game objects
    game_mode = SELECT_DOOR;
}

void playSound(string filename, bool loop) {
	string path = "assets/sounds/" + filename + ".mp3";
	soundEngine->play2D(path.c_str(), loop);
}

void key(unsigned char k, int x,int y){
	if (game_mode == 0) {
		if (k == '1') {
			//whichRoom = 1;
			game_mode = 1;
			glutPostRedisplay();
		}
		if (k == '2') {
			//whichRoom = 2;
			game_mode = 1;
			glutPostRedisplay();
		}
		if (k == '3') {
			//whichRoom = 3;
			game_mode = 1;
			glutPostRedisplay();
		}
		initTimer();
	}
}
void spe(int k, int x,int y){
	switch (k){
		case GLUT_KEY_RIGHT :
			scareScene.monster.moveR();
			break;
		case GLUT_KEY_LEFT:
			scareScene.monster.moveL();
			break;
		case GLUT_KEY_UP:
			scareScene.monster.moveF();
			break;
		case GLUT_KEY_DOWN:
			scareScene.monster.moveB();
			break;
	}

	if (scareScene.isCollision())
	{
		scareScene.monster.reset();
		playSound("7alet-taware2", false);
	}
	glutPostRedisplay();
}
void passM(int mouseX,int mouseY){

	if (game_mode == 0) return;
	mouseX = mouseX - windowWidth/2;
	mouseY = windowHeight - mouseY + windowHeight / 2;
	int changeX = mouseX - oldMouse.x;
	int changeY = mouseY - oldMouse.y;

	cam.dest.x -= changeX * 0.15;
	cam.dest.y += changeY * 0.008;

	oldMouse.x = mouseX;
	oldMouse.y = mouseY;

	glutPostRedisplay();
}

void drawText(string text, float x, float y) {

	glPushMatrix();

	glNormal3d(0, 0, -1);
	glColor3d(1, 1, 1);
	glRasterPos3f(x, y, 6);
	for (unsigned int i = 0; i< text.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

	glPopMatrix();

}

void anim(){
	if (game_mode == 1) {
		if (isTimeUp)
		{
			isTimeUp = false;
		}
		scareScene.target.grow();
	}
	glutPostRedisplay();
}

void display(){

	cam.setUp();
	light.setUp();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (game_mode == 0) {
		firstScene.draw();
	}
	else {
		scareScene.draw();
		drawTime();
		glutTimerFunc(1000, decTime, 0);
	}

	glFlush();
}

void main(int argc, char** argv){
	initGame();

    //GLUT methods
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Me5awefati");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(spe);
    glutPassiveMotionFunc(passM);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glutIdleFunc(anim);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_SHININESS);
	glEnable(GL_COLOR_MATERIAL_FACE);
	glShadeModel(GL_SMOOTH);

	firstScene.loadImages();
	scareScene.loadImages();

	playSound("main", true);
    glutMainLoop();

}
