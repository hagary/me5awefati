//
//  monster.hpp
//  Me5awefati
//
//  Created by Hagar Yasser Omar on 12/10/16.
//  Copyright © 2016 Hagar Yasser Omar. All rights reserved.
//

#ifndef monster_hpp
#define monster_hpp

#include "gameItem.hpp"

class Monster :public GameItem {
public: Monster();
		void moveR();
		void moveL();
		void moveF();
		void moveB();
		void reset();
private: int step;
		 Vector initP;
		 int dir;
};
#endif /* monster_hpp */
