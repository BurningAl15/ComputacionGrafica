//#include "libs\glut.h"
//#include <stdlib.h>
//#include <math.h>
//
//#include "operations.h"
//
//#define DEGTORAD (2 * 3.14159 / 360)
//
//enum { SPHERE = 1 };
//int csg_op = CSG_A;
//GLfloat viewangle;
//
//
//GLfloat sphereX = 0.f, sphereY = 0.f, sphereZ = 0.f;
//void sphere(void) {
//	glPushMatrix();
//	glTranslatef(sphereX, sphereY, sphereZ);
//	glCallList(SPHERE);
//	glPopMatrix();
//}
//
//
//enum { ANIM_LEFT, ANIM_RIGHT };
//int animDirection = ANIM_LEFT;
//
//static void anim(void) {
//	if (animDirection == ANIM_LEFT)
//		viewangle -= 3.f;
//	else
//		viewangle += 3.f;
//	glutPostRedisplay();
//}
//
//static void menu(int csgop) {
//	csg_op = csgop;
//	glutPostRedisplay();
//}
//
//static void
//display(void) {
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//	glPushMatrix();
//	glRotatef(viewangle, 0.f, 1.f, 0.f);
//	_one(sphere);
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//
//
//static void
//key(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'a':
//		viewangle -= 10.f;
//		glutPostRedisplay();
//		break;
//	case 's':
//		viewangle += 10.f;
//		glutPostRedisplay();
//		break;
//	case '\033': /*Escape*/
//		exit(0);
//	}
//}
//
//
//
//
////Main Operation
//int main(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(512, 512);
//	glutInitDisplayMode(GLUT_STENCIL | GLUT_DEPTH | GLUT_DOUBLE);
//	glutCreateWindow("Ejercicio2");
//	glutDisplayFunc(display);
//	glutKeyboardFunc(key);
//
//
//	glEnable(GL_CULL_FACE);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	////
//	static GLfloat lightpos[] = { -20.f, 0.f, 90.f, 0.0f };
//	static GLfloat sphere_mat[] = { 1.f, .0f, 0.f, 1.f };
//	static GLfloat cone_mat[] = { 0.f, .5f, 1.f, 1.f };
//
//	GLUquadricObj *sphere;
//
//	///
//	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
//
//
//	glNewList(SPHERE, GL_COMPILE);
//	sphere = gluNewQuadric();
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sphere_mat);
//	gluSphere(sphere, 20.f, 64, 64);
//	gluDeleteQuadric(sphere);
//	glEndList();
//
//
//	glMatrixMode(GL_PROJECTION);
//	glOrtho(-50., 50., -50., 50., -50., 50.);
//	glMatrixMode(GL_MODELVIEW);
//	glutMainLoop();
//	return 0;
//}