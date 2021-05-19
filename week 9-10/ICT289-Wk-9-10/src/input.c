#include "input.h"

Camera camera;
int viewportWidth;
int viewportHieght;
const float cameraTranslationSpeed = 0.005;
const float cameraRotationSpeed = M_PI / 180 * 0.2;
bool keys[256];

void PressNormalInput(unsigned char key, int xVal, int yVal)
{

	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'T':
	case 't':
		ThrowNewBall();
		break;
	default:
		break;
	}


	keys[key] = true;
}


void PressNormalInputUp(unsigned char key, int xVal, int yVal)
{
	keys[key] = false;
}

void MouseButtonInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		printf("Left Mouse button pressed\n");
	}
}

void MouseMovementInput(int x, int y)
{
	static bool warpedPointer = false;

	if (warpedPointer)
	{
		warpedPointer = false;
		return;
	}

	int dx = x - viewportWidth / 2;
	int dy = y - viewportHieght / 2;
	if (dx)
	{
		RotateCameraX(&camera, cameraRotationSpeed * dx);
	}
	if (dy)
	{
		RotateCameraY(&camera, -cameraRotationSpeed * dy);
	}

	glutWarpPointer(viewportWidth / 2, viewportHieght / 2);
	warpedPointer = true;

}

void InputTimer(int value)
{
	if (keys['w'] || keys['W'])
	{
		MoveCamera(&camera, cameraTranslationSpeed);
	}
	if (keys['s'] || keys['S'])
	{
		MoveCamera(&camera, -cameraTranslationSpeed);
	}
	if (keys['a'] || keys['A'])
	{
		StrafeCamera(&camera, cameraTranslationSpeed);
	}
	if (keys['d'] || keys['D'])
	{
		StrafeCamera(&camera, -cameraTranslationSpeed);
	}

	glutTimerFunc(1, InputTimer, 0);
}

