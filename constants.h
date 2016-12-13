//  constants.h
//  Me5awefati

#pragma once
#ifndef CONSTANTS
#define CONSTANTS

#define windowWidth 1024
#define windowHeight 720

//Room
#define roomSize 100

// Grid
#define cellSize 1
#define numCells (roomSize / cellSize)

//Camera
const double fovy = 70;
const double aspectRatio = (double)windowWidth/ (double)windowHeight;
const double zNear = 0.001;
const double zFar = roomSize + 50;


// Light
const double ambient = 0.2;
const double ambient_mainScene = 0.09;

// Toys
#define NUM_TOYS 4

//Timer
const int durationMins = 2;

#endif
