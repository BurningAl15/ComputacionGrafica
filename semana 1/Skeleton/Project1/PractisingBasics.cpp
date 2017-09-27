//#include "libs\glut.h"
//#include <stdlib.h>
//
//using namespace std;
////
////void initializing()
////{
////	//Inicializar el color del buffer
////	glClearColor(0, 0, 0, 0);
////}
////
//void Disp()
//{
//	//Matriz de camara, matriz del model
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	//Cargar la matriz de identidad
//	glLoadIdentity();
//
//	//Realizar una translación de la escena(model,camara)
//	glTranslatef(-25, -30, -50);
//
//	//glRotatef(-45, 1, 1, 0);
//
//	glColor3f(0.3f, 0.3f, 0.3f);
//	////Grid
//	//glBegin(GL_LINES);
//	//glColor3f(1.f, 0.f, 0.f);
//	//for (int i = 0; i <= 30; i++)
//	//{
//	//	//glVertex3f(0,i,0);
//	//	//glVertex3f(30,i,0);
//	//	////En Y (Vertical)
//	//	//glVertex3f(i, 0, 0); //Punto inicial
//	//	//glVertex3f(i, 30, 0); //Punto Final
//
//	//	glVertex3f(0, 0, 0); //Punto inicial
//	//	glVertex3f(30, 30, 0); //Punto Final
//	//}
//	//glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.f, 0.f, 1.f);
//	//glVertex3f(100, 200, 0);
//	/*for (int i = 0; i <= 50; i++)
//	{*/
//		glVertex3f(25, 10, 0);
//		glVertex3f(25, 30, 0);
//		glVertex3f(50, 10, 0);
//		glVertex3f(50, 30, 0);
//	//}
//	glEnd();
//
//	glutSwapBuffers();
//	glFlush();
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
//	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 200.0);
//}
//
//
//int main()
//{
//	//Inicializar Glut
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB /*| GLUT_DEPTH*/);
//	glutInitWindowSize(800, 600);
//	
//	//Crear ventanas
//	glutCreateWindow("Basics");
//	//initializing();
//
//	//funciones manipuladoras
//	glutDisplayFunc(Disp);
//	glutReshapeFunc(Reshape);
//
//
//	//Loop principal
//	glutMainLoop();
//
//	return EXIT_SUCCESS;
//}
//
//
