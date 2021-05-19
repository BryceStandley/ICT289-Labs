/*****************************************************************//**
 * \file   application.c
 * \brief  Main program entry point
 * 
 * \author Bryce Standley
 * \date   April 2021
 *********************************************************************/

#include "window.h"

int main(int argc, char** argv)
{
	WindowInit(argc, argv, 800, 600, "ICT289-Assessed Lab 2 - Bryce Standley - 33046367");

	glutMainLoop();
}
