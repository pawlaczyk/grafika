#include <windows.h> 
#include <math.h> //cs i inne rzeczy do matmy swiatla

#include "freeglut.h"


const float Pi = 3.1415926535897932384626433832795;

// ----------------------- swiatlo - najtrudniejsze


//--------------Deklaracja i warto�ci inicjuj�ce dla �wiate� i materia�u ---------

	//globalna energia ambient   
GLfloat scene_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

//specyfikacja materia�u

GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };//reakcja na energi� ambient


//wspolrzedne obserwatora

GLdouble eyex = 0.0;
GLdouble eyey = 1.0;
GLdouble eyez = 1.0;


void walls() {
	//Ściany - koloy komplementarne Monochromatic Color ladnie wspolgraja
	//sufit  RGB 	najjasniejszy rgb(244,241,235)
	glColor3f(0.95, 0.94, 0.92);
	glVertex3f(-1.0, 1.0, 1.0); //przod lewo
	glVertex3f(-1.0, 1.0, -1.0); //tyl lewp
	glVertex3f(1.0, 1.0, -1.0); //tyl prawo
	glVertex3f(1.0, 1.0, 1.0); //przod prawo

	//dół ciemny brąz 	181, 157, 121
	//PODŁOGA 
	glColor3f(0.70, 0.61, 0.4745); //kolor
	glVertex3f(-1.0, 0.0, -1.0); //góra lewa
	glVertex3f(1.0, 0.0, -1.0);  //góra prawo 
	glVertex3f(1.0, 0.0, 1.0); //dol prawo
	glVertex3f(-1.0, 0.0, 1.0); // dol lewo 

	// boczna srodek
	glColor3f(0.92, 0.89, 0.85);
	glVertex3f(-1.0, 0.0, 1.0); //lewa dół
	glVertex3f(-1.0, 0.0, -1.0); //prawa doł
	glVertex3f(-1.0, 1.0, -1.0); // gora prawa
	glVertex3f(-1.0, 1.0, 1.0); // gora lewa

	//Tylna środek troszke ciemneijsza niz te boczne
	glColor3f(0.89, 0.85, 0.78);
	glVertex3f(1.0, 0, -1.0);//dol prawo
	glVertex3f(1.0, 1.0, -1.0); //gora prawo
	glVertex3f(-1.0, 1.0, -1.0);//gora lewo
	glVertex3f(-1.0, 0, -1.0); //dol lewo


	//boczna srodeek
	glColor3f(0.92, 0.89, 0.85);
	glVertex3f(1.0, 1.0, -1.0); //gora lewa
	glVertex3f(1.0, 1.0, 1.0); //gora prawo
	glVertex3f(1.0, 0.0, 1.0); // dol prawo
	glVertex3f(1.0, 0.0, -1.0); //dol lewa
}


void table_left_back_leg(GLfloat baseForTable, GLfloat down) {
	// ------------------------ lewa tylna noga ------------------------
	//nogi są o podstawie kwadratu
	//noga lewa tył
	GLfloat base = baseForTable; //grubośc nogi
	GLfloat y = 0.375; //wysokość nogi

	//podstawa/doł nogi - KWADRAT
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25); //tyl lewo - punkt róg stołu
	glVertex3f(-0.5 + base, down, -0.25); //tyl prawo
	glVertex3f(-0.5 + base, down, -0.25 + base); // przod prawo
	glVertex3f(-0.5, down, -0.25 + base); //przod lewa

	//TYLNA ściany nogi z jest stałe -0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25); //dół nogi lewo
	glVertex3f(-0.5 + base, down, -0.25); // dół nogi prawo
	glVertex3f(-0.5 + base, y, -0.25); // góra nogi  prawo
	glVertex3f(-0.5, y, -0.25); //góra nogi lewo

	//lewa boczna ściana nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, -0.25); //dół ściany lewo tył
	glVertex3f(-0.5, down, -0.25 + base); // dół nogi lewo  przod
	glVertex3f(-0.5, y, -0.25 + base); // góra nogi lewo przod
	glVertex3f(-0.5, y, -0.25); //góra nogi lewo tył

	//prawa boczna ściana nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5 + base, down, -0.25); //dół ściany prawo tył
	glVertex3f(-0.5 + base, down, -0.25 + base); // dół prawo  przod
	glVertex3f(-0.5 + base, y, -0.25 + base); // góra nogi prawo przod
	glVertex3f(-0.5 + base, y, -0.25); //góra nogi lewo tył
}


void table_right_back_leg(GLfloat baseForTable, GLfloat down) {
	// ------------------------ PRAWA TYLNA noga ------------------------
	//nogi są o podstawie kwadratu
	//noga lewa tył
	GLfloat base = baseForTable; //grubośc nogi
	GLfloat y = 0.375; //wysokość nogi

	//podstawa/doł nogi - KWADRAT
	// --------------- PODSTAWA
	// ------------------------ PRAWA tylna noga
	//podstawa/doł nogi
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, -0.25); //tyl lewo 
	glVertex3f(0.5, down, -0.25); //tyl prawo - punkt stołu
	glVertex3f(0.5, down, -0.25 + base); // przod prawo
	glVertex3f(0.5 - base, down, -0.25 + base); //przod lewa

	//TYLNA ściany nogi z jest stałe -0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, down, -0.25); //prawa dół - punk stolu
	glVertex3f(0.5, y, -0.25); //prawa góra = punk stołu + y 
	glVertex3f(0.5 - base, y, -0.25); //lewa góra - do środka stołu
	glVertex3f(0.5 - base, down, -0.25); //lewa dolna - do środka stołu

	//PRZEDNIA ściany nogi z jest stałe -0.25 + BASE
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, down, -0.25 + base); //prawa dół 
	glVertex3f(0.5, y, -0.25 + base); //prawa góra
	glVertex3f(0.5 - base, y, -0.25 + base); //lewa góra - do środka stołu
	glVertex3f(0.5 - base, down, -0.25 + base); //lewa dolna - do środka stołu

	//BOCZNA PRAWA ściana nogi x jest stałe - punkt stołu 0.5
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, down, -0.25); //prawa dół tył - punkt stołu 
	glVertex3f(0.5, y, -0.25); //prawa tylna  góra - punkt stołu
	glVertex3f(0.5, y, -0.25 + base); //lewa góra przód - do przodu stołu
	glVertex3f(0.5, down, -0.25 + base); //lewa dolna przód - do przodu stołu

	//BOCZNA LEWA ściana nogi x jest stałe - punkt stołu 0.5 - base bo do środka stołu
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, -0.25); //lewa dół tył -do środka stołu
	glVertex3f(0.5 - base, y, -0.25); //lewa tylna  góra - punkt stołu
	glVertex3f(0.5 - base, y, -0.25 + base); //lewa góra przód - do przodu stołu
	glVertex3f(0.5 - base, down, -0.25 + base); //lewa dolna przód - do przodu stołu
}


void table_left_front_leg(GLfloat baseForTable, GLfloat down) {
	//LEWA PRZEDNIA noga

	//podstawa - kwadrat
	GLfloat base = baseForTable; //grubośc nogi
	GLfloat y = 0.375; //wysokość nogi

	// ------------------------ LEWA PRZEDNIA noga
	//podstawa/doł nogi - KWADRAT
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, 0.25 - base); //tyl lewo
	glVertex3f(-0.5 + base, down, 0.25 - base); //tyl prawo 
	glVertex3f(-0.5 + base, down, 0.25); // przod prawo  
	glVertex3f(-0.5, down, 0.25); //przod lewa - punkt róg stołu

	//tylna sciana
	//z jest stałe 0.25 - base
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, 0.25 - base); //dol lewo
	glVertex3f(-0.5 + base, down, 0.25 - base); //dol prawo
	glVertex3f(-0.5 + base, y, 0.25 - base); // gora prawo 
	glVertex3f(-0.5, y, 0.25 - base); //gora lewo

	//przednia sciana
	//z jest stałe 0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, 0.25); //dol lewo
	glVertex3f(-0.5 + base, down, 0.25); //dol prawo
	glVertex3f(-0.5 + base, y, 0.25); // gora prawo 
	glVertex3f(-0.5, y, 0.25); //gora lewo

	//boczna lewa sciana
	// x stale = -0.5
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, down, 0.25); //przod dol lewo  - punkt stolu
	glVertex3f(-0.5, down, 0.25 - base); //tyl dol lewo
	glVertex3f(-0.5, y, 0.25 - base); // gora tyl 
	glVertex3f(-0.5, y, 0.25); //przod gora

	//boczna prawa sciana
	//stale x  -0.5 + base - do środka stołu
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5 + base, down, 0.25); //przod dol prawo  - do środka stłu
	glVertex3f(-0.5 + base, down, 0.25 - base); //tyl dol prawo
	glVertex3f(-0.5 + base, y, 0.25 - base); // gora tyl 
	glVertex3f(-0.5 + base, y, 0.25); //przod gora
}


void table_right_front_leg(GLfloat baseForTable, GLfloat down) {
	// ------------------------ PRAWA PRZEDNIA noga

	//podstawa - kwadrat
	GLfloat base = baseForTable; //grubośc nogi
	GLfloat y = 0.375; //wysokość nogi

	//podstawa/doł nogi - kwadrat
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, 0.25 - base); //tyl lewo
	glVertex3f(0.5, down, 0.25 - base); //tyl prawo 
	glVertex3f(0.5, down, 0.25); // przod prawo  - punkt róg stołu
	glVertex3f(0.5 - base, down, 0.25); //przod lewa

	//tylna ściana
	//stałe z = 0.25 - base
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, 0.25 - base); //dół lewo do środka stołu
	glVertex3f(0.5, down, 0.25 - base); //dół prawo 
	glVertex3f(0.5, y, 0.25 - base); // prawo góra
	glVertex3f(0.5 - base, y, 0.25 - base); //góra lewa do środka stołu

	//przednia ściana
	//stałe z = 0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, 0.25); //dół lewo do środka stołu
	glVertex3f(0.5, down, 0.25); //dół prawo - punkt stołu
	glVertex3f(0.5, y, 0.25); // prawo góra - punkt stołu góra
	glVertex3f(0.5 - base, y, 0.25); //góra lewa do środka stołu

	//boczna  lewa ściana
	//stałe x = 0.5 -base do środka stołu
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 - base, down, 0.25); //dół przod
	glVertex3f(0.5 - base, down, 0.25 - base); //dół tyl
	glVertex3f(0.5 - base, y, 0.25 - base); // tyl góra 
	glVertex3f(0.5 - base, y, 0.25); //góra pzod

	//boczna prawa ściana
	//stałe x = 0.5 
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, down, 0.25); //dół przod - punkt stołu
	glVertex3f(0.5, down, 0.25 - base); //dół tyl
	glVertex3f(0.5, y, 0.25 - base); // tyl góra 
	glVertex3f(0.5, y, 0.25); //góra przod - punt stołu
}

void table_top(GLfloat thicknessForTable, GLfloat down) {
	//blat stołu
	//dół blatu
	//blat - taka ława do kafki

	GLfloat y = 0.375; //wysokość nogi
	GLfloat thickness = thicknessForTable; //grubośc blatu


	//doł blatu
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, y, -0.25); //tyl lewo
	glVertex3f(0.5, y, -0.25); //tyl prawo
	glVertex3f(0.5, y, 0.25); // dol prawo
	glVertex3f(-0.5, y, 0.25); //dol lewa

	//góra blatu
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, y + thickness, -0.25); //tyl lewo
	glVertex3f(0.5, y + thickness, -0.25); //tyl prawo
	glVertex3f(0.5, y + thickness, 0.25); // dol prawo
	glVertex3f(-0.5, y + thickness, 0.25); //dol lewa

	//front blatu
	//stałe z = 0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, y, 0.25); //dół lewo
	glVertex3f(0.5, y, 0.25); //dół prawo
	glVertex3f(0.5, y + thickness, 0.25); // góra prawo
	glVertex3f(-0.5, y + thickness, 0.25); //góra lewo 

	//tył blatu
	//stałe z = -0.25
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, y, -0.25); //dół lewo
	glVertex3f(0.5, y, -0.25); //dół prawo
	glVertex3f(0.5, y + thickness, -0.25); // góra prawo
	glVertex3f(-0.5, y + thickness, -0.25); //góra lewo 

	//lewy bok blatu
	// x stałe = -0.5
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, y, 0.25); //dół przod
	glVertex3f(0.5, y, -0.25); //doł tył
	glVertex3f(0.5, y + thickness, -0.25); // góra tyl
	glVertex3f(0.5, y + thickness, 0.25); //góra przód 
}



// ------------------------------------- KRZESŁA -------------------------------------
void chair_left_back_leg(GLfloat shift_z, GLfloat base_chair, GLfloat leg_height, GLfloat thickness, GLfloat down) {
	GLfloat base_leg = thickness / 4; //noga ma grubośc dwóch desek

	//tylna ściana lewej nogi
	// jest stałe z tyłu (-1)*base_chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, (-1) * base_chair + shift_z); //lewa dół punk krzesła
	glVertex3f((-1) * base_chair + base_leg, down, (-1) * base_chair + shift_z); //prawa dół do środka
	glVertex3f((-1) * base_chair + base_leg, leg_height, (-1) * base_chair + shift_z); //prawa góra do środka
	glVertex3f((-1) * base_chair, leg_height, (-1) * base_chair + shift_z); //lewa góra

	//przednia ściana lewej nogi
	// jest stałe z tyłu (-1)*base_chair + grubość nogi
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, (-1) * base_chair + base_leg + shift_z); //lewa dół punk krzesła
	glVertex3f((-1) * base_chair + base_leg, down, (-1) * base_chair + base_leg + shift_z); //prawa dół do środka
	glVertex3f((-1) * base_chair + base_leg, leg_height, (-1) * base_chair + base_leg + shift_z); //prawa góra do środka
	glVertex3f((-1) * base_chair, leg_height, (-1) * base_chair + base_leg + shift_z); //lewa góra

	//lewa ściana lewej nogi
	// x stałe = - base chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, (-1) * base_chair + base_leg + shift_z); //lprzód dół ZZZZZ do mnie
	glVertex3f((-1) * base_chair, down, (-1) * base_chair + shift_z); //tył dół 
	glVertex3f((-1) * base_chair, leg_height, (-1) * base_chair + shift_z); //tył  góra
	glVertex3f((-1) * base_chair, leg_height, (-1) * base_chair + base_leg + shift_z); //przód góra z do mnie

	//PRAWA ściana lewej nogi
	// x stałe =  - base_chair + +grubos nogi
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair + base_leg, down, (-1) * base_chair + base_leg + shift_z); //przód dół ZZZZZ do mnie
	glVertex3f((-1) * base_chair + base_leg, down, (-1) * base_chair + shift_z); //tył dół 
	glVertex3f((-1) * base_chair + base_leg, leg_height, (-1) * base_chair + shift_z); //tył  góra
	glVertex3f((-1) * base_chair + base_leg, leg_height, (-1) * base_chair + base_leg + shift_z); //przód góra z do mnie
}


void chair_right_back_leg(GLfloat shift_z, GLfloat base_chair, GLfloat leg_height, GLfloat thickness, GLfloat down) {

	// ----------PRAWA NOGA
	GLfloat base_leg = thickness / 4; //noga ma grubośc dwóch desek

	//tylna ściana PRAWEJ nogi
	// jest stałe z tyłu (-1)*base_chair

	// base_chair dodatnie, grubośc nogi odjać
	// Z jest stałe na równi z siedizskiem krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, (-1) * base_chair + shift_z); //prawa dół punk krzesła
	glVertex3f(base_chair - base_leg, down, (-1) * base_chair + shift_z); //lewa dół do środka
	glVertex3f(base_chair - base_leg, leg_height, (-1) * base_chair + shift_z); //lewa góra do środka
	glVertex3f(base_chair, leg_height, (-1) * base_chair + shift_z); //prawa góra

	//Przednia sciana PRAWEJ nOGI
	//z jest stałe wsuniete do środka krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, (-1) * base_chair + base_leg + shift_z); //prawa dół punk krzesła
	glVertex3f(base_chair - base_leg, down, (-1) * base_chair + base_leg + shift_z); //lewa dół do środka
	glVertex3f(base_chair - base_leg, leg_height, (-1) * base_chair + base_leg + shift_z); //lewa góra do środka
	glVertex3f(base_chair, leg_height, (-1) * base_chair + base_leg + shift_z); //prawa góra


	//lewa boczna ściana - do środka
	// X jest stałe base_chair - base_leg do środka ściana
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair - base_leg, down, (-1) * base_chair + base_leg + shift_z); // przód dół
	glVertex3f(base_chair - base_leg, down, (-1) * base_chair + shift_z); //tył dół
	glVertex3f(base_chair - base_leg, leg_height, (-1) * base_chair + shift_z); //tył góra do
	glVertex3f(base_chair - base_leg, leg_height, (-1) * base_chair + base_leg + shift_z); //przód góra

	//prawa boczna ściana razek z krzesłem
	// X jest stałe base_chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, (-1) * base_chair + base_leg + shift_z); // przód dół
	glVertex3f(base_chair, down, (-1) * base_chair + shift_z); //tył dół
	glVertex3f(base_chair, leg_height, (-1) * base_chair + shift_z); //tył góra do
	glVertex3f(base_chair, leg_height, (-1) * base_chair + base_leg + shift_z); //przód góra
}


void chair_left_front_leg(GLfloat shift_z, GLfloat base_chair, GLfloat leg_height, GLfloat thickness, GLfloat down) {
	// ----------- LEWA PRZEDNIA NOGA - z do mnie dodatnie
	GLfloat base_leg = thickness / 4; //noga ma grubośc dwóch desek

	//tylna ściana lewej nogi - ta na równi z krzesłem
	// jest stałe z przdou base_chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, base_chair + shift_z); //lewa dół punk krzesła
	glVertex3f((-1) * base_chair + base_leg, down, base_chair + shift_z); //prawa dół do środka
	glVertex3f((-1) * base_chair + base_leg, leg_height, base_chair + shift_z); //prawa góra do środka
	glVertex3f((-1) * base_chair, leg_height, base_chair + shift_z); //lewa góra



	//Z jest dodatnie u mnie więc tutaj odejmuje  bazę nogi
	//przednia ściana lewej nogi z musi wejsc do środka - odejmowanie base leg
	// jest stałe z tyłu (-1)*base_chair + grubość nogi
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, base_chair - base_leg + shift_z); //lewa dół punk krzesła
	glVertex3f((-1) * base_chair + base_leg, down, base_chair - base_leg + shift_z); //prawa dół do środka
	glVertex3f((-1) * base_chair + base_leg, leg_height, base_chair - base_leg + shift_z); //prawa góra do środka
	glVertex3f((-1) * base_chair, leg_height, base_chair - base_leg + shift_z); //lewa góra

	//lewa ściana lewej nogi
	// x stałe = - base chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, down, base_chair - base_leg + shift_z); //lprzód dół ZZZZZ do mnie
	glVertex3f((-1) * base_chair, down, base_chair + shift_z); //tył dół 
	glVertex3f((-1) * base_chair, leg_height, base_chair + shift_z); //tył  góra
	glVertex3f((-1) * base_chair, leg_height, base_chair - base_leg + shift_z); //przód góra z do mnie

	//PRAWA ściana lewej nogi
	// x stałe =  - base_chair + +grubos nogi
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair + base_leg, down, base_chair - base_leg + shift_z); //przód dół ZZZZZ do mnie
	glVertex3f((-1) * base_chair + base_leg, down, base_chair + shift_z); //tył dół 
	glVertex3f((-1) * base_chair + base_leg, leg_height, base_chair + shift_z); //tył  góra
	glVertex3f((-1) * base_chair + base_leg, leg_height, base_chair - base_leg + shift_z); //przód góra z do mnie
}

void chair_right_front_leg(GLfloat shift_z, GLfloat base_chair, GLfloat leg_height, GLfloat thickness, GLfloat down) {
	// ----------PRAWA NOGA PRZÓD
	GLfloat base_leg = thickness / 4; //noga ma grubośc dwóch desek

	// Z z przodu

	// base_chair dodatnie, grubośc nogi odjać
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, base_chair + shift_z); //lewa dół punk krzesła
	glVertex3f(base_chair - base_leg, down, base_chair + shift_z); //prawa dół do środka
	glVertex3f(base_chair - base_leg, leg_height, base_chair + shift_z); //prawa góra do środka
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //lewa góra

	//Przednia sciana PRAWEJ nOGI
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, base_chair + shift_z); //lewa dół punk krzesła
	glVertex3f(base_chair - base_leg, down, base_chair + shift_z); //prawa dół do środka
	glVertex3f(base_chair - base_leg, leg_height, base_chair + shift_z); //prawa góra do środka
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //lewa góra


	//lewa boczna ściana - do środka
	// X jest stałe base_chair - base_leg do środka ściana
	//Z jest dodatnie u mnie więc tutaj odejmuje  bazę nogi
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair - base_leg, down, base_chair - base_leg + shift_z); // przód dół
	glVertex3f(base_chair - base_leg, down, base_chair + shift_z); //tył dół
	glVertex3f(base_chair - base_leg, leg_height, base_chair + shift_z); //tył góra do
	glVertex3f(base_chair - base_leg, leg_height, base_chair - base_leg + shift_z); //przód góra

	//prawa boczna ściana - do środka
	// X jest stałe base_chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, down, base_chair - base_leg + shift_z); // przód dół
	glVertex3f(base_chair, down, base_chair + shift_z); //tył dół
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //tył góra do
	glVertex3f(base_chair, leg_height, base_chair - base_leg + shift_z); //przód góra
}

void chair_back(GLfloat shift_z, GLfloat base_chair, GLfloat leg_height, GLfloat chairThickness, GLfloat down) {
	GLfloat chair_back_height = 0.75 * leg_height; //oparcie na 3/4 wysokości nóg
	GLfloat thickness = chairThickness / 4;
	//podstawa oparcia prostokąt
	//oparcia grubosci deski jak siedzisko
	//z do mnie do przodu
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //lewo dół - punk krzesła
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //prawo doł prawo
	glVertex3f(base_chair, leg_height + thickness, base_chair - thickness + shift_z); //tył prawo 
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair - thickness + shift_z); //tył lewo

	//góra oparcia protoskąt
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //lewo dół - punk krzesła
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //prawo doł prawo
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //tył prawo 
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //tył lewo

	//tylna ściana oparcia - ta na zewnątrz krzesła
	//tutaj bliżej mnie
	// z jest stałe z tyłem krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //lewo dół - punk krzesła
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //prawo doł prawo - punkt krzesła
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //góra prawo 
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //góra lewo

	//tylna przednia oparcia - tado środka krzesła
	//tutaj dalej mnie przesuenieta o grubosc deski oparcia
	// z jest stałe z tyłem krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair - thickness + shift_z); //lewo dół - punk krzesła
	glVertex3f(base_chair, leg_height + thickness, base_chair - thickness + shift_z); //prawo doł prawo - punkt krzesła
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //góra prawo 
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //góra lewo


	//lewa ściana oparcia o grubości deski
	//x jest stałe i równe lewemu brzegowi krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //dół przód - punk krzesła
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair - thickness + shift_z); //tył doł prawo
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //tył góra  
	glVertex3f((-1) * base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //przód góra

	//prawa ściana oparcia o grubości deski
	//x jest stałe i równe prawemu brzegowi krzesła
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //dół przód - punk krzesła
	glVertex3f(base_chair, leg_height + thickness, base_chair - thickness + shift_z); //tył doł prawo
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair - thickness + shift_z); //tył góra  
	glVertex3f(base_chair, leg_height + thickness + chair_back_height, base_chair + shift_z); //przód góra
}

void chair_front_top(GLfloat base_chair, GLfloat thickness, GLfloat leg_height, GLfloat shift_z, GLfloat down) {
	// FrONTOWE KRZESŁO SIEDZISKO BLAT

	//rysuję jakby miał byc na srodku
	// blat siedziska kwadrat
	//blat siedziska dół
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height, -base_chair + shift_z); //tył lewo
	glVertex3f(base_chair, leg_height, -base_chair + shift_z); //tył prawo
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //przód prawo 
	glVertex3f((-1) * base_chair, leg_height, base_chair + shift_z); //przód lewo

	//blat siedziska góra
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height + thickness, -base_chair + shift_z); //tył lewo
	glVertex3f(base_chair, leg_height + thickness, -base_chair + shift_z); //tył prawo
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //przód prawo
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //przód lewo

	//tył blatu z jest z tyły
	//z do tyłu const -base_chair + przesunieciie do przodu
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height, -base_chair + shift_z); //dół lewo z do tyłu
	glVertex3f(base_chair, leg_height, -base_chair + shift_z); //dół prawo z do tyłu
	glVertex3f(base_chair, leg_height + thickness, -base_chair + shift_z); //góra prawo z do tyłu
	glVertex3f((-1) * base_chair, leg_height + thickness, -base_chair + shift_z); //góra lewo z do tyłu

	//przód blatu z jest z przodu
	//z do tyłu const -base_chair + przesunieciie do przodu
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height, base_chair + shift_z); //dół lewo z do tyłu
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //dół prawo z do tyłu
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //góra prawo z do tyłu
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //góra lewo z do tyłu

	//blat z lewa boczna ściana x stałe = - base chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f((-1) * base_chair, leg_height, base_chair + shift_z); //przód dół z do przodu
	glVertex3f((-1) * base_chair, leg_height, (-1) * base_chair + shift_z); //tył dół z do tyłu
	glVertex3f((-1) * base_chair, leg_height + thickness, (-1) * base_chair + shift_z); //tył góra z do tyłu
	glVertex3f((-1) * base_chair, leg_height + thickness, base_chair + shift_z); //przód góra lewo z dO przodu

	//blat z prawy boczna ściana x stałe =  + base chair
	glColor3f(0.0, 1.0, 0.0); //rGb
	glVertex3f(base_chair, leg_height, base_chair + shift_z); //przód dół z do przodu
	glVertex3f(base_chair, leg_height, (-1) * base_chair + shift_z); //tył dół z do tyłu
	glVertex3f(base_chair, leg_height + thickness, (-1) * base_chair + shift_z); //tył góra z do tyłu
	glVertex3f(base_chair, leg_height + thickness, base_chair + shift_z); //przód góra lewo z dO przodu

}


void chair_front(GLfloat down) {
	GLfloat base_chair = 0.0625; //baza dla krzesła - połowa bazy długości siedziska
	GLfloat base_chair_2 = 2 * base_chair; //baza dla krzesła - połowa bazy długości siedziska


	GLfloat thickness = 0.1; // grubosc deski krzesła
	GLfloat leg_height = 0.2625; //wysokość nogi krzesła - 0.7 razy wysokosc stołu

	//wektor przesunięcia
	//x bez zmian
	//y bez zmian
	// z idzie do mnie o kawałek stołu i połowę wielkość siedziska krzesła
	GLfloat shift_z = 0.5 + base_chair;

	//siedziko
	chair_front_top(base_chair, thickness, leg_height, shift_z, down);

	//chair_front_top(base_chair, thickness, leg_height, shift_z);
	// ------------- nogi
	chair_left_back_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_right_back_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_left_front_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_right_front_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_back(shift_z, base_chair, leg_height, thickness, down);
}

void chair_back(GLfloat down) {
	GLfloat base_chair = 0.0625; //baza dla krzesła - połowa bazy długości siedziska
	GLfloat base_chair_2 = 2 * base_chair; //baza dla krzesła - połowa bazy długości siedziska

	GLfloat thickness = 0.1; // grubosc deski krzesła
	GLfloat leg_height = 0.2625; //wysokość nogi krzesła - 0.7 razy wysokosc stołu

	//wektor przesunięcia
	//x bez zmian
	//y bez zmian
	// z idzie do mnie o kawałek stołu i połowę wielkość siedziska krzesła
	GLfloat shift_z = (-1) * (0.5 + base_chair); // 0.5 + base_chair;

	//siedziko
	chair_front_top(base_chair, thickness, leg_height, shift_z, down);

	//chair_front_top(base_chair, thickness, leg_height, shift_z);
	// ------------- nogi
	chair_left_back_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_right_back_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_left_front_leg(shift_z, base_chair, leg_height, thickness, down);
	chair_right_front_leg(shift_z, base_chair, leg_height, thickness, down);

	//przesuniecie wektora z dla oparcia krzesła kóte jest w głębi
	GLfloat chair_back_z = shift_z - (base_chair * 2) + (thickness/4);
	chair_back(chair_back_z, base_chair, leg_height, thickness, down);
}

void table(GLfloat down) {
	GLfloat baseForTable = 0.05;
	table_top(baseForTable, down);
	table_left_back_leg(baseForTable, down);
	table_right_back_leg(baseForTable, down);
	table_left_front_leg(baseForTable, down);
	table_right_front_leg(baseForTable, down);
}

//funkcja pomocnicza rysuj�ca przybli�enie wielok�towe powierzchni kuli

void kula(int m, int n, GLfloat r, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat sx, GLfloat sy, GLfloat sz)
//m (n) jest ilosci� segment�w na r�wnole�niku (po�owie po�udnika), r promieniem kuli 
{

	int i, j;
	GLdouble alpha, beta, r0, r1, z0, z1, x00, x01, x10, x11, y00, y01, y10, y11;

	alpha = 0.5 * Pi / float(n);
	beta = 2 * Pi / float(m);
	r0 = r;
	z0 = 0;

	glPushMatrix();
	glTranslated(tx, ty, tz);
	glScaled(sx, sy, sz);

	for (j = 0; j < n - 1; j++)
	{
		r1 = r * cos(float((j + 1)) * alpha);
		z1 = r * sin(float((j + 1)) * alpha);
		x01 = r1; y01 = 0;
		x00 = r0; y00 = 0;
		for (i = 1; i <= m; i++)
		{
			x11 = r1 * cos(float(i) * beta); y11 = r1 * sin(float(i) * beta);
			x10 = r0 * cos(float(i) * beta); y10 = r0 * sin(float(i) * beta);
			glBegin(GL_POLYGON);
			//	glColor3f(1,0,0);
			glNormal3f(x00, y00, z0);
			glVertex3d(x00, y00, z0);
			glNormal3f(x10, y10, z0);
			glVertex3d(x10, y10, z0);
			glNormal3f(x11, y11, z1);
			glVertex3d(x11, y11, z1);
			glNormal3f(x01, y01, z1);
			glVertex3d(x01, y01, z1);
			glEnd();
			glBegin(GL_POLYGON);
			//	glColor3f(0,0,1);
			glNormal3f(x00, y00, -z0);
			glVertex3d(x00, y00, -z0);
			glNormal3f(x01, y01, -z1);
			glVertex3d(x01, y01, -z1);
			glNormal3f(x11, y11, -z1);
			glVertex3d(x11, y11, -z1);
			glNormal3f(x10, y10, -z0);
			glVertex3d(x10, y10, -z0);
			glEnd();
			x01 = x11; y01 = y11;
			x00 = x10; y00 = y10;
		}// end for i
		r0 = r1;
		z0 = z1;

	}//end for j

	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0, 0, r);
	glVertex3f(0, 0, r);
	for (i = 0; i <= m; i++)
	{
		x10 = r1 * cos(float(i) * beta); y10 = r1 * sin(float(i) * beta);
		glNormal3f(x10, y10, z1);
		glVertex3f(x10, y10, z1);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0, 0, -r);
	glVertex3f(0, 0, -r);
	for (i = m; i >= 0; i--)
	{
		x10 = r1 * cos(float(i) * beta); y10 = r1 * sin(float(i) * beta);
		glNormal3f(x10, y10, -z1);
		glVertex3f(x10, y10, -z1);
	}
	glEnd();

	glPopMatrix();

}//end kula()


void swiatelko(void)//globalne �wiat�o ambient
{
	scene_ambient[0] = 1.0;
	scene_ambient[1] = 1.0;
	scene_ambient[2] = 1.0;

	mat_ambient[0] = 0.5;
	mat_ambient[1] = 0.5;
	mat_ambient[2] = 0.5;

	glEnable(GL_LIGHTING);//w��czenie mechanizmu o�wietlenia

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, scene_ambient);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	glLoadIdentity();

	gluLookAt(190.0, 200.0, 130.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	kula(200, 200, 70, 0, 0, 0, 1, 1, 1);

	mat_ambient[1] = 0.0; //wcze�niejsza warto�c =1.0
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	kula(100, 100, 70, 150, 0, 0, 1, 1, 1);

	glFlush();
	glutSwapBuffers();
}

//-----------glowna funkcja 
void display()
{
	GLfloat down = 0.0000000000000000000000000000000000000000000014;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//"czyszczenie" t�a okan i bufora g��bokosci
	glEnable(GL_DEPTH_TEST);//w��cznie algorytmu zas�aniania
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 10.0); //bry�a widzenia perspektywicznego


	gluLookAt(eyex, eyey, eyez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//obserwator 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);

	walls();
	// ---stoł
	table(down);
	//--------------- krzesła masywne mega wygodne jak w pracy w kuchni
	
	chair_front(down);
	chair_back(down);

	swiatelko();

	glEnd();

	glFlush();
}


//odrysowywanie okna renderingu

void Redisplay(int width, int height)
{
	// obszar renderingu - ca�e okno
	glViewport(0, 0, width, height);

	// generowanie sceny 3D
	display();
}


//ruch obserwatora do przodu, do ty�u
void Klawiatura(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		eyez -= 0.1;
	else
		// klawisz -
		if (key == '-')
			eyez += 0.1;
	// odrysowanie okna
	Redisplay(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}


//ruch obserwatora w poziomie i w pionie
void Strzalki(int key, int x, int y)
{
	switch (key)
	{
		// scena w lewo
	case GLUT_KEY_LEFT:
		eyex += 0.1;
		break;
		// scena w g�r�
	case GLUT_KEY_UP:
		eyey -= 0.1;
		break;
		// scena w prawo
	case GLUT_KEY_RIGHT:
		eyex -= 0.1;
		break;
		// scena w d�
	case GLUT_KEY_DOWN:
		eyey += 0.1;
		break;
	}
	// odrysowanie okna
	Redisplay(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}


void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("projekt poprawione proporcje swiatlo jest ble");
	glutDisplayFunc(display);

	// obsluga klawiatury
	glutKeyboardFunc(Klawiatura);

	// obsluga strzalek
	glutSpecialFunc(Strzalki);
	///init();
	glutMainLoop();
}