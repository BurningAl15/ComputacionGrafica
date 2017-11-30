//#include "libs\glut.h"
//
//#include <stdlib.h>
//#include <iostream>
//#include "Libraries\RgbImage.h"
//#include <time.h>
//#include <Windows.h>
//using namespace std;
//int tick = -1;
//int slices = 16;
//int stacks = 16;
//int width=1920, height=1080;
//
////Camera variables
//float zoom = -5;
//float horizontal = 0;
//float vertical = 0;
//
//float transformVal = 0.5f;
//
////Objects transformations
//float rotationX=0;
//float rotationY = 0;
//float rotationZ = 0;
//float translationX=0;
//float translationY = 0;
//float translationZ = -6;
//
//
//static void initializing(void)
//{
//	//Inicializar el color del buffer
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//void LoadTextureFromFile(char *filename)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST);
//	RgbImage theTexMap(filename);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
//}
//
//
//char* filename = "RedLeavesTexture.bmp";
//char* ground = "VENUS.bmp";
//
//static void
//resize(int width, int height) {
//	const float ar = (float)width / (float)height;
//
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-ar-zoom+horizontal, ar+zoom+horizontal, -1.0-zoom+vertical, 1.0+zoom+vertical, 2.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);	
//	glLoadIdentity();
//	
//}
//
//
//static void
//display(void)
//{
//	resize(width, height);
//	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
//	const double a = t*90.0;
//
//	const double tm = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
//	double am = 20.0;
//	srand(time(nullptr));
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glColor3d(1, 0, 0);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//	
//	glPushMatrix();
//	LoadTextureFromFile(filename);		
//	glTranslated(translationX, translationY-1, translationZ+2);
//	glRotated(rand() %60 + rotationX, 1, 0, 0);
//	glRotated(rand() % 60 + rotationY, 0, 1, 0);
//	glRotated(rand() % 60 + rotationZ, 0, 0, 1);
//	glRotated(a, 0, 0, 1);
//	glScalef(rand() % 4, rand() % 4, rand() % 4);
//	glutSolidCube(1);
//	glPopMatrix();
//
//	//
//	LoadTextureFromFile(ground);
//	glPushMatrix();
//
//	glTranslated(translationX-8, translationY+8, translationZ - 2);
//	glRotated(rand() %60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//	
//	glPushMatrix();
//	glTranslated(tick, translationY+6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glTranslated(translationX +8, translationY + 6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(-tick, translationY + 6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	//
//
//	glPushMatrix();
//	glTranslated(translationX - 8, translationY - 6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(tick, translationY - 6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glTranslated(translationX + 8, translationY - 6, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(-tick, translationY - 6, translationZ-2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(translationX-8, tick, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(translationX+8, tick, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(-tick, tick, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(tick, tick, translationZ - 2);
//	glRotated(rand() % 60 + rotationX, 1, 0, 0);
//	glRotated(a, rand(), rand(), rand());
//	glutSolidSphere(2, slices, stacks);
//	glPopMatrix();
//
//
//	glDisable(GL_TEXTURE_2D);
//	glFlush();
//	
//	glutSwapBuffers();
//	glutPostRedisplay();
//	Sleep(5);
//}
//
//
//static void
//key(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 27:
//	case 'q':
//		exit(0);
//		break;
//
//	case '+':
//		slices++;
//		stacks++;
//		break;
//
//	case '-':
//		
//		if (slices>3 && stacks>3)
//		{
//			slices--;
//			stacks--;
//		}
//		break;
//	//Object movement
//	case '4':
//		translationX -= transformVal;
//		break;
//	case '6':
//		translationX += transformVal;
//		break;
//
//	case '8':
//		translationY += transformVal;
//		break;
//
//	case '5':
//		translationY = transformVal;
//		break;
//
//	case '7':
//		translationZ -= transformVal;
//		break;
//
//	case '9':
//		translationZ += transformVal;
//		break;
//
//	case 'z':
//		rotationX -= transformVal;
//		break;
//	case 'x':
//		rotationX += transformVal;
//		break;
//	case 'c':
//		rotationY -= transformVal;
//		break;
//	case 'v':
//		rotationY += transformVal;
//		break;
//	case 'b':
//		rotationZ -= transformVal;
//		break;
//	case 'n':
//		rotationZ += transformVal;
//		break;
//	//Camera movement
//	/////////////////////Full zoom ///////////////////////////////
//	case 'p':
//		if(zoom>-0.5 && zoom <30)
//			zoom+=transformVal;
//		else
//		{
//			zoom = 0;
//		}
//			cout << zoom<<endl;
//		break;		
//	case 'l':
//		if (zoom > -0.5 && zoom < 30)
//			zoom-= transformVal;
//		else {
//			zoom = 29.5;
//		}
//			cout << zoom << endl;
//		break;
//	
//	//Horizontal camera movement
//	case 'a':
//		horizontal -= transformVal;
//		break;
//	case 'd':
//		horizontal += transformVal;
//		break;
//
//	//Vertical camera movement
//	case 'w':
//		vertical -= transformVal;
//		break;
//	case 's':
//		vertical += transformVal;
//		break;
//	}
//	//cout << rotationX << " - " << rotationY << " - " << rotationZ << " .. " << endl;
//	
//	glutPostRedisplay();
//}
//
//static void idle(void)
//{
//	tick++;
//	int dir = 0;
//	if (tick >= 5)
//	{
//		dir = -1;
//		tick = tick*dir;
//		slices++;
//		stacks++;
//	}
//	/*if (slices>3 && stacks>3)
//	{
//		slices--;
//		stacks--;
//	}
//	if(slices<3 && stacks<3)
//	{
//		slices++;
//		stacks++;
//
//	}*/
//	
//	cout <<tick<< " - " << stacks << " - " << slices << endl;
//	glutPostRedisplay();
//}
//
//const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
//
//const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
//const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//const GLfloat high_shininess[] = { 100.0f };
//
//
//int main() {
//	
//	glutInitWindowSize(width, height);
//	glutInitWindowPosition(10, 10);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//	
//	glutCreateWindow("Trabajo Final CompuGrafica - Vera");
//	//initializing();
//	
//	glutDisplayFunc(display);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(key);
//	glutIdleFunc(idle);	
//	
//	glClearColor(1, 1, 1, 1);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	glEnable(GL_LIGHT0);
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//
//	glutMainLoop();
//
//	return EXIT_SUCCESS;
//}
