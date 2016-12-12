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
#include "gameItems\room.hpp"

class ScareScene{
public:
	ScareScene();
	Room room;
	void loadImages();
    void draw();
};
#endif /* scareScene_hpp */
