//
//  toy.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "toy.hpp"
Toy::Toy() : GameItem("toy1/toy1") {
	size = 5;
	scaleModel = 0.005;
	rot = -90;

	centerPoint.x = -30;
	centerPoint.y = -50;
	centerPoint.z = roomSize - 40;
}