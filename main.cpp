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
int durMins = 1;
Vector pos;
bool isTimeUp;

//Score
int score;

int game_mode;
#define SELECT_DOOR 0
#define SCARE_ROOM  1
#define GAME_OVER 2

void initTimer() {
	durMins = durationMins;
	currMin = durMins;
	currSec = 0;
	pos.x = 0; pos.y = 0; pos.z = roomSize - 10;
	timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	glutTimerFunc(1000, decTime, 0);
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
void drawText(string text, float x, float y) {
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2i(x, y);
	std::string s = text;
	void * font = GLUT_BITMAP_TIMES_ROMAN_24;

	for (std::string::iterator i = s.begin(); i != s.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSwapBuffers();

}
void drawTime() {
	std::string secs = std::to_string(currSec);
	std::string mins = std::to_string(currMin);
	std::string time = mins + " : " + secs;
	drawText(time, 900, 650);
}
void drawScore() {
	std::string sc = "SCORE  "+ std::to_string(score);
	drawText(sc, 700, 650);
}


void initGame(){
    //initialize game objects
    game_mode = SELECT_DOOR;
	score = 2000;
}

void playSound(string filename, bool loop, float volume) {
	string path = "assets/sounds/" + filename + ".mp3";
	ISound *s = soundEngine->play2D(path.c_str(), loop, false, true, ESM_AUTO_DETECT, false);
	s->setVolume(volume);
}

void key(unsigned char k, int x,int y){
	if (game_mode == SELECT_DOOR) {
		if (k == '1') {
			//whichRoom = 1;
			game_mode = SCARE_ROOM;
			initTimer();
			playSound("tefl-adamy", false, 1);
			glutPostRedisplay();
		}
		if (k == '2') {
			//whichRoom = 2;
			game_mode = SCARE_ROOM;
			initTimer();
			playSound("tefl-adamy", false, 1);
			glutPostRedisplay();
		}
		if (k == '3') {
			//whichRoom = 3;
			game_mode = SCARE_ROOM;
			initTimer();
			playSound("tefl-adamy", false, 1);
			glutPostRedisplay();
		}

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
		playSound("7alet-taware2", false, 1);
		score -= 100;
		//TODO if score <=0
	}
	glutPostRedisplay();
}
void passM(int mouseX,int mouseY){

	if (game_mode == SELECT_DOOR) return;
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


void anim(){
	if (game_mode == SCARE_ROOM) {
		if (isTimeUp)
		{
			isTimeUp = false;
		}
		scareScene.target.grow();
	}
	glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (game_mode == SCARE_ROOM) {
		drawTime();
		drawScore();
	}
	glPushMatrix();
	cam.setUp();
	light.setUp();
	if (game_mode == SELECT_DOOR) {
		firstScene.draw();
	}
	else {
		scareScene.draw();
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
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

	playSound("main", true, 0.2);
    glutMainLoop();

}
