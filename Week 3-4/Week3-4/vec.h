#pragma once
#ifndef VEC_H
#define VEC_H
#include <math.h>

typedef struct Vector2
{
	float x;
	float y;
} Vector2;

typedef struct Vector3
{
	float x;
	float y;
	float z;
} Vector3;

Vector2 Vec2(float a, float b);

Vector3 Vec3(float a, float b, float c);

Vector2 Vec2Zero();

Vector3 Vec3Zero();

float Distance2v(Vector2 a, Vector2 b);

float Distance3v(Vector3 a, Vector3 b);

#endif // !VEC_H