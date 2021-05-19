#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include<GL\freeglut.h>
#include "input.h"
#include "scene.h"
#include "camera.h"
#include "colours.h"
#include "model.h"
#include "rigidbody.h"
#include "ball.h"

/**
 * window.h
 * \author Bryce Standley
 * \brief Main window file that contains all functions related to the window and the program
 * \date  April 2021
 */

#define TARGET_FPS 10


float deltaTime, previousTime, currentTime;

/**
* \brief Aditional init function for unrelated items to glut
*/
void init(int w, int h);

/**
* \brief Main Render function
*/
void Render(void);

/**
* 
* \brief Lighting setup function
*/
void SetLighting();

/**
*
* \brief Main GLUT init functions
*/
void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title);

/*
* \brief Resize function for glut
*/
void WindowReSize(int w, int h);


/*
* \brief Init function to load all models into the program
*/
void LoadModels();

void DrawBall(Ball* ball);

void PhysicsUpdate(int value);


#endif // !WINDOW_H
