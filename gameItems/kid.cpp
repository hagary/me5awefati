
//  kid.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "kid.hpp"

Kid::Kid() : GameItem("mostafa/boy") {
	size = 1;
	scaleModel = 0.2;
	rot = 180;
	rotX = -90;
	rotZ = -20;
	centerPoint.x = -25;
	centerPoint.y = -41;
	centerPoint.z = roomSize - 35;
}