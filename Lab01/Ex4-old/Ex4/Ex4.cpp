//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//Amended: 10/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "vec.h"


char fileName[32];
char line[32];
FILE* file;
object3D bone;


void readOFFFile(object3D *object)
{
    char off[10];

    file = fopen(fileName, "r");
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

int main()
{
    printf("Please enter the OFF file to open: ");
    scanf("%s%*c", &fileName);
    
    readOFFFile(&bone);

    printf("\n-------------------------------------------\n");
    printf("There is %d vectors and %d faces within %s\n", bone.nPoints, bone.nFaces, fileName);
    printf("-------------------------------------------\n");
    
    printf("Press enter to display vertex data\n");
    getchar();
    printPoints(&bone);

    printf("Press enter to display face data\n");
    getchar();
    printFaces(&bone);

    return 0;
}


