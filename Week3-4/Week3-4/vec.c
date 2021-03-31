#include "vec.h"

Vector2 Vec2(float a, float b)
{
	Vector2 out;
	out.x = a;
	out.y = b;

	return out;
}

Vector3 Vec3(float a, float b, float c)
{
	Vector3 out;
	out.x = a;
	out.y = b;
	out.z = c;

	return out;
}

Vector2 Vec2Zero()
{
	return Vec2(0, 0);
}

Vector3 Vec3Zero()
{
	return Vec3(0, 0, 0);
}


float Distance2v(Vector2 a, Vector2 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

float Distance3v(Vector3 a, Vector3 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}