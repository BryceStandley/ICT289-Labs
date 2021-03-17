//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//File: off.cpp
//Created: 11/03/2021

#include "off.h"

char line[32];
FILE* file;

void readOFFFile(char *fname, object3D* object)
{
    char off[10];

    file = fopen(fname, "r");
    fscanf(file, "%s %d %d %d", off, &object->nPoints, &object->nFaces, &object->nEdges);
    object->points = (vectorData*)malloc(object->nPoints * sizeof(vectorData));

    for (int i = 0; i < object->nPoints; i++)
    {
        fscanf(file, "%f %f %f", &object->points[i].x, &object->points[i].y, &object->points[i].z);
    }

    object->faces = (faceData*)malloc(object->nFaces * sizeof(faceData));

    for (int i = 0; i < object->nFaces; i++)
    {
        fscanf(file, "%d %d %d %d", &object->faces[i].verts, &object->faces[i].x, &object->faces[i].y, &object->faces[i].z);
    }

    fclose(file);

}


void printPoints(const object3D* object)
{
    for (int i = 0; i < object->nPoints; i++)
    {
        printf("%f %f %f \n", object->points[i].x, object->points[i].y, object->points[i].z);
    }
}

void printFaces(const object3D* object)
{
    for (int i = 0; i < object->nPoints; i++)
    {
        printf("%d %d %d \n", object->faces[i].x, object->faces[i].y, object->faces[i].z);
    }
}