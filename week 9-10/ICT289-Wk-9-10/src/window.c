#include "window.h"

Vector3 cPosition;
Object3D boneModel;
Object3D* models;

float physicsTimer = -0.5f; // Start at -1 to begin at 0 on the physics ticks


void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title)
{
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);

	glutReshapeFunc(WindowReSize);
	glutDisplayFunc(Render);
	glutIdleFunc(Render);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(PressNormalInput);
	glutKeyboardUpFunc(PressNormalInputUp);

	glutMouseFunc(MouseButtonInput);
	glutMotionFunc(MouseMovementInput);
	glutPassiveMotionFunc(MouseMovementInput);

	init(windowWidth, windowHeight);

	SetLighting();

	printf("Program lanuched successfully!");

	glutTimerFunc(1, PhysicsUpdate, 0);

	glutTimerFunc(1, InputTimer, 0);

}

void SetLighting()
{
	//Put Any lighting code here
	//Lighting code used from labs
	GLfloat lightPos[] = {1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat shininess[] = { 50.0f };
	glShadeModel(GL_SMOOTH);

	// Define position of light source
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Define lighting model
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	// Define material properties
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,specular);

	glEnable(GL_COLOR_MATERIAL);

	//Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void Render()
{
	//Clear the colours and transforms
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	UpdateCamera(&camera);
	SetLighting();

	//Draw the ground plane
	glColor3f(GREEN);
	DrawGroundPlane(100, 100);

	glColor3f(CYAN);
	DrawBall(ballOne.ballID);


	//Swap the buffers
	glutSwapBuffers();
}

void PhysicsUpdate(int value)
{
	physicsTimer += 0.5f;
	Render();

	//Physics updates go here
	UpdateBall(&ballOne, (int)physicsTimer, camera.Forward);


	glutTimerFunc(1, PhysicsUpdate, 0); // physics tick every 1 msecond
}

void DrawBall(int ballID)
{
	glPushMatrix();
	if (ballID == 1)
	{
		glTranslatef(ballOne.transform.Position.x, ballOne.transform.Position.y, ballOne.transform.Position.z);
		glutSolidSphere(ballOne.ballRadius, 30, 30);
	}
	

	glPopMatrix();
}

void init(int w, int h)
{
	viewportWidth = w;
	viewportHieght = h;

	//Put opening init calls here
	glClearColor(BLACK, 1.0f);

	//disable the cursor and move it to the center of the window
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(viewportWidth / 2, viewportHieght / 2);

	//Camera init to default values
	cPosition = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };
	camera.transform.Position = cPosition;
	camera.LookAt = (Vector3){ .x = 5.0f, .y = 0.0f, .z = -10.0f };;
	camera.Up = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };;
	camera.transform.Rotation = (Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f };
	camera.Forward = (Vector3){ .x = 0.0f, .y = 0.0f, .z = -1.0f };

	UpdateCamera(&camera);


	InitBall(&ballOne, 0.5f);
	ballOne.rigidbody.speed = 0.01f;
	ballOne.transform.Position = (Vector3) { .x = 5.0f, .y = 10.0f, .z = 5.0f };
	ballOne.StartPosition = ballOne.transform.Position;

	//LoadModels();

}

void WindowReSize(int w, int h)
{
	if (h == 0) h = 1;
	float ratio = (float) 1.0 * w / h;
	viewportWidth = w;
	viewportHieght = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void LoadModels()
{
	if (!LoadOffFile("./res/models/bone.off", &boneModel)) printf("File at './res/models/bone.off' failed to load\n");
}
