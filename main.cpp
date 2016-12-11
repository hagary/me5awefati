//
//  main.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//
#include <iostream>
#include "constants.h"
#include <GLUT/glut.h>

int game_mode;
#define SELECT_DOOR = 0;
#define SCARE_ROOM  = 1;

void initGame(){
    //initialize game objects
    game_mode = SELECT_DOOR;
}
void key(unsigned char k, int x,int y){
}
void spe(int k, int x,int y){
}
void passM(int mouseX,int mouseY){
}
void anim(){
}
void display(){
    
}
int main(int argc, const char * argv[]) {
    initGame();
    
    //GLUT methods
    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Me5awefati");
    glutFullScreen();
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
    glShadeModel(GL_SMOOTH);
    glutMainLoop();
    
    return 0;
}
