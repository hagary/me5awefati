#include "Target.hpp"

Target::Target(){
	size = min = 0.1;
	max = 0.15;
	growFactor = 0.0006;
	growing = true;
}

void Target::draw()
{	
	/*GLfloat l0Diffuse[] = { 1, 0, 0, 1.0f};
	GLfloat l0Ambient[] = { 0 , 0 ,0, 1.0f };
	GLfloat l0Position[] = { 0, 0, roomSize - 10};
	GLfloat l0Direction[] = { 0, 0, roomSize - 10 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, l0Position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 360);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l0Direction);*/
	GLUquadricObj *disk;
	disk = gluNewQuadric();
	glPushMatrix();
	glTranslated(0, -49.7, roomSize - 10);
	glScaled(size, size, size);
	glRotated(90, 1, 0, 0);
	glColor3d(1, 0, 0);
	//glBindTexture(GL_TEXTURE_2D, redID);
	gluDisk(disk, 0, 50, 50, 50);
	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
}
void Target::grow() {
	if (growing)
	{ 
		size += growFactor;
		if (size >= max)
			growing = false;
		return;
	}
	size -= growFactor;
	if (size <= min)
		growing = true;
}