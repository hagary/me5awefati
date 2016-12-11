#pragma once
//  cell.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include "gameItems/gameItem.hpp"

class Cell{
	public: 
		Cell();
		GameItem gameItem;
		int size;

		void assignItem(GameItem);

};
#endif /* cell_hpp */
