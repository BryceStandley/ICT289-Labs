//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4
//File: off.cpp
//Created: 11/03/2021
//Updated: 18/03/2021
//Reason: updated to use with OpenGL

#include "off.h"

char line[32];
FILE* file;

/**
* Used to read in data from a OFF 3D model file and store it in a object3D struct for later use
* 
* \author Bryce Standley
* \date   March 2021
* \param fname
* \param object
* \return 
*/
int readOFFFile(char *fname, object3D* object)
{
    char off[10];

    file = fopen(fname, "r");
    fscanf(file, "%s %d %d %d", off, &object->nPoints, &object->nFaces, &object->nEdges);
    object->points = (point3*)malloc(object->nPoints * sizeof(point3));

    for (int i = 0; i < object->nPoints; i++)
    {
        fscanf(file, "%f %f %f", &object->points[i][0], &object->points[i][1], &object->points[i][2] );
    }

    object->faces = (face*)malloc(object->nFaces * sizeof(face));

    for (int i = 0; i < object->nFaces; i++)
    {
        fscanf(file, "%d %d %d %d", &object->faces[i][0], &object->faces[i][1], &object->faces[i][2], &object->faces[i][3]);
    }

    fclose(file);
    object->transform = (Transform*)malloc(sizeof(Transform));
    setTransform(object);
    return 1;

}

/**
* Used to print the point/vertex data to the console
* 
* \author Bryce Standley
* \date   March 2021
* \param object
*/
void printPoints(const object3D* object)
{
    for (int i = 0; i < object->nPoints; i++)
    {
        printf("%f %f %f \n", object->points[i][0], object->points[i][1], object->points[i][2]);
    }
}
/**
* Used to print face data of a 3D object to the console
* 
* \author Bryce Standley
* \date   March 2021
* \param object
*/
void printFaces(const object3D* object)
{
    for (int i = 0; i < object->nPoints; i++)
    {
        printf("%d %d %d \n", object->faces[i][1], object->faces[i][2], object->faces[i][3]);
    }
}
/**
* Finds the center of mass and radius of a 3D object to then transform and scale the scene to render the given object at the origin 
* 
* \author Bryce Standley
* \date   March 2021
* \param object
* \return 
*/
normalizeData normalizeOffFile(object3D* object)
{
    float xCenter = 0.0;
    float yCenter = 0.0; 
    float zCenter = 0.0;

    float xMin = object->points[0][0];
    float xMax = object->points[0][0];
    float yMin = object->points[0][1];
    float yMax = object->points[0][1];
    float zMin = object->points[0][2];
    float zMax = object->points[0][2];


    for (int i = 0; i < object->nPoints; i++)
    {
        xCenter += object->points[i][0];
        yCenter += object->points[i][1];
        zCenter += object->points[i][2];
    }

    xCenter /= object->nPoints;
    yCenter /= object->nPoints;
    zCenter /= object->nPoints;


    for (int i = 0; i < object->nPoints; i++)
    {
        if (object->points[i][0] < xMin) {xMin = object->points[i][0];}
        if (object->points[i][0] > xMax) { xMax = object->points[i][0];}

        if (object->points[i][1] < yMin) { yMin = object->points[i][1]; }
        if (object->points[i][1] > yMax) { yMax = object->points[i][1]; }

        if (object->points[i][2] < zMin) { zMin = object->points[i][2]; }
        if (object->points[i][2] > zMax) { zMax = object->points[i][2]; }
    }

    //xCenter = (xMin + xMax) / 2.0;
    //yCenter = (yMin + yMax) / 2.0;
    //zCenter = (zMin + zMax) / 2.0;

    float testx = 1 / (xMax - xMin);
    float texty = 1 / (yMax - yMin);
    float textz = 1 / (zMax - zMin);


    float radius = 0.0;
    float* mag;
    mag = (float*)malloc(object->nPoints * sizeof(float));

    if (mag == NULL)
    {
        printf("Memory not allowcated!\n");
    }
    else
    {
        for (int i = 0; i < object->nPoints; i++)
        {
            Vector3 center = Vec3(xCenter, yCenter, zCenter);
            Vector3 point = Vec3(object->points[i][0], object->points[i][1], object->points[i][2]);
            mag[i] = Distance3v(point, center);
        }
    }
    radius = mag[0];

    for (int i = 1; i < object->nPoints; i++)
    {
        if (mag[i] > radius)
        {
            radius = mag[i];
        }
    }

    normalizeData data;


    data.xCenter = xCenter;
    data.yCenter = yCenter;
    data.zCenter = zCenter;
    data.radius = radius;
    data.scale = 1.0 / radius;
    return data;

}

void setTransform(object3D* object)
{
    object->transform->position = Vec3Zero();
    object->transform->rotation = Vec3Zero();
    object->transform->scale = Vec3(1, 1, 1);
}


int collisionDetection(object3D* obj1, object3D* obj2)
{
    normalizeData normalObj1 = normalizeOffFile(obj1);
    normalizeData normalObj2 = normalizeOffFile(obj2);

    Vector3 obj1Center = Vec3(normalObj1.xCenter * normalObj1.scale, normalObj1.yCenter * normalObj1.scale, normalObj1.zCenter * normalObj1.scale);
    Vector3 obj2Center = Vec3(normalObj2.xCenter * normalObj2.scale, normalObj2.yCenter * normalObj2.scale, normalObj2.zCenter * normalObj2.scale);

    float distance = Distance3v(obj1Center, obj2Center);
    float radii = normalObj1.radius + normalObj2.radius;
    if (distance <= radii)
    {
        printf("Object 1 and Object 2's bounding spheres are colliding with distance between centers: %f being less than or equal to the sum of both radii %f\n", distance, radii);
        return 1;
    }
    else
    {
        printf("Object 1 and Object 2's bounding spheres are NOT colliding with distance between centers: %f being more than the sum of both radii: %f\n", distance, radii);
        return 0;
    }

}
