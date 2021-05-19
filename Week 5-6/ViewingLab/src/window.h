#pragma once
#include <GL/freeglut.h>

#define BLACK 0.0, 0.0, 0.0, 1.0
#define WHITE 1.0, 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0, 1.0
#define GREEN 0.0, 1.0, 0.0, 1.0
#define BLUE 0.0, 0.0, 1.0, 1.0

typedef GLfloat point2[2];
typedef GLfloat point3[3];


enum mode {
	ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
};

/**
* \brief Main Input function
*
* \author Bryce Standley
* \date   April 2021
* \param key
* \param xVal
* \param yVal
*/
void Input(unsigned char key, int xVal, int yVal);


/**
* \brief Aditional init function for unrelated items to glut
* 
* \author Bryce Standley
* \date   April 2021
*/
void init(void);

void draw3DHouse(float scaleFactor);

/**
* \brief Main Render function
* 
* \author Bryce Standley
* \date   April 2021
*/
void Render(void);

/**
* 
* \brief Lighting setup function
* \author Bryce Standley
* \date   April 2021
*/
void SetLighting(void);

void processSpecialKeys(int key, int xx, int yy);
void changeSize(int w, int h);
void computePos(float deltaMove);
void computeDir(float deltaAngle);
void releaseKey(int key, int x, int y);

/**
*
* \brief Main GLUT init functions
* \author Bryce Standley
* \date   April 2021
* \param argc
* \param argv
* \param windowWidth
* \param windowHeight
* \param title
*/
void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title);