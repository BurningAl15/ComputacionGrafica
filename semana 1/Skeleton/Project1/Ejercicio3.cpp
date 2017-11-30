//#include <stdlib.h>
//
//#include <stdio.h>
//#include "libs\glut.h"
//
//static int spin = 0;
//static int begin;
//
//void movelight(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		begin = x;
//	}
//}
//
//void motion(int x, int y)
//{
//	spin = (spin + (x - begin)) % 360;
//	begin = x;
//	glutPostRedisplay();
//}
//
//void myinit(void)
//{
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glDepthFunc(GL_LESS);
//	glEnable(GL_DEPTH_TEST);
//}
//
//void display(void)
//{
//	GLfloat position[] =
//	{ 0.0, 0.0, 1.5, 1.0 };
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	//Pos de la fuent de luz
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -5.0);
//	glPushMatrix();
//	glRotated((GLdouble)spin, 0.0, 1.0, 0.0);
//	glRotated(0.0, 1.0, 0.0, 0.0);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glTranslated(0.0, 0.0, 1.5);
//	glDisable(GL_LIGHTING);
//	glColor3f(0.0, 1.0, 1.0);
//	glutWireCube(0.1);
//	glEnable(GL_LIGHTING);
//	glPopMatrix();
//	
//	//Figura a iluminar
//	glutSolidTeapot(1.0);
//	glPopMatrix();
//
//	glPushAttrib(GL_ENABLE_BIT);
//	glDisable(GL_DEPTH_TEST);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluOrtho2D(0, 3000, 0, 3000);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glPopAttrib();
//	glutSwapBuffers();
//}
//void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow(argv[0]);
//	myinit();
//	glutMouseFunc(movelight);
//	glutMotionFunc(motion);
//	glutReshapeFunc(myReshape);
//	glutDisplayFunc(display);
//	
//	glutMainLoop();
//	return 0;
//}