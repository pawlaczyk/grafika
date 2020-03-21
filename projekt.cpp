#include <windows.h> 

#include "freeglut.h"


void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//"czyszczenie" t�a okan i bufora g��bokosci
	glEnable(GL_DEPTH_TEST);//w��cznie algorytmu zas�aniania
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 10.0); //bry�a widzenia perspektywicznego
	gluLookAt(0.0, 0.4, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//obserwator 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);

	//�ciana: y = 0.5

	//czerwona góra
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0); //przod lewo
	glVertex3f(-1.0, 1.0, -1.0); //tyl lewp
	glVertex3f(1.0, 1.0, -1.0); //tyl prawo
	glVertex3f(1.0, 1.0, 1.0); //przod prawo
	

	//dół zielony
	//PODŁOGA
	glColor3f(0.0, 1.0, 0.0); //kolor
	glVertex3f(-1.0, 0.0, -1.0); //góra lewa
	glVertex3f(1.0, 0.0, -1.0);  //góra prawo 
	glVertex3f(1.0, 0.0, 1.0); //dol prawo
	glVertex3f(-1.0, 0.0, 1.0); // dol lewo 
	

	//�ciana: x = 0.5


	//niebieski prawy
	/*
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	*/


	
	//Tylna środek
	//żółta lewa środek
	glColor3f(1.0, 1.0, 0.0);//kolor
	glVertex3f(-1.0, 0.0, 1.0); //lewa dół
	glVertex3f(-1.0, 0.0, -1.0); //prawa doł
	glVertex3f(-1.0, 1.0, -1.0); // gora prawa
	glVertex3f(-1.0, 1.0, 1.0); // gora lewa
	


	//rózowa TYŁ Środek
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(1.0, 0, -1.0);//dol prawo
	glVertex3f(1.0, 1.0, -1.0); //gora prawo
	glVertex3f(-1.0, 1.0, -1.0);//gora lewo
	glVertex3f(-1.0, 0, -1.0); //dol lewo
	


	//morska
	//PRAWA ŚICINA ŚRODEK
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0); //gora lewa
	glVertex3f(1.0, 1.0, 1.0); //gora prawo
	glVertex3f(1.0, 0.0, 1.0); // dol prawo
	glVertex3f(1.0, 0.0, -1.0); //dol lewa
	

	glEnd();

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scena testowa");
	glutDisplayFunc(display);
	glutMainLoop();
}