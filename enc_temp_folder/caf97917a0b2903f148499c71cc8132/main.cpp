//
//  main.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//
#include "scenes\scareScene.hpp"
#include "controllers\camera.hpp"
#include "controllers\lights.hpp"

// Game Variables
ScareScene scareScene;
Camera cam;
Lights light;

int game_mode;
#define SELECT_DOOR 0;
#define SCARE_ROOM  1;

void initGame(){
    //initialize game objects
    game_mode = SELECT_DOOR;
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
	glutPostRedisplay();
}
void passM(int mouseX,int mouseY){
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
	glutSwapBuffers();
	glFlush();
}

GLuint loadTexture() {

	GLuint tex_2d = SOIL_load_OGL_texture
		(
			"main-wall.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	/* check for an error during the load process */
	if (0 == tex_2d)
	{
		printf("SOIL loading error: '%s'\n", SOIL_last_result());
	}
	return tex_2d;
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
    glutMainLoop();

}
