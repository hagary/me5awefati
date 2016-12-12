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
#include "constants.h"

class ScareScene{
public:
	ScareScene();
	Room room;
	Bed bed;
	Wardrobe wardrobe;
	void loadImages();
    void draw();
};
#endif /* scareScene_hpp */
