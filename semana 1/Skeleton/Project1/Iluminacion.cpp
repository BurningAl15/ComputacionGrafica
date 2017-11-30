//#include "libs\glut.h"

//Ejercicio 1

//void init(void)
//{
//	//Valores para las luces 
//	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
//	GLfloat mat_shininess[] = { 50.0 };
//	//Valor para la posicion de la luz
//	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//
//	//Un material para cada tipo de luz (specular, shininess)
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//Posicion de la luz
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//
//}
//
//void Display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidSphere(1.0, 20, 16);
//	glFlush();
//}
//
//void Reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	if (w <= h)
//	{
//		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,
//			1.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
//	}
//	else
//		glOrtho( -1.5*(GLfloat)h / (GLfloat)w,
//			1.5*(GLfloat)h / (GLfloat)w, -1.5, 1.5, -10.0, 10.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//int main()
//{
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Lights");
//	init();
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//
//	return 0;
//}

//Ejercicio 2

//static int spin = 0;

//static void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//
//static void Display(void)
//{
//	GLfloat position[] = { 0.0,0.0,1.5,1.0 };
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -5.0);
//
//	glPushMatrix();
//	glRotated((GLdouble)spin, 0.0, 1.0, 0.0);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//
//	//Cubo que actua como la camara
//	glTranslated(0.0, 0.0, 1.5);
//	glDisable(GL_LIGHTING);
//	glColor3f(0.0, 1.0, 1.0);
//	glutWireCube(0.1);
//	glEnable(GL_LIGHTING);
//	glPopMatrix();
//
//	glutSolidTorus(0.275, 0.85, 8, 15);
//	glPopMatrix();
//	glFlush();
//
//
//}
//
//static void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//static void mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN)
//		{
//			spin = (spin + 30) % 360;
//			glutPostRedisplay();
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//int main() {
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Lights 2");
//	init();
//	glutDisplayFunc(Display);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}

