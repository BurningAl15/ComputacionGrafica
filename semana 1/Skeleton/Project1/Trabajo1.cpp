//#include "libs\glut.h"
//#include <stdlib.h>
//#include <iostream>
//#include <ctime>
//#include <windows.h>
//
//double posx = -20.f;
//double posy = -20.f;
//double posz = 0.f;
//float figX = -5.f, figY = -5.f;
//
//
//double angle = 0.f;
//
//using namespace std;
//int vertices = 0;
//void initializing()
//{
//	//Inicializar el color del buffer
//	glClearColor(1.0f, 0, 0, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void Disp()
//{
//	srand(time(nullptr));
//	vertices = rand() % 4 + 3;
//	//Matriz de camara, matriz del model
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	//Cargar la matriz de identidad
//	glLoadIdentity();
//
//	//Realizar una translación de la escena(model,camara)
//	glTranslatef(0, 0, posz);
//	glRotatef(angle, 0, 0, 1);
//
//	float r, g, b;
//
//	//double aumento = 0.5f;
//	/*for (int i = 0; i < 10; i++)
//	{
//		
//		if (posz >= -15.f || posz <= 0)
//		{
//			aumento*=-1;
//		}
//		posz += aumento;
//		Sleep(1);
//	}*/
//
//
//	glBegin(GL_POLYGON);
//	glColor3f(0,1,0);
//	glVertex3f(-0.5f, -0.5f, posz-5);
//	glColor3f(0, 0, 1);
//	glVertex3f(-0.75f, 0.f, posz -5);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.5f, 0.5f, posz -5);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.f, 0.75f, posz -5);
//	glColor3f(0, 0, 1);
//	glVertex3f(0.5f, 0.5f, posz -5);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.75f, 0.f, posz -5);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.5f, -0.5f, posz -5);
//	glColor3f(0, 0, 1);
//	glVertex3f(0.f, 0.75f, posz -5);
//
//
//
//
//	glEnd();
//	
//	glFlush();
//	glutSwapBuffers(); glutPostRedisplay();
//}
//
//
//void Reshape(int w, int h)
//{
//	//Tarea: Transformación de coordenadas(geometría analítica)
//	glViewport(0, 0, w, h); //puerto de visualizacion
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	//Modifica la perspectiva en frustrum(por revisar)
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 400.0);
//}
//
//void Resize(int w, int h)
//{
//	/*if (w >= h)
//	{
//		glViewport(0, 0, (GLsizei)h, (GLsizei)h);
//	}
//	else
//	{
//		glViewport(0, 0, (GLsizei)w, (GLsizei)w);
//	}
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 400.0);*/
//
//	
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //puerto de visualizacion
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	//Modifica la perspectiva en frustrum(por revisar)
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 0,100.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//
//void myTimeOut(int id)
//{
//	angle += 5;
//	glutPostRedisplay();
//	glutTimerFunc(100, myTimeOut, 0);
//}
//
//void myKeyboard(unsigned char key, int x, int y)
//{
//	if ((key == '-') || (key == 'd')) posz -= 0.1f;
//	if ((key == '+') || (key == 'i')) posz += 0.1f;
//}
//
//int main()
//{
//	//Inicializar Glut
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB /*| GLUT_DEPTH*/);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(500, 500);
//
//	//Crear ventanas
//	glutCreateWindow("Perspective");
//	//initializing();
//
//	//funciones manipuladoras
//
//	glutDisplayFunc(Disp);
//	glutKeyboardFunc(myKeyboard);
//	glutTimerFunc(100, myTimeOut, 0);
//	glutReshapeFunc(Resize);
//
//	//Loop principal
//	glutMainLoop();
//
//	return EXIT_SUCCESS;
//}
