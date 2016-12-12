#include "gameItem.hpp"
#include "controllers\room.hpp"

GameItem::GameItem(string name)
{
	string path = "assets/models/" + name + ".3ds";
	model.Load((char*)path.c_str());

}

void GameItem::draw()
{

	glPushMatrix();
	glTranslatef(0, -50, roomSize - 30);

	glScalef(size, size, size);

	//Room testCube;
	//testCube.draw(1);

	glPushMatrix();
	glRotatef(rot, 0, 1, 0);
	glScalef(scaleModel, scaleModel, scaleModel);
	model.Draw();
	glPopMatrix();

	glPopMatrix();
}
