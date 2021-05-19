#pragma once
#include "vector.h"

typedef struct Rigidbody
{
	float mass;
	float gravity;
	Vector3 velocity;
	float speed;
	Vector3 Acceleration;
	Vector3 Force;
}Rigidbody;

void InitRigidbody(Rigidbody* rb);

Vector3 VelocityAtTime(Vector3 InitVelocity, Vector3 Acceleration, float time);

Vector3 Acceleration(Vector3 force, float mass);

Vector3 AverageVelocity(Vector3 initVelocity, Vector3 finalVelocity);

Vector3 Displace(Vector3 InitVelocity, Vector3 Acceleration, float time);

Vector3 Force(float mass, Vector3 Acceleration);

Vector3 ForceDueToGravity(float mass, float gravity);
