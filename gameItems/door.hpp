//
//  door.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright Â© 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef door_hpp
#define door_hpp

#include <stdio.h>
#include "gameItem.hpp"
#include "Texture.hpp"

class Door : public GameItem {
public: Door();
		GLuint texID;
		void draw(double xTrans);
};

#endif /* door_hpp */
