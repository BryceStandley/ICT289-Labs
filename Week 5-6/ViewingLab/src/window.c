#pragma once
#include "window.h"

mode = PERSPECTIVE;

GLdouble viewer[] = { 0.0, 0.0, 1.0, // initial camera location
						   0.0, 0.0, 0.0, // initial look at point
						   0.0, 1.0, 0.0  // initial  upvector
};


// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 5.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;

void Input(unsigned char key, int xVal, int yVal)
{

	switch (key) {
	case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
	case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
	case GLUT_KEY_UP: deltaMove = 0.5f; break;
	case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
	}


	// Exit
	if (key == 'q') exit(0);
	if (key == 'Q') exit(0);


	// Redisplay the window content
	glutPostRedisplay();
}

void releaseKey(int key, int x, int y) 
{

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}


void init()
{
	//Put opening init calls here


}


void draw3DHouse(float scaleFactor)
{
	point3 roof[] = {
		//x				// y			//z
		{-0.5,			 0.5,			 0.5},//Front Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 0.5},

		{-0.5,			 0.5,			 -0.5},//Back Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 -0.5},

		{-0.5,			 0.5,			 -0.5},// Left Roof
		{0.0,			 1.0,			 0.0},
		{-0.5,			 0.5,			 0.5},

		{0.5,			 0.5,			 0.5},//Right Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 -0.5}
	};
	glPushMatrix();
	glTranslatef(0.0f, (scaleFactor / 2.0), 0.0f);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	
	glColor4f(RED);
	glutSolidCube(1);

	glBegin(GL_POLYGON);
	glColor4f(BLUE);
	glVertex3fv(roof[0]);
	glVertex3fv(roof[2]);
	glVertex3fv(roof[1]);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3fv(roof[3]);
	glVertex3fv(roof[5]);
	glVertex3fv(roof[4]);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3fv(roof[6]);
	glVertex3fv(roof[8]);
	glVertex3fv(roof[7]);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3fv(roof[9]);
	glVertex3fv(roof[11]);
	glVertex3fv(roof[10]);
	glEnd();
	glPopMatrix();

}

void Render()
{
	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();               // start with identity transformation
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);

	//Put Render code here
	//Draw Ground Plane
	glColor4f(GREEN);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	//Draw Houses
	glColor4f(RED);
	glLineWidth(1.0f);

	draw3DHouse(0.5);
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	draw3DHouse(1.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5.0f, 0.0, -2.5f);
	draw3DHouse(2.0f);
	glPopMatrix();


	glutSwapBuffers();
}

void SetLighting()
{
	//Put Any lighting code here
	// Define RGBA specular colours for object material
	GLfloat  mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	// How shiny material is
	GLfloat  mat_shininess[] = { 100.0 };

	GLfloat  light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat  lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	// Define position of light source
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// Define lighting model
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	// Define material properties
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_COLOR_MATERIAL);

	//Enable lighting
	glEnable(GL_LIGHTING); // as in turn on power for
	//all lights
	glEnable(GL_LIGHT0); // as in flip on the light switch

	glEnable(GL_DEPTH_TEST);

}

/**
 * \brief Handles special button presses
 *
 * \param key
 * \param xx
 * \param yy
 */
void processSpecialKeys(int key, int xx, int yy) 
{

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

void changeSize(int w, int h) 
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void computePos(float deltaMove) 
{

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) 
{

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);

	glutDisplayFunc(Render);
	glutIdleFunc(Render);
	glutKeyboardFunc(Input);
	glutReshapeFunc(changeSize);
	glutSpecialFunc(processSpecialKeys);
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	glEnable(GL_DEPTH_TEST);

	init();
	SetLighting();

	glClearColor(BLACK);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble left = -1;
	GLdouble right = 1;
	GLdouble bottom = -1;
	GLdouble top = 1;
	GLdouble nearVal = 0.1;
	GLdouble farVal = 100;
	glOrtho(left, right, bottom, top, nearVal, farVal);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}