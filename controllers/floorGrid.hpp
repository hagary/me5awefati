//
//  floorGrid.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef floorGrid_hpp
#define floorGrid_hpp

#include <stdio.h>
#include "cell.hpp"
#include "constants.h"

class FloorGrid{
public:
	FloorGrid();
	Cell grid[numCells][numCells];
	
};
#endif /* floorGrid_hpp */
