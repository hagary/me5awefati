//
//  scareScene.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef scareScene_hpp
#define scareScene_hpp

#include "Texture.hpp"
#include "controllers\room.hpp"
#include "gameItems\Bed.hpp"
#include "gameItems\Wardrobe.hpp"
#include "gameItems\toy.hpp"
#include "gameItems\monster.hpp"
#include "Target.hpp"
#include "constants.h"
class ScareScene{
public:
	ScareScene();
	Monster monster;
	Room room;
	Bed bed;
	Toy toy;
	Wardrobe wardrobe;
	Target target;
	void loadImages();
    void draw();
};
#endif /* scareScene_hpp */
