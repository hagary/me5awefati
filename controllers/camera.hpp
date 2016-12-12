//
//  camera.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#pragma once
#ifndef camera_hpp
#define camera_hpp

#include "Vector.h"
#include "constants.h"

class Camera{
public:
	Camera();
	Vector eye;
	Vector dest;
	Vector up;
	Vector initDest;
	double angle;
    void setUp();
};
#endif /* camera_hpp */
