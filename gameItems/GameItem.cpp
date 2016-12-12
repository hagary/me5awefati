#include "gameItem.hpp"
#include "controllers\room.hpp"

GameItem::GameItem(string name)
{
	string path = "assets/models/" + name + ".3ds";
	model.Load((char*)path.c_str());
	rotX = 0;
	rotZ = 0;

}

void GameItem::draw()
{
	glPushMatrix();
	glTranslatef(centerPoint.x, centerPoint.y, centerPoint.z);
	glScalef(size, size, size);

	//Room testCube;
	//testCube.draw(1);

	glPushMatrix();
	glRotatef(rotZ, 0, 0, 1);
	glRotatef(rot, 0, 1, 0);
	glRotatef(rotX, 1, 0, 0);
	glScalef(scaleModel, scaleModel, scaleModel);
	model.Draw();
	glPopMatrix();

	glPopMatrix();
}
