//#include "libs\glut.h"
//#include <stdlib.h>
//#include <iostream>
////#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//
//double posx = -20.f;
//double posy = -20.f;
//double posz = rand() % 100 - 20.f;
//float figX = -5.f, figY=-5.f;
//
//
//double angle = 0.f;
//double scale = 0.1f;
//using namespace std;
//int vertices = 0;
//void initializing()
//{
//	//Inicializar el color del bufferx	
//	glClearColor(0, 0, 0, 0);
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
//	glPushMatrix();
//	//Realizar una translación de la escena(model,camara)
//	glTranslatef(posy, posx, posz-200);
//	glRotatef(angle, posy, posx, posz-200);
//	glScalef(posy*scale, posx*scale, -200);
//	
//	float r, g, b;
//	float aumento=0.1f;
//	
//	for (int i = 0; i < 1; i++)
//	{
//		r = static_cast <float> (rand()) / static_cast <float> (10000);
//		g = static_cast <float> (rand()) / static_cast <float> (10000);
//		b = static_cast <float> (rand()) / static_cast <float> (10000);
//		posz = rand() % 50 - 20.f;
//		figX= rand() % 80 - 50.f;
//		figY = rand() % 80 - 50.f;
//		
//		switch (vertices)
//		{
//		case 3:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX+25, figY+10, 0);
//			glVertex3f(figX+37.5f, figY+30, 0);
//			glVertex3f(figX+50, figY+10, 0);
//			break;
//		case 4:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX+25, figY+10, 0);
//			glVertex3f(figX+25, figY + 30, 0);
//			glVertex3f(figX+50, figY + 30, 0);
//			glVertex3f(figX+50, figY + 10, 0);
//			break;
//		case 5:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX + 25, figY + 10, 0);
//			glVertex3f(figX + 25, figY + 30, 0);
//			glVertex3f(figX + 37.5f, figY + 40, 0);
//			glVertex3f(figX + 50, figY + 30, 0);
//			glVertex3f(figX + 50, figY + 10, 0);
//			break;
//		case 6:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX + 25, figY + 5, 0);
//			glVertex3f(figX + 10, figY + 20, 0);
//			glVertex3f(figX + 25, figY + 35, 0);
//			glVertex3f(figX + 50, figY + 35, 0);
//			glVertex3f(figX + 65, figY + 20, 0);
//			glVertex3f(figX + 50, figY + 5, 0);
//			break;
//		case 7:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX + 25, figY + 5, 0);
//			glVertex3f(figX + 10, figY + 20, 0);
//			glVertex3f(figX + 25, figY + 35, 0);
//			glVertex3f(figX + 37.5f, figY + 45, 0);
//			glVertex3f(figX + 50, figY + 35, 0);
//			glVertex3f(figX + 65, figY + 20, 0);
//			glVertex3f(figX + 50, figY + 5, 0);
//			break;
//		
//		default:
//			glBegin(GL_POLYGON);
//			glColor3f(r, g, b);
//			glVertex3f(figX + 25, figY + 10, 0);
//			glVertex3f(figX + 37.5f, figY + 30, 0);
//			glVertex3f(figX + 50, figY + 10, 0);
//			break;
//		}
//		glEnd();
//		vertices=rand() % 4 + 3;
//		
//		angle++;
//		Sleep(2);
//	}
//
//	
//	glPopMatrix();
//	glutSwapBuffers();
//	glFlush(); glutPostRedisplay();
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
//
//
//int main()
//{
//	//Inicializar Glut
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB /*| GLUT_DEPTH*/);
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(1600, 1080);
//	
//	//Crear ventanas
//	glutCreateWindow("Basics");
//	//initializing();
//
//	//funciones manipuladoras
//
//	glutDisplayFunc(Disp);
//	glutReshapeFunc(Reshape);
//	
//	//Loop principal
//	glutMainLoop();
//
//	return EXIT_SUCCESS;
//}


