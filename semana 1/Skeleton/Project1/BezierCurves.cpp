//#include <iostream>
//#include <stdlib.h>
//#include <Windows.h>
//#include <math.h>
//#include <glut.h>
//#include <gl\GL.h>
//#include <gl\GLU.h>
//#include <vector>
//#include <iostream>
//#include "Punto.h"
//#include "Poligono2D.h"
//
//using namespace std;
//
//Poligono2D* Pol;
//Punto2D* base;
//
//int ipb;
//int tipoTransformacion;
//int rotar;
//double espesor;
//
//int SCREEN_HEIGHT = 480;
//int NUMPOINTS = 0;
//vector<Punto2D> puntosControl;
//
//void myInit()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glColor3f(1.0, 0.0, 0.0);
//	glPointSize(4.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//}
//
//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//
//void DibujarPunto(int x, int y)
//{
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//}
//
//void DibujaLinea(Punto2D p1, Punto2D p2)
//{
//	glBegin(GL_LINES);
//	glVertex3f(p1.x1, p1.y1, p1.z1);
//	glVertex3f(p2.x1, p2.y1, p2.z1);
//	glEnd();
//	glFlush();
//}
//
//int factorial(int x)
//{
//	int fac = 1;
//	for (int i = 2; i <= x; i++) fac *= i;
//	return fac;
//}
//
//int CoeficienteBinomial(int n, int i)
//{
//	int a = factorial(n);
//	int b = factorial(i);
//	int c = factorial(n-i);
//	int cb = a / (b*c);
//	return cb;
//}
//
//Punto2D DibujaBezier(double t)
//{
//	Punto2D P;
//	P.init();
//	//glTranslated(100, 100, 5);
//	int n = NUMPOINTS - 1;
//	for (int i = 0; i < NUMPOINTS; i++)
//	{
//		P.x1 += CoeficienteBinomial(n, i)*(puntosControl[i].x1)*(pow((i - t), n - i))*(pow(t, i));
//		P.y1 += CoeficienteBinomial(n, i)*(puntosControl[i].y1)*(pow((i - t), n - i))*(pow(t, i));
//	}
//	cout << P.x1 << " - " << P.y1;
//	return P;
//}
//
//Poligono2D* getPoligono()
//{
//	return Pol;
//}
//
//void Mykey(int key, int x, int y)
//{
//	double X, Y;
//	X = 0;
//	Y = 0;
//	int zoomX, zoomY;
//	zoomX = 1;
//	zoomY = 1;
//
//	if (key == GLUT_KEY_F1 && puntosControl.size() > 2)
//	{
//		glColor3f(1.0, 1.0, 1.0);
//		for (int i = 0; i < NUMPOINTS - 1; i++)
//		{
//			DibujaLinea(puntosControl[i], puntosControl[i + 1]);
//		}
//
//		glColor3f(0.0, 0.0, 1.0);
//		Punto2D POld = puntosControl[0];
//		for (double t = 0.0; t <= 1.0; t += 0.005)
//		{
//			Punto2D P = DibujaBezier(t);
//			glColor3f(1.0, 0.0, 0.0);
//			//P.Trasladar(X, Y);
//			DibujaLinea(POld, P);
//			
//
//
//			/*for (double w = 10; w <= 100.0; w = w+ 10)
//			{
//				Punto2D P1, P2;
//				glColor3f(0.0, 1.0, 0.0);
//				P1.setX(P.getX() + w);
//				P1.setY(P.getY() + w);
//				P2.setX(POld.getX() + w);
//				P2.setY(POld.getY() + w);
//
//				DibujaLinea(P1, P2);
//				cout << w << endl;
//			}*/
//
//			POld = P;
//		}
//		////Pregunta 2
//		//DibujaLinea(puntosControl[0], puntosControl[(NUMPOINTS - 1)/2]);
//
//		//DibujaLinea(puntosControl[((NUMPOINTS - 1) / 2)], puntosControl[NUMPOINTS - 1]);
//		////Pregunta 4 (cierra la figura)
//		//DibujaLinea(puntosControl[0], puntosControl[NUMPOINTS - 1]);
//		//glColor3f(1.0, 1.0, 0.0);
//	}
//	if (key == GLUT_KEY_F2)
//	{
//		puntosControl = vector<Punto2D>();
//		NUMPOINTS = 0;
//	}
//
//	
//	//Pregunta 3
//
//	switch (key)
//	{
//	case GLUT_KEY_DOWN:
//		Y--;
//		break;
//	case GLUT_KEY_UP:
//		Y++;
//		break;
//	case GLUT_KEY_LEFT:
//		X++;
//		break;
//	case GLUT_KEY_RIGHT:
//		X--;
//		break;
//	}
//	/*if (key = GLUT_KEY_PAGE_UP)
//	{
//		zoomX += 1;
//	}*/
//
//	//cout << base->getX() << " - " << base->getY() << endl;
//	cout << x << " - " << y << endl;
//	//base->Escalar(*base,zoomX,zoomY);
//	//glutPostRedisplay();
//}
//
//void MyMouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON&& state == GLUT_DOWN)
//	{
//		Punto2D aux;
//		aux.setxy((float)x, (float)(SCREEN_HEIGHT - y));
//		puntosControl.push_back(aux);
//		NUMPOINTS++;
//
//		DibujarPunto(x, SCREEN_HEIGHT - y);
//	}
//}
//
////void CrearPoligono() {
////	//Creamos poligono	
////	Pol = new Poligono2D(5);
////	Pol->setVertice(0, 10, 12);
////	Pol->setVertice(1, 16, 12);
////	Pol->setVertice(2, 16, 18);
////	Pol->setVertice(3, 13, 21);
////	Pol->setVertice(4, 10, 18);
////
////	base = new Punto2D();
////	ipb = 0;
////	tipoTransformacion = 0;
////	rotar = 0;
////	espesor = 1;
////}
//
//void initRendering() {
//	//glColor(R,G,B,alfa)
//	glClearColor(0, 0, 0, 0);
//}
//
//void Reshape(int w, int h) {
//	//tarea: transformacion de coordenadas(geometria analitica)
//	glViewport(0, 0, w, h); //puerto de visualizacion
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	//modifica la perspectiva en frustum (por revisar)
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.);
//}
//
////void Display() {
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glMatrixMode(GL_MODELVIEW);
////	//Cargar la matriz de identidad
////	glLoadIdentity();
////	//Realizar una translacion de la escena(model, camara)
////	glTranslated(-15, -15, -40);
////	glColor3f(0.3f, 0.3f, 0.3f);
////	//Inicializa el moto para graficar lineas
////	//Grafica lineaas horizontales
////	glBegin(GL_LINES);
////	for (int i = 0; i <= 30; i++) {
////		glVertex3f(0, i, 0); //punto inicial
////		glVertex3f(30, i, 0); //punto final
////	}
////	glEnd();
////	//Tarea: lineas verticales
////	glBegin(GL_LINES);
////	for (int i = 0; i <= 30; i++) {
////		glVertex3f(i, 0, 0); //punto inicial
////		glVertex3f(i, 30, 0); //punto final
////	}
////	glEnd();
////	////Dibujar vertices
////	glClear(GL_DEPTH_BUFFER_BIT);
////	glPointSize(5.0f);
////	glColor3f(0.6f, 0.6f, 0.6f);
////	glBegin(GL_POINTS);
////	for (int i = 0; i <= 30; i++)
////	{
////		for (int j = 0; j <= 30; j++)
////		{
////			glVertex3f(i, j, 0);
////		}
////	}
////	glEnd();
////	//Dibujar el cuadrado de punto asociado de control
////	CrearPoligono();
////
////	base->setX(Pol->getVertice(ipb)->getX());
////	base->setY(Pol->getVertice(ipb)->getY());
////
////	glColor3f(1, 1, 1);
////	glBegin(GL_LINE_LOOP);
////	glVertex3d(base->getX() - 0.5f, base->getY() - 0.5f, 0);
////	glVertex3d(base->getX() + 0.5f, base->getY() - 0.5f, 0);
////	glVertex3d(base->getX() + 0.5f, base->getY() + 0.5f, 0);
////	glVertex3d(base->getX() - 0.5f, base->getY() + 0.5f, 0);
////	glEnd();
////
////	//Crear poligono
////	glClear(GL_DEPTH_BUFFER_BIT);
////	glColor3f(1, 1, 0);
////	glBegin(GL_LINE_LOOP);
////	for (int i = 0; i < Pol->cantidadVertices(); i++)
////	{
////		Punto2D* v = Pol->getVertice(i);
////		glVertex3d(v->getX(), v->getY(), 0);
////	}
////	glEnd();
////
////	glBegin(GL_LINE_LOOP);
////	for (int i = 0; i < Pol->cantidadVertices(); i++)
////	{
////		Punto2D* v = Pol->getVertice(i);
////		glVertex3d(v->getX(), v->getY(), espesor);
////	}
////	glEnd();
////
////	glBegin(GL_LINES);
////	for (int i = 0; i < Pol->cantidadVertices(); i++)
////	{
////		Punto2D* v = Pol->getVertice(i);
////		glVertex3d(v->getX(), v->getY(), 0);
////		glVertex3d(v->getX(), v->getY(), espesor);
////	}
////	glEnd();
////
////	//swap
////	glutSwapBuffers();
////	glFlush();
////}
//
////void bezier_plane() {
////	for (int i = 0; i < 20; i++) {
////		for (int j = 0; j < 20; j++) {
////			grid[i][j].x = 0;
////			grid[i][j].y = 0;
////			grid[i][j].z = 0;
////		}
////	}
////	//Creates the grid using bezier calculation
////	CalcBezier();
////	for (int i = 0; i < 19; i++) {
////		for (int j = 0; j < 19; j++) {
////			Vector p1, p2, p3, normal;
////			p1.x = grid[i + 1][j + 1].x - grid[i][j].x; p1.y = grid[i + 1][j + 1].y - grid[i][j].y; p1.z = grid[i + 1][j + 1].z - grid[i][j].z;
////			p2.x = grid[i + 1][j].x - grid[i][j].x;   p1.y = grid[i + 1][j].y - grid[i][j].y; p1.z = grid[i + 1][j].z - grid[i][j].z;
////
////			normal = CalcNormal(p2, p1);
////			double first = dotproduct(normal, Camera);
////
////			p3.x = grid[i][j + 1].x - grid[i][j].x; p3.y = grid[i][j + 1].y - grid[i][j].y; p3.z = grid[i][j + 1].z - grid[i][j].z;
////
////			normal = CalcNormal(p1, p3);
////			double second = dotproduct(normal, Camera);
////
////			if (first < 0 && second < 0) {
////				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////				glColor3f(0, 1, 0);
////				glBegin(GL_TRIANGLE_STRIP);
////				glVertex3f(grid[i][j].x, grid[i][j].y, grid[i][j].z);
////				glVertex3f(grid[i][j + 1].x, grid[i][j + 1].y, grid[i][j + 1].z);
////				glVertex3f(grid[i + 1][j].x, grid[i + 1][j].y, grid[i + 1][j].z);
////				glVertex3f(grid[i + 1][j + 1].x, grid[i + 1][j + 1].y, grid[i + 1][j + 1].z);
////				glEnd();
////			}
////			else if (first < 0 && second > 0) {
////				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////				glColor3f(0, 1, 0);
////				glBegin(GL_TRIANGLE_STRIP);
////				glVertex3f(grid[i][j].x, grid[i][j].y, grid[i][j].z);
////				glVertex3f(grid[i + 1][j].x, grid[i + 1][j].y, grid[i + 1][j].z);
////				glVertex3f(grid[i + 1][j + 1].x, grid[i + 1][j + 1].y, grid[i + 1][j + 1].z);
////				glEnd();
////			}
////			else if (first > 0 && second < 0) {
////				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////				glColor3f(0, 1, 0);
////				glBegin(GL_TRIANGLE_STRIP);
////				glVertex3f(grid[i][j].x, grid[i][j].y, grid[i][j].z);
////				glVertex3f(grid[i][j + 1].x, grid[i][j + 1].y, grid[i][j + 1].z);
////				glVertex3f(grid[i + 1][j + 1].x, grid[i + 1][j + 1].y, grid[i + 1][j + 1].z);
////				glEnd();
////			}
////		}
////	}
////}
//
//
//int main(int argc, char *argv[]) {
//
//	//Bezier
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 150);
//	glutCreateWindow("Curva de Bezier: ");
//	
//	glutMouseFunc(MyMouse);
//	glutDisplayFunc(myDisplay);
//	glutSpecialFunc(Mykey);
//	//glutReshapeFunc(Reshape);
//	myInit();
//	glutMainLoop();
//
//	return(0);
//}

#include<iostream>
#include "libs\glut.h"
#include "Punto.h"
#include "Poligono2D.h"
using namespace std;

Poligono2D* Pol;
Punto2D* base;

//Globales Variables para operaciones
int ipb;
int tipoTransformacion;
int rotar;
double espesor;
//Curvas Bezier
int SCREEN_HEIGHT = 480;
int NUMPOINTS = 0;
vector <Punto2D> puntosControl;

//Funciones Bezier
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
	glVertex3f(p1.x1, p1.y1, p1.z1);
	glVertex3f(p2.x1, p2.y1, p2.z1);
	glEnd();
	glFlush();
}

int Factorial(int x)
{
	int fact = 1;
	for (int i = 2; i <= x; i++)
	{
		fact *= i;
	}
	return fact;
}

int CoeficienteBinomial(int n, int i)
{
	int a = Factorial(n);
	int b = Factorial(i);
	int c = Factorial(n - i);
	int cb = a / (b*c);
	return cb;
}

Punto2D Dibujabezier(double t)
{
	Punto2D P;
	P.init();
	int n = NUMPOINTS - 1;
	for (int i = 0; i < NUMPOINTS; i++)
	{
		P.x1 += CoeficienteBinomial(n, i)*(puntosControl[i].x1)*(pow((1 - t), n - i)*pow(t, i));
		P.y1 += CoeficienteBinomial(n, i)*(puntosControl[i].y1)*(pow((1 - t), n - i)*pow(t, i));
	}
	return P;
}

void Mykey(int key, int x, int y)
{
	if (key == GLUT_KEY_F1 && puntosControl.size() > 2)
	{
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 0; i < NUMPOINTS - 1; i++)
		{
			DibujaLinea(puntosControl[i], puntosControl[i + 1]);
		}

		glColor3f(0.0, 0.0, 1.0);
		Punto2D POld = puntosControl[0];
		for (double t = 0.0; t <= 1.0; t += 0.005)
		{
			Punto2D P = Dibujabezier(t);
			DibujaLinea(POld, P);
			POld = P;
		}

		glColor3f(1.0, 1.0, 0.0);
	}
	if (key == GLUT_KEY_F2)
	{
		puntosControl = vector<Punto2D>();
		NUMPOINTS = 0;
	}
}

void MyMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON&& state == GLUT_DOWN)
	{
		Punto2D aux;
		aux.setxy((float)x, (float)(SCREEN_HEIGHT - y));
		puntosControl.push_back(aux);
		NUMPOINTS++;

		DibujarPunto(x, SCREEN_HEIGHT - y);
	}
}

void CrearPoligono() {
	//Creamos poligono	
	Pol = new Poligono2D(5);
	Pol->setVertice(0, 10, 12);
	Pol->setVertice(1, 16, 12);
	Pol->setVertice(2, 16, 18);
	Pol->setVertice(3, 13, 21);
	Pol->setVertice(4, 10, 18);

	base = new Punto2D();
	ipb = 0;
	tipoTransformacion = 0;
	rotar = 0;
	espesor = 1;
}

void initRendering() {
	//glColor(R,G,B,alfa)
	glClearColor(0, 0, 0, 0);
}

void Reshape(int w, int h) {
	//tarea: transformacion de coordenadas(geometria analitica)
	glViewport(0, 0, w, h); //puerto de visualizacion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//modifica la perspectiva en frustum (por revisar)
	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.);
}

//void Display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	//Cargar la matriz de identidad
//	glLoadIdentity();
//	//Realizar una translacion de la escena(model, camara)
//	glTranslated(-15, -15, -40);
//	glColor3f(0.3f, 0.3f, 0.3f);
//	//Inicializa el moto para graficar lineas
//	//Grafica lineaas horizontales
//	glBegin(GL_LINES);
//	for (int i = 0; i <= 30; i++) {
//		glVertex3f(0, i, 0); //punto inicial
//		glVertex3f(30, i, 0); //punto final
//	}
//	glEnd();
//	//Tarea: lineas verticales
//	glBegin(GL_LINES);
//	for (int i = 0; i <= 30; i++) {
//		glVertex3f(i, 0, 0); //punto inicial
//		glVertex3f(i, 30, 0); //punto final
//	}
//	glEnd();
//	////Dibujar vertices
//	glClear(GL_DEPTH_BUFFER_BIT);
//	glPointSize(5.0f);
//	glColor3f(0.6f, 0.6f, 0.6f);
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= 30; i++)
//	{
//		for (int j = 0; j <= 30; j++)
//		{
//			glVertex3f(i, j, 0);
//		}
//	}
//	glEnd();
//	//Dibujar el cuadrado de punto asociado de control
//	CrearPoligono();
//
//	base->setX(Pol->getVertice(ipb)->getX());
//	base->setY(Pol->getVertice(ipb)->getY());
//
//	glColor3f(1, 1, 1);
//	glBegin(GL_LINE_LOOP);
//	glVertex3d(base->getX() - 0.5f, base->getY() - 0.5f, 0);
//	glVertex3d(base->getX() + 0.5f, base->getY() - 0.5f, 0);
//	glVertex3d(base->getX() + 0.5f, base->getY() + 0.5f, 0);
//	glVertex3d(base->getX() - 0.5f, base->getY() + 0.5f, 0);
//	glEnd();
//
//	//Crear poligono
//	glClear(GL_DEPTH_BUFFER_BIT);
//	glColor3f(1, 1, 0);
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < Pol->cantidadVertices(); i++)
//	{
//		Punto2D* v = Pol->getVertice(i);
//		glVertex3d(v->getX(), v->getY(), 0);
//	}
//	glEnd();
//
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < Pol->cantidadVertices(); i++)
//	{
//		Punto2D* v = Pol->getVertice(i);
//		glVertex3d(v->getX(), v->getY(), espesor);
//	}
//	glEnd();
//
//	glBegin(GL_LINES);
//	for (int i = 0; i < Pol->cantidadVertices(); i++)
//	{
//		Punto2D* v = Pol->getVertice(i);
//		glVertex3d(v->getX(), v->getY(), 0);
//		glVertex3d(v->getX(), v->getY(), espesor);
//	}
//	glEnd();
//
//	//swap
//	glutSwapBuffers();
//	glFlush();
//}

int main(int argc, char *argv[]) {
	//Bezier
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Curva de Bezier: ");

	glutMouseFunc(MyMouse);
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(Mykey);

	myInit();
	glutMainLoop();

	return(0);
}