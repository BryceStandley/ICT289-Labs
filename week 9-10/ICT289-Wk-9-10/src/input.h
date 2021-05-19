#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <GL/freeglut.h>
#include "camera.h"
#include <stdbool.h>
#include <corecrt_math_defines.h>
#include "ball.h"

/*
* \brief External variables used by the input but also needs to be referenced elsewhere
*/
extern Camera camera;
extern int viewportWidth;
extern int viewportHieght;


/**
* \brief Main Input function
* 
* \author Bryce Standley
* \date   April 2021
* \param key
* \param xVal
* \param yVal
*/
void PressNormalInput(unsigned char key, int xVal, int yVal);

/*
* \brief Function to reset any input keys
*/
void PressNormalInputUp(unsigned char key, int xVal, int yVal);

/*
* \brief Mouse button input callback function
*/
void MouseButtonInput(int button, int state, int x, int y);

/*
* \brief Mouse movement input callback function
*/
void MouseMovementInput(int x, int y);

/*
* \brief Timer function used to poll input events for the camera controls
*/
void InputTimer(int value);

#endif // !INPUT_H
