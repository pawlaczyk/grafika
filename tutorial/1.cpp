//https://www.youtube.com/watch?v=SAmD_Aq1Un4
#include <windows.h> 
#include <iostream>
#include "freeglut.h"

void render(void);

void keyboard(unsigned char c, int x, int y); //musi yć unsgned char
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); //daje wszystkie kolory łącznie z alpha
	glutInitWindowPosition(100, 100); //x, y szerokości
	glutInitWindowSize(640, 480); //szerokosz , wysokosc okna
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard); //function poiner
	glutMouseFunc(mouse);

	glutMainLoop(); //skonczylam proces inicjalizacji, teraz mozna robić renderowanie
}

void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		//escape key
		exit(0);
	} 
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		exit(0);
	}
}

void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//"czyszczenie" t�a okan i bufora g��bokosci

	glBegin(GL_TRIANGLES); //glBegin zawsze sparowane z metodą glEnd
		//glVertex3f // 3D float; kolor przed verterxem
		glColor3f(1, 0, 0); // kolor tak samo ; kolory interpolated  //REd=1, Gren-0, Blue=0
		glVertex2f(-0.5, -0.5); // x, y
		glColor3f(0, 1, 0); //green
		glVertex2f(0.5, -0.5); // x, y
		glColor3f(0, 0, 1); // blue
		glVertex2f(0.0, 0.5); // x, y
	glEnd(); //bez tego sie porzyga albo cos dziwnego zrobi

	glutSwapBuffers(); //wysyła wszystko na okno co może być wyrenderowane
}

