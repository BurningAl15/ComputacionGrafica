//#include <iostream>
//#include <stdlib.h>
//#include <Windows.h>
//#include <math.h>
//#include <glut.h>
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
//	glColor3f(1.0, 1.0, 1.0);
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
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex3f(p1.x1, p1.y1, p1.z1);
//	glVertex3f(p2.x1, p2.y1, p2.z1);
//	glEnd();
//
//	glPushMatrix();
//	glColor3f(1.0, 0.0, 0.0);
//	glTranslatef((p1.x1+ p2.x1)/2, (p1.y1 + p2.y1)/2, (p1.z1-5.0+ p2.z1)/2);
//	glutSolidSphere(15, 15, 15);
//	glPopMatrix();
//	
//
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
//	//P.init();
//	int n = NUMPOINTS - 1;
//	for (int i = 0; i < NUMPOINTS; i++)
//	{
//		P.x1 += CoeficienteBinomial(n, i)*(puntosControl[i].x1)*(pow((i - t), n - i))*(pow(t, i));
//		P.y1 += CoeficienteBinomial(n, i)*(puntosControl[i].y1)*(pow((i - t), n - i))*(pow(t, i));
//	}
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
//		for (double t = 0.0; t <= 3.0; t += 0.005)
//		{
//			Punto2D P = DibujaBezier(t);
//			//glColor3f(1.0, 0.0, 0.0);
//			//P.Trasladar(X, Y);
//			DibujaLinea(POld, P);
//			
//
//			POld = P;
//		}
//		/*DibujaLinea(puntosControl[0], puntosControl[NUMPOINTS - 1]);
//		glColor3f(1.0, 1.0, 0.0);*/
//	}
//	if (key == GLUT_KEY_F2)
//	{
//		puntosControl = vector<Punto2D>();
//		NUMPOINTS = 0;
//	}
//
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
//void CrearPoligono() {
//	//Creamos poligono	
//	Pol = new Poligono2D(5);
//	Pol->setVertice(0, 10, 12);
//	Pol->setVertice(1, 16, 12);
//	Pol->setVertice(2, 16, 18);
//	Pol->setVertice(3, 13, 21);
//	Pol->setVertice(4, 10, 18);
//
//	base = new Punto2D();
//	ipb = 0;
//	tipoTransformacion = 0;
//	rotar = 0;
//	espesor = 1;
//}
//
//void initRendering() {
//	//glColor(R,G,B,alfa)
//	glClearColor(0, 0, 0, 0);
//}
//
//void Reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.);
//}
//
//int main(int argc, char *argv[]) {
//
//	//Bezier
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(10, 15);
//	glutCreateWindow("Curva de Bezier: ");
//
//	glutMouseFunc(MyMouse);
//	glutDisplayFunc(myDisplay);
//	glutSpecialFunc(Mykey);
//
//	myInit();
//	glutMainLoop();
//
//	return(0);
//}