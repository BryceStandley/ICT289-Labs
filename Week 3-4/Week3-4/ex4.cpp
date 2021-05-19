//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//File: ex4.cpp
//Amended: 11/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "off.h"

char fileName[32];
object3D bone;

int main()
{
    printf("Please enter the OFF file to open: ");
    scanf("%s%*c", &fileName);

    readOFFFile(fileName, &bone);

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