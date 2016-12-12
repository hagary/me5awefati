//
//  room.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include <glut.h>
#include "constants.h"

class Room {
public:
	Room(){};
	GLuint ceilID;
	GLuint wallID;
	GLuint floorID;

	void draw(double size);
};

void drawWall(int, bool, bool, bool, bool, bool, bool);

#endif /* room_hpp */
