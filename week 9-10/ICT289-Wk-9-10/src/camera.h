#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <GL/freeglut.h>
#include"vector.h"
#include <corecrt_math_defines.h>

/**
 * camera.h
 * \author Bryce Standley
 * \brief Adds the data structure and functions to control a OpenGL camera
 * \date  April 2021
 */


/*
* \brief Data structure of the camera
*/
typedef struct Camera
{
	Transform transform;
	Vector3 LookAt;
	Vector3 Up;
	Vector3 Forward;
}Camera;

/*
* \brief Updates the direction the cameras looking towards
*/
void UpdateCameraLookAt(Camera* c);

/*
* \brief Updates the camera and the gluLookAt function
*/
void UpdateCamera(Camera* c);

/*
* \brief moves the cameras position forwards and back
*/
void MoveCamera(Camera* c, float incr);

/*
* \brief Moves the cameras position left and right
*/
void StrafeCamera(Camera* c, float incr);

/*
* \brief Rotates the camera's yaw/x value
*/
void RotateCameraX(Camera* c, float incr);

/*
* \brief Rotates the camera's pitch/y value
*/
void RotateCameraY(Camera* c, float incr);



#endif // !CAMERA_H

