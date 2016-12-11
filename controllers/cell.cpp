//
//  cell.cpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#include "cell.hpp"

Cell::Cell(){
	this->size = cellSize;
}

void Cell::assignItem(GameItem g) {
	this->gameItem = g;
}
