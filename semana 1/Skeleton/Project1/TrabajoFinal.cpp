#include "libs\glut.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

static int slices = 16;
static int stacks = 16;
int width=1200, height=1080;

//Camera variables
float zoom = 0;
float horizontal = 0;
float vertical = 0;

float transformVal = 0.5f;

//Objects transformations
float rotation=0;
float translationX=0;
float translationY = 0;
float translationZ = -6;
static void
resize(int width, int height) {
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar-zoom+horizontal, ar+zoom+horizontal, -1.0-zoom+vertical, 1.0+zoom+vertical, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
}


static void
display(void)
{
	resize(width,height);
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	const double a = t*90.0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1, 0, 0);
	glPushMatrix();
	

	glTranslated(translationX, translationY, translationZ);
	glRotated(60+rotation, 1, 0, 0);
	glRotated(a, 0, 0, 1);
	glutSolidCone(1, 1, slices, stacks);
	glPopMatrix();
	

	glPushMatrix();
	glTranslated(0, -1.2, -6);
	glRotated(60, 1, 0, 0);
	glRotated(a, 0, 0, 1);
	glutWireCone(1, 1, slices, stacks);
	glPopMatrix();


	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}


static void
key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	case 'q':
		exit(0);
		break;

	case '+':
		slices++;
		stacks++;
		break;

	case '-':
		if (slices>3 && stacks>3)
		{
			slices--;
			stacks--;
		}
		break;
	//Object movement
	case '4':
		translationX -= transformVal;
		break;
	case '6':
		translationX += transformVal;
		break;

	case '8':
		translationY -= transformVal;
		break;

	case '5':
		translationY += transformVal;
		break;

	case '7':
		translationZ -= transformVal;
		break;

	case '9':
		translationZ += transformVal;
		break;

	case '1':
		rotation -= transformVal;
		break;
	case '3':
		rotation += transformVal;
		break;


	//Camera movement
	/////////////////////Full zoom ///////////////////////////////
	case 'p':
		if(zoom>-0.5 && zoom <30)
			zoom+=transformVal;
		else
		{
			zoom = 0;
		}
			cout << zoom<<endl;
		break;		
	case 'l':
		if (zoom > -0.5 && zoom < 30)
			zoom-= transformVal;
		else {
			zoom = 29.5;
		}
			cout << zoom << endl;
		break;
	
	//Horizontal camera movement
	case 'a':
		horizontal -= transformVal;
		break;
	case 'd':
		horizontal += transformVal;
		break;

	//Vertical camera movement
	case 'w':
		vertical -= transformVal;
		break;
	case 's':
		vertical += transformVal;
		break;
	}

	glutPostRedisplay();
}

static void idle(void)
{
	glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main() {
	glutInitWindowSize(width, height);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("FreeGLUT Shapes");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();

	return EXIT_SUCCESS;
}
