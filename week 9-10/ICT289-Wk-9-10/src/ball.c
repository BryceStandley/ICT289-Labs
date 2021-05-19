#include "ball.h"

Ball ballOne;

void InitBall(Ball* ball, float ballRadius)
{
	ball->ballID = 1;
	ball->ballRadius = ballRadius;
	ball->bounceCounter = 0;
	ball->transform.Position = Vector3Zero;
	ball->transform.Rotation = Vector3Zero;
	ball->transform.Scale = Vector3Zero;
	ball->StartPosition = ball->transform.Position;

	InitRigidbody(&ball->rigidbody);
}

void ThrowNewBall()
{
	printf("New ball thrown forward from the camera!\n");
}


void UpdateBall(Ball* ball, int time, Vector3 CameraForward)
{


	//Calculation for moving the ball in the y
	ball->transform.Position.y -= ball->rigidbody.speed;
	if (ball->transform.Position.y < ball->ballRadius || ball->transform.Position.y > ball->StartPosition.y)
	{
		if (ball->bounceCounter != 10)
		{
			if (ball->StartPosition.y > ball->transform.Position.y)
			{
				ball->StartPosition.y /= 1.3f;
			 }
			//ball->rigidbody.speed /= 2.0; // half the speed
			ball->rigidbody.speed *= -1; // invert to go up
			ball->bounceCounter++;
		}
		else if(ball->bounceCounter == 10 || ball->StartPosition.y <= 1)
		{
			ball->rigidbody.speed = 0;
		}
			
	}

}