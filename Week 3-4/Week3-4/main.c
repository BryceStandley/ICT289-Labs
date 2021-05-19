
#include <GL\freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "off.h"

void init(int argc, char** argv);
void display(void);
void keys(unsigned char key, int x, int y);
void setLight();

enum { ORTHO2D, ORTHO, PRO } mode = ORTHO;
typedef GLfloat point2[2];
typedef GLfloat point3[3];
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 800;

float camX = 1.0;
float camY = 0.5;
float camZ = 1.0;

char fileName[] = "bone_normalized_aligned.off";
object3D offFile;

int main(int argc, char** argv)
{
	//printf("Please enter the OFF file to open: ");
	//scanf_s("%s%*c", &fileName);

	if (readOFFFile(fileName, &offFile))
	{
		normalizeOffFile(&offFile);

		init(argc, argv);

		glutMainLoop();
	}



	return 0;
}

void init(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Week 3 - 4 ICT289 - Bryce Standley - 33046367");

	glutDisplayFunc(display);
	glutKeyboardFunc(keys);

	setLight();

	mode = ORTHO;

	glClearColor(0.0, 0.0, 0.0, 1.0); //Clear colour to black background
	glColor3f(1.0, 1.0, 1.0); //set draw in white
	glLineWidth(5.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (mode == ORTHO2D)
	{
		gluOrtho2D(0, SCR_WIDTH, 0, SCR_HEIGHT);
	}
	if (mode == ORTHO)
	{
		GLdouble left = -1;
		GLdouble right = 1;
		GLdouble bottom = -1;
		GLdouble top = 1;
		GLdouble nearVal = 0.1;
		GLdouble farVal = 100;
		glOrtho(left, right, bottom, top, nearVal, farVal);
	}
	if (mode == PRO)
	{
		GLdouble fov = 60;
		GLdouble aspect = 3;
		GLdouble nearVal = 0.1;
		GLdouble farVal = 100;
		gluPerspective(fov, aspect, nearVal, farVal);
	}


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camX, camY, camZ,
				0.0, 0.0, 0.0,
				0.0, 1.0, 0.0);
}

void drawSquare()
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, -0.5, -1.5);
	glVertex3f(-0.5, -0.5, -1.5);
	glVertex3f(0.5, 0.5, -1.5);
	glVertex3f(-0.5, 0.5, -1.5);
	glEnd();
}

void draw3DHouse()
{
	point3 roof[] = {
		//x				// y			//z
		{-0.5,			 0.5,			 0.5},//Front Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 0.5},

		{-0.5,			 0.5,			 -0.5},//Back Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 -0.5},

		{-0.5,			 0.5,			 -0.5},// Left Roof
		{0.0,			 1.0,			 0.0},
		{-0.5,			 0.5,			 0.5},

		{0.5,			 0.5,			 0.5},//Right Roof
		{0.0,			 1.0,			 0.0},
		{0.5,			 0.5,			 -0.5}
	};
	
	glColor3f(0.2, 0.2, 0.2);
	glutSolidCube(1);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(roof[0]);
	glVertex3fv(roof[1]);
	glVertex3fv(roof[2]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3fv(roof[3]);
	glVertex3fv(roof[4]);
	glVertex3fv(roof[5]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(roof[6]);
	glVertex3fv(roof[7]);
	glVertex3fv(roof[8]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3fv(roof[9]);
	glVertex3fv(roof[10]);
	glVertex3fv(roof[11]);
	glEnd();

}

void drawHouse()
{
	float halfScrW = SCR_WIDTH / 2.0f;
	float halfScrH = SCR_HEIGHT / 2.0f;
	point2 vertices[4] = { 
		{halfScrW - 100, halfScrH - 50},
		{halfScrW - 100,halfScrH + 150},
		{halfScrW + 100, halfScrH + 150},
		{halfScrW + 100, halfScrH - 50} };

	glBegin(GL_LINE_LOOP);
	glVertex2fv(vertices[0]);
	glVertex2fv(vertices[1]);
	glVertex2fv(vertices[2]);
	glVertex2fv(vertices[3]);
	glEnd();

	glBegin(GL_LINE_LOOP);//Door
	glVertex2f(halfScrW - 50, halfScrH - 50);
	glVertex2f(halfScrW - 50, halfScrH + 50);
	glVertex2f(halfScrW , halfScrH + 50);
	glVertex2f(halfScrW, halfScrH - 50);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2fv(vertices[1]);
	glVertex2f(halfScrW, halfScrH + 200);
	glVertex2fv(vertices[2]);
	glEnd();
}

void drawAxes()
{
	point3 xAxis[] = {
		{0.0, 0.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 0.0, -0.01},
		{0.0, 0.0, -0.01}
	};

	point3 yAxis[] = {
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{0.0, 1.0, -0.01},
		{0.0, 0.0, -0.01}
	};

	point3 zAxis[] = {
	{0.0, 0.0, 0.0},
	{0.01, 0.0, 0.0},
	{0.01, 0.0, 1.0},
	{0.0, 0.0, 1.0}
	};

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(xAxis[0]);
	glVertex3fv(xAxis[1]);
	glVertex3fv(xAxis[2]);
	glVertex3fv(xAxis[3]);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(yAxis[0]);
	glVertex3fv(yAxis[1]);
	glVertex3fv(yAxis[2]);
	glVertex3fv(yAxis[3]);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(zAxis[0]);
	glVertex3fv(zAxis[1]);
	glVertex3fv(zAxis[2]);
	glVertex3fv(zAxis[3]);
	glEnd();



}

void drawOffFile(object3D file)
{
	float randRed, randGreen, randBlue;

	for (int i = 0; i < file.nFaces; i++)
	{
		randRed = (float)rand() / RAND_MAX;
		randGreen = (float)rand() / RAND_MAX;
		randBlue = (float)rand() / RAND_MAX;
		glBegin(GL_TRIANGLES);
		glColor3f(randRed, randGreen, randBlue);
		face f;
		f[1] = file.faces[i][1];
		f[2] = file.faces[i][2];
		f[3] = file.faces[i][3];

		glVertex3fv(file.points[f[1]]);
		glVertex3fv(file.points[f[2]]);
		glVertex3fv(file.points[f[3]]);

		glEnd();

	}

}

void display()
{
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
		
	//drawSquare();
	//glRotatef(rotateVal, 0.0, 1.0, 0.0);
	//glutSolidCube(1);
	//drawHouse();
	//draw3DHouse();
	//drawAxes();
	drawOffFile(offFile);


	glFlush();
}

void keys(unsigned char key, int xVal, int yVal)
{
	if (key == 'Z')
	{
		camZ -= 0.01f;
	}

	if (key == 'z')
	{
		camZ += 0.01f;
	}

	if (key == 'Y')
	{
		camY -= 0.01f;
	}
	if (key == 'y')
	{
		camY += 0.01f;
	}

	if (key == 'X')
	{
		camX -= 0.01f;

	}
	if (key == 'x')
	{
		camX += 0.01f;
	}

	if (key == 'Q' || key == 'q')
	{
		exit(0);
	}

	printf("camX: %f -- camY: %f -- camZ: %f\n", camX, camY, camZ);

	glutPostRedisplay();
}

void setLight(void) {

	// Define RGBA specular colours for object material
	GLfloat  mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	// How shiny material is
	GLfloat  mat_shininess[] = { 50.0 };

	GLfloat  light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat  lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	// Define position of light source
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// Define lighting model
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	// Define material properties
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_COLOR_MATERIAL);

	//Enable lighting
	glEnable(GL_LIGHTING); // as in turn on power for
	//all lights
	glEnable(GL_LIGHT0); // as in flip on the light switch

	glEnable(GL_DEPTH_TEST);

}