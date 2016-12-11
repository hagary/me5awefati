#include "gameItem.hpp"

GameItem::GameItem(){}

GameItem::GameItem(std::string name)
{
	model.Load("assets/models/"+ name.c_str +".3ds");
}

void GameItem::draw()
{
	glPushMatrix();
	glScaled(size, size, size);

	glPushMatrix();
	glScaled(scaleModel, scaleModel, scaleModel);
	model.Draw();
	glPopMatrix();

	glPopMatrix();
}
