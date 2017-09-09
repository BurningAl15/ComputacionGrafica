//#include "libs\glut.h"
//#include <iostream>
//
//using namespace std;
//
//void initRendering()
//{
//	//glColor(R,G,B,alpha)
//	glClearColor(0, 0, 0, 0);
//}
//
//void Reshape(int w, int h)
//{
//	//Tarea: Transformación de coordenadas(geometría analítica)
//	glViewport(0, 0, w, h); //puerto de visualizacion
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	//Modifica la perspectiva en frustrum(por revisar)
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.0);
//}
//
//void Display()
//{
//	//Matriz de camara, matriz del model
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	//Cargar la matriz de identidad
//	glLoadIdentity();
//	//Realizar una translación de la escena(model,camara)
//	glTranslatef(-15, -15, -40);
//	//Rota la figura en el eje: hlRotatef(grados, ejeX,ejeY,ejeZ)
//	glRotatef(-45, 1, 1, 0);
//
//	 glColor3f(0.3f, 0.3f, 0.3f);
//	//Inicializa el motor para graficar lineas
//
//	//Grafica lineas horizontales
//	glBegin(GL_LINES);
//	for (int i = 0; i <= 30; i++)
//	{
//		//En X (Horizontal)
//		glVertex3f(0, i, 0); //Punto inicial
//		glVertex3f(30, i, 0); //Punto Final
//
//		//En Y (Vertical)
//		glVertex3f(i, 0, 0); //Punto inicial
//		glVertex3f(i, 30, 0); //Punto Final
//
//
//		glVertex3f(0 ,0 , 0); //Punto inicial
//		glVertex3f(30, 30, 0); //Punto Final
//	}
//
//	glEnd();
//
//	glClear(GL_DEPTH_BUFFER_BIT);
//	glPointSize(5.0f);
//	glColor3f(0.6f, 0.6f, 0.6f);
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= 30; i++)
//		for (int j = 0; j <= 30; j++)
//			glVertex3f(i, j, 0);
//	glEnd();
//
//
//
//	//Tarea: lineas horizontales
//	//
//
//	glutSwapBuffers();
//	glFlush();
//}
//
//int main()
//{
//	//step1: Initialize GLUT
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(400, 400);
//
//	//step2: Create Window
//	glutCreateWindow("Skeleton - ejercicio ejemplo");
//	//initRendering();
//
//	//step3: Callbacks - Setear máquina de estados.
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//
//	//step4: Main Loop
//	glutMainLoop();
//
//
//
//	return 0;
//}