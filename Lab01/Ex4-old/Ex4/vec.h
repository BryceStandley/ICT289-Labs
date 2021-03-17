#pragma once
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
    vectorData *points;
    faceData *faces;
}object3D;

