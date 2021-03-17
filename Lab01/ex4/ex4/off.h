//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//File: off.h (previously vec.h)
//Amended: 11/03/2021

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorData
{
    float x, y, z;
}vectorData;

typedef struct faceData
{
    int x, y, z, verts;
}faceData;

typedef struct object3D
{
    int nFaces;
    int nPoints;
    int nEdges;
    vectorData* points;
    faceData* faces;
}object3D;

void readOFFFile(char *fname, object3D* object);

void printPoints(const object3D* object);

void printFaces(const object3D* object);