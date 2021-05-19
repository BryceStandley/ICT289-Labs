#include "ball.h"

Ball ballOne, ballTwo;

float time = 0;

void InitBall(Ball* ball, float ballRadius)
{
	ball->ballID = 1;
	ball->ballRadius = ballRadius;
	ball->bounceCounter = 0;
	ball->transform.Position = Vector3Zero;
	ball->transform.Rotation = Vector3Zero;
	ball->transform.Scale = Vector3One;
	ball->StartPosition = ball->transform.Position;
	ball->thrown = 0;

	InitRigidbody(&ball->rigidbody);
}

void ThrowNewBall(Ball* ball, Camera* camera)
{
	printf("New ball thrown forward from the camera!\n");

	ball->transform.Position = camera->transform.Position;
	ball->transform.Position.y += 5;
	ball->rigidbody.Acceleration.x = Scale3(camera->LookAt, 5.0f).x;
	ball->rigidbody.Acceleration.y = -ball->rigidbody.gravity;
	ball->rigidbody.Acceleration.z = Scale3(camera->LookAt, 5.0f).z;

	ball->thrown = 1;
}


void UpdateBall(Ball* ball, float deltaTime, Vector3 CameraForward)
{

	Transform newTransorm;
	newTransorm.Position = Displace(ball->transform.Position, ball->rigidbody.velocity, ball->rigidbody.Acceleration, deltaTime);

	Rigidbody newRigidbody = ball->rigidbody;
	newRigidbody.velocity = VelocityAtTime(ball->rigidbody.velocity, ball->rigidbody.Acceleration, deltaTime);


	if (newTransorm.Position.y <= ball->ballRadius)
	{
		newRigidbody.velocity = Invert3(Scale3(newRigidbody.velocity, 0.75));
		newTransorm.Position.y = ball->ballRadius;
	}

	ball->transform = newTransorm;
	ball->rigidbody = newRigidbody;

}