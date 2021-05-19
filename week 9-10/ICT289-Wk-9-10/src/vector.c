#include "vector.h"

float Magnatude2(Vector2 a) { return sqrt(pow(a.x, 2) + pow(a.y, 2)); }
float Magnatude3(Vector3 a) { return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)); }
float Magnatude4(Vector4 a) { return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2)); }

float Distance2(Vector2 a, Vector2 b)
{
	Vector2 v = DirectionVector2(a, b);
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

float Distance3(Vector3 a, Vector3 b)
{
	Vector3 v = DirectionVector3(a, b);
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

float Distance4(Vector4 a, Vector4 b)
{
	Vector4 v = DirectionVector4(a, b);
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
}

Vector2 DirectionVector2(Vector2 a, Vector2 b)
{
	Vector2 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	return v;
}
Vector3 DirectionVector3(Vector3 a, Vector3 b)
{
	Vector3 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return v;
}

Vector4 DirectionVector4(Vector4 a, Vector4 b)
{
	Vector4 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	v.w = b.w - a.w;
	return v;
}

Vector2 Add2(Vector2 a, Vector2 b)
{
	Vector2 v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return v;
}

Vector3 Add3(Vector3 a, Vector3 b)
{
	Vector3 v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return v;
}

Vector4 Add4(Vector4 a, Vector4 b)
{
	Vector4 v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	v.w = a.w + b.w;
	return v;
}

Vector2 Subtract2(Vector2 a, Vector2 b)
{
	Vector2 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	return v;
}

Vector3 Subtract3(Vector3 a, Vector3 b)
{
	Vector3 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return v;
}

Vector4 Subtract4(Vector4 a, Vector4 b) 
{
	Vector4 v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	v.w = b.w - a.w;
	return v;
}


Vector2 Scale2(Vector2 a, float scale)
{
	a.x *= scale;
	a.y *= scale;
	return a;
}

Vector3 Scale3(Vector3 a, float scale)
{
	a.x *= scale;
	a.y *= scale;
	a.z *= scale;
	return a;
}

Vector4 Scale4(Vector4 a, float scale)
{
	a.x *= scale;
	a.y *= scale;
	a.z *= scale;
	a.w *= scale;
	return a;
}

Vector2 Divide2(Vector2 a, float divide)
{
	a.x /= divide;
	a.y /= divide;
	return a;
}

Vector3 Divide3(Vector3 a, float divide)
{
	a.x /= divide;
	a.y /= divide;
	a.z /= divide;
	return a;
}

Vector4 Divide4(Vector4 a, float divide)
{
	a.x /= divide;
	a.y /= divide;
	a.z /= divide;
	a.w /= divide;
	return a;
}


Vector2 Pow2(Vector2 a, float powerOf)
{
	a.x = pow(a.x, powerOf);
	a.y = pow(a.y, powerOf);
	return a;
}


Vector3 Pow3(Vector3 a, float powerOf)
{
	a.x = pow(a.x, powerOf);
	a.y = pow(a.y, powerOf);
	a.z = pow(a.z, powerOf);
	return a;
}


Vector4 Pow4(Vector4 a, float powerOf)
{
	a.x = pow(a.x, powerOf);
	a.y = pow(a.y, powerOf);
	a.z = pow(a.z, powerOf);
	a.w = pow(a.w, powerOf);
	return a;
}

Vector2 Multiply2(Vector2 a, Vector2 b)
{
	Vector2 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	return result;
}

Vector3 Multiply3(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return result;
}

Vector4 Multiply4(Vector4 a, Vector4 b)
{
	Vector4 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	result.w = a.w * b.w;
	return result;
}

float DotProduct2(Vector2 a, Vector2 b) { return (a.x * b.x) + (a.y * b.y); }

float DotProduct3(Vector3 a, Vector3 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }


Vector3 CrossProduct3(Vector3 a, Vector3 b)
{
	Vector3 v;
	v.x = (a.y * b.z) - (a.z - b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return v;

}

float Angle2(Vector2 a, Vector2 b)
{
	float AdotB = DotProduct2(a, b);
	float normA = Magnatude2(a);
	float normB = Magnatude2(b);
	return acos(AdotB / (normA * normB));
}

float Angle3(Vector3 a, Vector3 b)
{
	float AdotB = DotProduct3(a, b);
	float normA = Magnatude3(a);
	float normB = Magnatude3(b);
	return acos(AdotB / (normA * normB));
}


float Area3(Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 AB, AC;
	AB = DirectionVector3(a, b);
	AC = DirectionVector3(a, c);
	return 0.5 * Magnatude3(CrossProduct3(AB, AC));
}

float TriangleArea(float base, float height) { return 0.5 * base * height; }


Vector2 Normalize2(Vector2 a)
{
	Vector2 v;
	v.x = a.x * Magnatude2(a);
	v.y = a.y * Magnatude2(a);
	return v;
}

Vector3 Normalize3(Vector3 a)
{
	Vector3 v;
	v.x = a.x * Magnatude3(a);
	v.y = a.y * Magnatude3(a);
	v.z = a.z * Magnatude3(a);
	return v;
}

Vector4 Normalize4(Vector4 a)
{
	Vector4 v;
	v.x = a.x * Magnatude4(a);
	v.y = a.y * Magnatude4(a);
	v.z = a.z * Magnatude4(a);
	v.w = a.w * Magnatude4(a);
	return v;
}
