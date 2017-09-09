//#include "libs\glut.h"
//#include <vector>
//#include "Poligono2D.h"
//using namespace std;
//
//double pi = 3.1415926535897;
//
//int gridX = 30;
//int gridY = 30;
//Poligono2D* Pol;
//Punto2D* base;
//int ipb;
//int tipoTransformacion;
//int rotar;
//int espesor;
//float v_x, v_y, v_z;
//
//
//void crearPoligono()
//{
//	base = new Punto2D();
//	ipb = 0;
//	tipoTransformacion = 0;
//	rotar = 0;
//	espesor = 1;
//
//	v_x = -gridX / 2;
//	v_y = -gridY / 2;
//	v_z = -40;
//
//	Pol = new Poligono2D(5);
//	Pol->setVertice(0, 10, 12);
//	Pol->setVertice(1, 16, 12);
//	Pol->setVertice(2, 16, 18);
//	Pol->setVertice(3, 13, 21);
//	Pol->setVertice(4, 10, 18);
//
//}
//
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
//	glTranslatef(v_x, v_y, v_z);
//	//Rota la figura en el eje: hlRotatef(grados, ejeX,ejeY,ejeZ)
//	glRotatef(45, 1, 1, 0);
//
//	glColor3f(0.3f, 0.3f, 0.3f);
//	//Inicializa el motor para graficar lineas
//
//	//Grafica lineas horizontales
//	glBegin(GL_LINES);
//	for (int i = 0; i <= gridY; i++)
//	{
//		glVertex3f(0, i, 0); 
//		glVertex3f(gridX, i, 0);
//	}
//
//	glEnd();
//
//	glBegin(GL_LINES);
//	for (int i = 0; i <= gridX; i++)
//	{
//		glVertex3f(i, 0, 0);
//		glVertex3f(i, gridY, 0);
//	}
//
//	glEnd();
//
//	glClear(GL_DEPTH_BUFFER_BIT);
//	glPointSize(5.0f);
//	glColor3f(0.6f, 0.6f, 0.6f);
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= gridX; i++)
//		for (int j = 0; j <= gridY; j++)
//			glVertex3f(i, j, 0);
//	glEnd();
//
//	base->SetX(Pol->getVertice(ipb).GetX());
//	base->SetY(Pol->getVertice(ipb).GetY());
//
//	if (rotar != 0)
//		if (rotar > 0) {
//			Pol->Rotar(base, 1*180/pi);
//			rotar--;
//		}
//		else {
//			Pol->Rotar(base, -1*180/pi);
//			rotar++;
//		}
//
//
//		glColor3f(1, 1, 1);
//		glBegin(GL_LINE_LOOP);
//		glVertex3d(base->GetX() - 0.5f, base->GetY() - 0.5f, 0);
//		glVertex3d(base->GetX() + 0.5f, base->GetY() - 0.5f, 0);
//		glVertex3d(base->GetX() + 0.5f, base->GetY() + 0.5f, 0);
//		glVertex3d(base->GetX() - 0.5f, base->GetY() + 0.5f, 0);
//		glEnd();
//
//		glClear(GL_DEPTH_BUFFER_BIT);
//		glColor3f(1, 1, 0);
//		glBegin(GL_LINE_LOOP);
//		for (int i = 0; i < Pol->cantidadVertices(); i++)
//		{
//			Punto2D v = Pol->getVertice(i);
//			glVertex3d(v.GetX(), v.GetY(), 0);
//		}
//		glEnd();
//
//	
//		glBegin(GL_LINE_LOOP);
//		for (int i = 0; i < Pol->cantidadVertices(); i++)
//		{
//			Punto2D v = Pol->getVertice(i);
//			glVertex3d(v.GetX(), v.GetY(), espesor);
//		}
//		glEnd();
//
//		glBegin(GL_LINES);
//		for (int i = 0; i < Pol->cantidadVertices(); i++)
//		{
//			Punto2D v = Pol->getVertice(i);
//			glVertex3d(v.GetX(), v.GetY(), 0);
//			glVertex3d(v.GetX(), v.GetY(), espesor);
//		}
//		glEnd();
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