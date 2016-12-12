//
//  toy.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "toy.hpp"
Toy::Toy(std::string path, Vector center) : GameItem(path) {
	size = 5;
	scaleModel = 0.005;
	rot = -90;

	centerPoint = center;
}