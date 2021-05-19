#include "camera.h"

//yaw is rotation on the x
//pitch is rotation on the y

void UpdateCameraLookAt(Camera* c)
{
	Vector3 v;
	v.x = (cos(c->transform.Rotation.x) * cos(c->transform.Rotation.y)) + c->transform.Position.x;
	v.y = sin(c->transform.Rotation.y) + +c->transform.Position.y;
	v.z = (sin(c->transform.Rotation.x) * cos(c->transform.Rotation.y)) + +c->transform.Position.z;
	c->LookAt = v;
}

void MoveCamera(Camera* c, float incr)
{
	float lx = cos(c->transform.Rotation.x) * cos(c->transform.Rotation.y);
	//float ly = sin(c->transform.Rotation.y);
	float lz = sin(c->transform.Rotation.x) * cos(c->transform.Rotation.y);

	c->transform.Position.x += incr * lx;
	c->transform.Position.y = 1.0f;
	c->transform.Position.z += incr * lz;

	UpdateCamera(c);
}

void StrafeCamera(Camera* c, float incr)
{
	float strafeLx = cos(c->transform.Rotation.x - M_PI_2);
	float strafeLz = sin(c->transform.Rotation.x - M_PI_2);

	c->transform.Position.x += incr * strafeLx;
	c->transform.Position.z += incr * strafeLz;

	UpdateCamera(c);
}

void RotateCameraX(Camera* c, float angle)
{
	c->transform.Rotation.x += angle;
	UpdateCamera(c);
}

void RotateCameraY(Camera* c, float angle)
{
	float limit = 89.0 * M_PI / 180.0;
	c->transform.Rotation.y += angle;
	if (c->transform.Rotation.y < -limit)
	{
		c->transform.Rotation.y = -limit;
	}

	if (c->transform.Rotation.y > limit)
	{
		c->transform.Rotation.y = limit;
	}

	UpdateCamera(c);
}


void UpdateCamera(Camera* c)
{
	UpdateCameraLookAt(c);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(c->transform.Position.x, c->transform.Position.y, c->transform.Position.z,
				c->LookAt.x, c->LookAt.y, c->LookAt.z,
					c->Up.x, c->Up.y, c->Up.z);
}
