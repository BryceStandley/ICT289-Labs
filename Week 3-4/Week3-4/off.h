//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//File: off.h (previously vec.h)
//Amended: 11/03/2021
//Updated: 18/03/2021
//Reason: updated to use with OpenGL
#pragma once
#ifndef OFF_H
#define OFF_H


#include <stdio.h>
#include <stdlib.h>
#include "vec.h"
#include <GL/freeglut.h>

typedef GLfloat point2[2];
typedef GLfloat point3[3];
typedef int face[4];

typedef struct vectorData
{
    float x, y, z;
}vectorData;

typedef struct faceData
{
    int x, y, z, verts;
}faceData;

typedef struct Transform
{
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
} Transform;


typedef struct object3D
{
    int nFaces;
    int nPoints;
    int nEdges;
    point3* points;
    face* faces;
    Transform* transform;
}object3D;

typedef struct normalizeData
{
    float xCenter;
    float yCenter;
    float zCenter;
    float radius;
    float scale;
}normalizeData;


int readOFFFile(char *fname, object3D* object);

void printPoints(const object3D* object);

void printFaces(const object3D* object);

normalizeData normalizeOffFile(object3D* object);

void setTransform(object3D* object);

int collisionDetection(object3D* obj1, object3D* obj2);
#endif // !OFF_H
