#include "window.h"


int main(int argc, char** argv)
{
	WindowInit(argc, argv, 800, 600, "Viewing Lab");

	glutMainLoop();

	return 0;
}