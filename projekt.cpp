#include <windows.h> 

#include "freeglut.h"

void walls() {
	//Ściany 
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
}

void table() {
	//kolor
	glColor3f(0.0, 1.0, 1.0);
	
	//noga - 4 ściany + góra dół prosotpadłoscian
	GLfloat y = 0.375; //wysokość nogi
	//nogi

	//blat - taka ława do kafki
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, y, -0.25); //tyl lewo
	glVertex3f(0.5, y, -0.25); //tyl prawo
	glVertex3f(0.5, y, 0.25); // dol prawo
	glVertex3f(-0.5, y, 0.25); //dol lewa

	//noga lewa tył
	GLfloat base = 0.125; //grubośc nogi
	GLfloat down = 0.001; //grubośc nogi

	// ------------------------ lewa tylna noga ------------------------
	//podstawa/doł nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25); //tyl lewo - punkt róg stołu
	glVertex3f(-0.5+base, down, -0.25); //tyl prawo
	glVertex3f(-0.5+base, down, -0.25+base); // przod prawo
	glVertex3f(-0.5, down, -0.25+base); //przod lewa

	//TYLNA ściany nogi z jest stałe -0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25); //dół nogi lewo
	glVertex3f(-0.5 + base, down, -0.25); // dół nogi prawo
	glVertex3f(-0.5 + base, y, -0.25); // góra nogi  prawo
	glVertex3f(-0.5, y, -0.25); //góra nogi lewo

	//PRZEDNIA ściany nogi z jest stałe -0.25+base
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25+base); //dół nogi lewo
	glVertex3f(-0.5 + base, down, -0.25+base); // dół nogi prawo
	glVertex3f(-0.5 + base, y, -0.25+base); // góra nogi  prawo
	glVertex3f(-0.5, y, -0.25+base); //góra nogi lewo


	//PRAWA ściany nogi z jest stałe
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25 + base); //dół nogi lewo
	glVertex3f(-0.5 + base, down, -0.25 + base); // dół nogi prawo
	glVertex3f(-0.5 + base, y, -0.25 + base); // góra nogi  prawo
	glVertex3f(-0.5, y, -0.25 + base); //góra nogi lewo

	// ------------------------ PRAWA tylna noga
	//podstawa/doł nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5-base, down, -0.25); //tyl lewo 
	glVertex3f(0.5, down, -0.25); //tyl prawo - punkt stołu
	glVertex3f(0.5, down, -0.25 + base); // przod prawo
	glVertex3f(0.5-base, down, -0.25 + base); //przod lewa


	// ------------------------ PRAWA PRZEDNIA noga
	//podstawa/doł nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, 0.25 -base); //tyl lewo
	glVertex3f(0.5, down, 0.25-base); //tyl prawo 
	glVertex3f(0.5, down, 0.25); // przod prawo  - punkt róg stołu
	glVertex3f(0.5-base, down, 0.25); //przod lewa
	

	// ------------------------ LEWA PRZEDNIA noga
	//podstawa/doł nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, 0.25 - base); //tyl lewo
	glVertex3f(-0.5 +base, down, 0.25 - base); //tyl prawo 
	glVertex3f(-0.5 +base, down, 0.25); // przod prawo  
	glVertex3f(-0.5, down, 0.25); //przod lewa - punkt róg stołu
	
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//"czyszczenie" t�a okan i bufora g��bokosci
	glEnable(GL_DEPTH_TEST);//w��cznie algorytmu zas�aniania
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 10.0); //bry�a widzenia perspektywicznego
	gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//obserwator 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);

	walls();
	table();

	

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