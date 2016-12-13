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

#include "scenes\scareScene.hpp"
#include "controllers\camera.hpp"
#include "controllers\lights.hpp"
#include "timer.hpp"

// Game Variables
ScareScene scareScene;
Camera cam;
Lights light;
Timer timer;
Vector oldMouse;
ISoundEngine* soundEngine = createIrrKlangDevice();


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
	scareScene.target.grow();
	glutPostRedisplay();
}
void display(){

	cam.setUp();
	light.setUp();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scareScene.draw();
  glutTimerFunc(1000, timer->decTime, 0);
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

	scareScene.loadImages();

	playSound("main", true);
    glutMainLoop();

}
