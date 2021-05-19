#pragma once
#ifndef MODEL_H
#define MODEL_H
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "vector.h"
#include "colours.h"
#include <GL/freeglut.h>

/**
 * model.h
 * \author Bryce Standley
 * \brief Used to load and manage models into the program
 * 
 * \date  April 2021
 */

/*
* \brief Structure of a 3D Model based arounf the OFF file type
*/
 
typedef struct Object3D
{
	int numFaces;
	int numPoints;
	int numEdges;
	Vector3* vertexPoints;
	Vector4* faceIndices;
	Transform transform;
} Object3D;

/*
* \brief Init's values in the object before loading in the file. Similar to a default constructor for the object
*/
void InitEmptyObject(Object3D* object);

/*
* \brief Loads in a given 3D model OFF file and returns true or false for a successful load
*/
int LoadOffFile(char* filePath, Object3D* object);

/*
* \brief Used to render a OFF file. Use this function within the glut render call
*/
void DrawOffFile(Object3D* object);


#endif // !MODEL_H


