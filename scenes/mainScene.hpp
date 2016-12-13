//
//  mainScene.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef mainScene_hpp
#define mainScene_hpp

#include <stdio.h>
#include "gameItems\door.hpp"
#include "controllers\room.hpp"

class mainScene{
public:
	mainScene();
	Room firstRoom;
	Door door1;
	Door door2;
	Door door3;
	GLUquadric* holder;
    void draw();
	void drawHolder();
};
#endif /* mainScene_hpp */