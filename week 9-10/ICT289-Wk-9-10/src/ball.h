#pragma once
#include "rigidbody.h"
#include "model.h"
#include "camera.h"

typedef struct Ball
{
	int ballID;
	Object3D ballModel;
	int hasModel;
	float ballRadius;
	int bounceCounter;
	Vector3 StartPosition;
	Transform transform;
	Rigidbody rigidbody;
	int thrown;
}Ball;


extern Ball ballOne, ballTwo;

void InitBall(Ball* ball, float ballRadius);

void UpdateBall(Ball* ball, float deltaTime, Vector3 CameraForward);

void ThrowNewBall(Ball* ball, Camera* camera);
