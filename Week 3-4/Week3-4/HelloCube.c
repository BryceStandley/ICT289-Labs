// to compile under Mac, use the following command
// gcc HelloOpenGL.c -framework GLUT -framework OpenGL -framework Cocoa -o HelloOpenGL


#ifdef _WIN32
    //define something for Windows (32-bit and 64-bit, this part is common)
#include <gl/freeglut.h>		// For windows
#ifdef _WIN64
    //define something for Windows (64-bit only)
#endif
#elif __APPLE__
#include <GLUT/glut.h>			// for Mac OS
#endif




// This program is meant to draw a house by specifying vertices for the
// corners and using the openGL primitive GL_LINE_LOOP to draw
// lines joining these points.
// fix any problems
// You may want to read ahead, see the  redbook  or chapter 3 of the OpenGL superbible� see top of 0readme file.

typedef GLfloat point2[2];
typedef GLfloat point3[3];

enum {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
} mode;

static GLdouble viewer[] = { 0.0, 0.0, 1.0, // initial camera location
                           0.0, 0.0, 0.0, // initial look at point
                           0.0, 1.0, 0.0  // initial  upvector
};

static GLdouble theta[] = { 0.0, 0.0, 0.0 };

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
void init(void)
{

    setLight();
    /* attributes */

    glClearColor(0.0, 0.0, 0.0, 1.0); /* draw on white background */
    glColor3f(1.0, 0.0, 0.0); /* draw in red */
    glLineWidth(5.0);   /* draw using lines 5 pixels wide */

    /* set up viewing */
    /* 500 x 500 pixel window with origin at lower left corner of display
     window*/

     /* switch matrix mode to 'projection' and load an identity matrix as the projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* Let's test 3 different modes of viewing */
    mode = ORTHO;

    if (mode == ORTHO2D) {	// for displaying 2D content (not 3D)
        // 2D viwwing (no Z coordnates
        gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    }if (mode == ORTHO) {
        // This is orthographic projection
        GLdouble left = -1;
        GLdouble right = 1;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;     // near and far clipping planes
        glOrtho(left, right,
            bottom, top,
            nearVal, farVal);

    }
    else if (mode == PERSPECTIVE) {
        //
        GLdouble fov = 60;		// degrees
        GLdouble aspect = 1;		// aspect ratio aspect = height/width
        GLdouble nearVal = 0.5;
        GLdouble farVal = 100;     // near and far clipping planes
        gluPerspective(fov, aspect, nearVal, farVal);

    }
    else if (mode == FRUSTUM) {
        GLdouble left = -1;
        GLdouble right = 1;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = .05;
        GLdouble farVal = 100;     // near and far clipping planes
        glFrustum(left, right,
            bottom, top,
            nearVal, farVal);
    }
    /* switch matrix mode back to 'model view', i.e. in world coordinate syst */
    glMatrixMode(GL_MODELVIEW);

    // now setting the camera
    glLoadIdentity();               // start with identity transformation

    gluLookAt(viewer[0], viewer[1], viewer[2],      // eye location
        viewer[3], viewer[4], viewer[5],      // looking at
        viewer[6], viewer[7], viewer[8]       // up vector
    );

}

void drawCube() {

    point3 vertices[8] = { {-.5, -.5, -.5},
                         {.5, -.5, -.5},
                         {.5, .5, -.5},
                         {-.5, .5, -.5},
                         {-.5, -.5, -1.5},
                         {.5, -.5, -1.5},
                         {.5, .5, -1.5},
                         {-.5, .5, -1.5} };

    //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);
    glEnd();

    /*
    glBegin(GL_LINE_LOOP);
        glVertex3fv(vertices[1]);
        glVertex3fv(vertices[5]);
        glVertex3fv(vertices[6]);
        glVertex3fv(vertices[2]);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glVertex3fv(vertices[3]);
        glVertex3fv(vertices[2]);
        glVertex3fv(vertices[6]);
        glVertex3fv(vertices[7]);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3fv(vertices[4]);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[3]);
        glVertex3fv(vertices[7]);
    glEnd();
     */

     //glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[6]);
    glEnd();
}

void mydisplay(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();               // start with identity transformation
    gluLookAt(viewer[0], viewer[1], viewer[2],      // eye location
        viewer[3], viewer[4], viewer[5],      // looking at
        viewer[6], viewer[7], viewer[8]       // up vector
    );

    // Rotate whatever comes after
    /*glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    */

    // A cube
    //drawCube();
    glutSolidCube(1);
    // glutSolidSphere(.2, 20, 20);

    glFlush(); /* flush buffers */
}

void keys(unsigned char key, int x, int y)
{

    /* Use x, X, y, Y, z, and Z keys to move viewer */

    if (key == 'x') {
        viewer[0] -= .1;
        /*
        theta[0] -= 5;
        if (theta[0] < 0)
            theta[0] = 360;
        */
    }
    if (key == 'X') {
        viewer[0] += .1;
        /*
        theta[0] += 5;
        if (theta[0] > 360)
            theta[0] = 0;
            */
    }
    if (key == 'y') viewer[1] -= .1;
    if (key == 'Y') viewer[1] += .1;
    if (key == 'z') viewer[2] -= .1;
    if (key == 'Z') viewer[2] += .1;

    if ((key == 'q') || (key == 'Q'))
        exit(0);


    // Redisplay the window content
    glutPostRedisplay();
}


int main(int argc, char** argv) {

    /* Standard GLUT initialization */

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(500, 500); /* 500 x 500 pixel window */
    glutInitWindowPosition(0, 0); /* place window top left on display */
    glutCreateWindow("Hello OpenGL");  /* window title */

    glutDisplayFunc(mydisplay);  /* display callback invoked when window is opened */

    // Interaction
    // glutMouseFunc(mouse);		// interaction with mouse
    glutKeyboardFunc(keys);		// interaction with keyboard

    init(); 		/* set attributes */

    glutMainLoop(); /* enter event loop */

    return 0;
}

