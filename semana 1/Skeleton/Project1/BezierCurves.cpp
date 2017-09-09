#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <vector>
#include "Punto.h"

using namespace std;

int SCREEN_HEIGHT = 480;
int NUMPOINTS = 0;
vector<Punto2D> puntosControl;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void DibujarPunto(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void DibujaLinea(Punto2D p1, Punto2D p2)
{
	glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glEnd();
	glFlush();
}

int factorial(int x)
{
	int fac = 1;
	for (int i = 2; i <= x; i++) fac *= i;
	return fac;
}

int CoeficienteBinomial(int n, int i)
{
	int a = factorial(n);
	int b = factorial(i);
	int c = factorial(n-i);
	int cb = a / (b*c);
	return cb;
}

Punto2D DibujaBezier(double t)
{
	Punto2D P;
	//P.init();
	int n = NUMPOINTS - 1;
	for (int i = 0; i < NUMPOINTS; i++)
	{
		P.x += CoeficienteBinomial(n, i)*(puntosControl[i].x)*(pow((i - t), n - i))*(pow(t, i));
		P.y += CoeficienteBinomial(n, i)*(puntosControl[i].y)*(pow((i - t), n - i))*(pow(t, i));
	}
	return P;
}

void myKey(int key, int x, int y)
{
	if (key == GLUT_KEY_F1 && puntosControl.size() > 2)
	{
		glColor3f(1.0, 1.0, 1.0);
		for(int i=0;i<NUMPOINTS )
	}
}