#include "scene.h"

void DrawGroundPlane(float scaleX, float scaleZ)
{
	glBegin(GL_QUADS);
	glVertex3f(-(1 * scaleX), 0.0f, -(1 * scaleZ));
	glVertex3f(-(1 * scaleX), 0.0f, (1 * scaleZ));
	glVertex3f((1 * scaleX), 0.0f, (1 * scaleZ));
	glVertex3f((1 * scaleX), 0.0f, -(1 * scaleZ));
	glEnd();
}

void DrawCubeOnGround(float scale)
{
	glTranslatef(0.0f, (scale / 2.0), 0.0f);
	glScalef(scale, scale, scale);

	glutSolidCube(1);
}


void DrawOffModels(Object3D* objects)
{
	for (int i = 0; i < 2; i++)
	{
		DrawOffFile(&objects[i]);
	}
}
