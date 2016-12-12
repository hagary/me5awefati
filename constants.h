//  constants.h
//  Me5awefati

#pragma once
#ifndef CONSTANTS
#define CONSTANTS

#define windowWidth 1024
#define windowHeight 720

//Room
#define roomSize 1000

// Grid
#define cellSize 20
#define numCells (roomSize / cellSize)

//Camera
const double fovy = 90;
const double aspectRatio = ((double)windowWidth - 200)/ (double)windowHeight;
const double zNear = 0.001;
const double zFar = roomSize + 50;

#endif