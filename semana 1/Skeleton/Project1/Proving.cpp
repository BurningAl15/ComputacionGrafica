//#include <iostream>
//using namespace std;
//
//#include "libs\glut.h"
//
//void initRendering() {
//	glClearColor(0, 0, 0, 0);
//}
//
//void Reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.0);
//}
//
//void linea_pto_medio_completo(int x1, int y1, int x2, int y2) {
//	int dx, dy, incrE, incrNE, d, x, y, sx, sy, i;
//	bool dymayor;
//
//	(x2 > x1) ? sx = 1 : sx = -1;
//	(y2 > y1) ? sy = 1 : sy = -1;
//
//	dx = abs(x2 - x1);
//	dy = abs(y2 - y1);
//	if (dy > dx) {
//		dymayor = true;
//		int t;
//		t = dx;
//		dx = dy;
//		dy = t;
//	}
//	else
//		dymayor = false;
//
//	d = 2 * dy - dx;
//	incrE = 2 * dy;
//	incrNE = 2 * (dy - dx);
//	x = x1;
//	y = y1;
//
//	glColor3f(1, 1, 0);
//	glPointSize(5); //pixel size
//	glBegin(GL_POINTS);
//	for (i = 0; i <= dx; i++) {
//		glVertex3f(x, y, 0);
//		if (d <= 0) {	// pixel E seleccionado
//			d = d + incrE;
//			if (dymayor)
//				y = y + sy;
//			else
//				x = x + sx;
//		}
//		else {			// pixel NE seleccionado
//			d = d + incrNE;
//			x = x + sx;
//			y = y + sy;
//		}
//	}
//	glEnd();
//}
//
//void linea_pto_medio(int x1, int y1, int x2, int y2) {
//	int dx, dy, incrE, incrNE, d, x, y;
//	dx = x2 - x1;
//	dy = y2 - y1;
//	d = 2 * dy - dx;
//	incrE = 2 * dy;
//	incrNE = 2 * (dy - dx);
//	x = x1;
//	y = y1;
//	glColor3f(1, 0, 0);
//	glPointSize(5);
//	glBegin(GL_POINTS);
//	while (x <= x2) {
//		glVertex3f(x, y, 0);
//		if (d <= 0) {
//			x = x + 1;
//			d = d + incrE;
//		}
//		else {
//			x = x + 1;
//			y = y + 1;
//			d = d + incrNE;
//		}
//	}
//	glEnd();
//}
//
//void Display() {
//	int i, j;
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(-15, -15, -40);
//	glColor3f(0.3f, 0.3f, 0.3f);
//
//	//lineas horizontales
//	glBegin(GL_LINES);
//	for (i = 0; i <= 30; i++) {
//		glVertex3f(0, i, 0);
//		glVertex3f(30, i, 0);
//	}
//	glEnd();
//
//	//lineas verticales
//	glBegin(GL_LINES);
//	for (j = 0; j <= 30; j++) {
//		glVertex3f(j, 0, 0);
//		glVertex3f(j, 30, 0);
//	}
//	glEnd();
//
//	//lineas de otra pendiente
//	glColor3f(0.4f, 0.4f, 0.4f);
//
//	glBegin(GL_QUADS);
//	glVertex3f(-0.5f, -0.5f, 0);
//	glVertex3f(0.5f, -0.5f, 0);
//	glVertex3f(0.5f, 0.5f, 0);
//	glVertex3f(-0.5f, 0.5f, 0);
//	glEnd();
//
//
//	//linea_pto_medio(0, 0, 20, 5);
//	//linea_pto_medio(0, 0, 5, 20);
//
//	linea_pto_medio_completo(0, 0, 20, 5);
//	linea_pto_medio_completo(0, 0, 5, 20);
//
//
//	glColor3f(0, 0, 1);
//	glBegin(GL_LINES);
//	glVertex3f(0, 0, 0);
//	glVertex3f(30, 30, 0);
//	glEnd();
//
//	glutSwapBuffers();
//	glFlush();
//}
//
//int main() {
//	//Step 1: Initialize GLUT
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(400, 400);
//
//	//Step2: Create Windows
//	glutCreateWindow("Algoritmo de Bresenham");
//	initRendering();
//
//	//Step3: Handlers functions
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//
//	//Step4: Main Loop
//	glutMainLoop();
//	return 0;
//}


