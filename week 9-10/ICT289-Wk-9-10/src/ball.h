#pragma once
#include "rigidbody.h"

typedef struct Ball
{
	int ballID;
	float ballRadius;
	int bounceCounter;
	Vector3 StartPosition;
	Transform transform;
	Rigidbody rigidbody;
}Ball;

extern Ball ballOne;

void InitBall(Ball* ball, float ballRadius);

void UpdateBall(Ball* ball, int time, Vector3 CameraForward);

void ThrowNewBall(void);
