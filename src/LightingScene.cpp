#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = { 4, 6.0, 1.0, 1.0 };
float light1_pos[4] = { 10.5, 6.0, 1.0, 1.0 };

float light2_pos[4] = { 10.5, 6.0, 5.0, 1.0 };
float light3_pos[4] = { 4, 6.0, 5.0, 1.0 };

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = { 0.2, 0.2, 0.2, 1.0 };

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = { 0.2, 0.2, 0.2 };
float difA[3] = { 0.6, 0.6, 0.6 };
float specA[3] = { 0, 0.2, 0.2 };
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = { 0.2, 0.2, 0.2 };
float difB[3] = { 0.6, 0.6, 0.6 };
float specB[3] = { 0.2, 0.2, 0.2 };
float shininessB = 120.f;
//Coefficients for tableAppearance

float ambT[3] = { 0.2, 0.2, 0.2 };
float difT[3] = { 0.8, 0.8, 0.8 };
float specT[3] = { 0.2, 0.2, 0.2 };
float shininessT = 40.f;
//Coefficients for slidesAppearance

float ambS[3] = { 0.2, 0.2, 0.2 };
float difS[3] = { 0.8, 0.8, 0.8 };
float specS[3] = { 0.2, 0.2, 0.2 };
float shininessS = 40.f;
//Coefficients for boardAppearance
float ambBo[3] = { 0.2, 0.2, 0.2 };
float difBo[3] = { 0.2, 0.2, 0.2 };
float specBo[3] = { 0.5, 0.5, 0.5 };
float shininessBo = 120.f;

float ambientNull[4] = { 0.3, 0.3, 0.3, 1 };
float yellow[4] = { 1, 1, 0, 1 };

void LightingScene::init() {
	// Enables lighting computations
	glEnable(GL_LIGHTING);
	sceneVar = 0;
	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// Define ambient light (do not confuse with ambient component of individual lights)
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientNull);

	clockRun=true;
	wired=false;
	// Declares and enables lights, with null ambient component
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setSpecular(yellow);
	light0->setAmbient(ambientNull);
	light0->enable();
	lght0on = true;

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	light1->enable();
	lght1on = true;

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);
	light2->enable();
	lght2on = true;

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(1);
	light3->enable();
	lght3on = true;

	// Uncomment below to enable normalization of lighting normal vectors
	glEnable(GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	lamp1 = new myLamp(7, 4, true);
	clock = new myClock();
	robot = new MyRobot(40);
	Imp = new Impostor();

	//Declares materials
	materialA = new CGFappearance(ambA, difA, specA, shininessA);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);
	materialC = new CGFappearance(ambB, difB, specB, shininessB);
	tableAppearance = new CGFappearance(ambT, difT, specT, shininessT);
	tableAppearance->setTexture("table.png");
	tableAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	slidesAppearance = new CGFappearance(ambS, difS, specS, shininessS);
	slidesAppearance->setTexture("slides.png");
	slidesAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	boardAppearance = new CGFappearance(ambBo, difBo, specBo, shininessBo);
	boardAppearance->setTexture("board.png");
	boardAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	windowAppearance = new CGFappearance(ambB, difB, specB, shininessB);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	floorAppearance = new CGFappearance(ambT, difT, specT, shininessT);
	floorAppearance->setTexture("floor.png");
	landscapeAppearance = new CGFappearance(ambT, difT, specT, shininessT);
	landscapeAppearance->setTexture("Dressrosa.jpg");

	setUpdatePeriod(30);
	// defines shade model
	glShadeModel(GL_SMOOTH);

	//Declares scene elements

}
void LightingScene::update(unsigned long sysTime) {
	if (clockRun)
		clock->update(sysTime);

		robot->update();

}
void LightingScene::applyTexture(int i){
	robot->applyTexture(i);
}
void LightingScene::toggleSomething() {

}
void LightingScene::toggleLight(int i) {
	switch (i) {
	case 0:
		if (lght0on) {
			light0->disable();
			lght0on = false;
		} else {
			light0->enable();
			lght0on = true;
		}
		break;
	case 1:
		if (lght1on) {
			light1->disable();
			lght1on = false;
		} else {
			light1->enable();
			lght1on = true;
		}
		break;
	case 2:
		if (lght2on) {
			light2->disable();
			lght2on = false;
		} else {
			light2->enable();
			lght2on = true;
		}
		break;
	case 3:
		if (lght3on) {
			light3->disable();
			lght3on = false;
		} else {
			light3->enable();
			lght3on = true;
		}
		break;

	}
}
void LightingScene::display() {

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
	glTranslated(5, 0, 8);
	tableAppearance->apply();
	table->draw();
	glPopMatrix();

	//Second Table

	glPushMatrix();
	glTranslated(12, 0, 8);
	table->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
	glTranslated(7.5, 0, 7.5);
	glScaled(15, 0.2, 15);
	floorAppearance->apply();
	wall->draw(10, 10);
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	windowAppearance->apply();
	Imp->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glRotated(90.0, 1, 0, 0);
	glScaled(15, 0.2, 8);
	materialC->apply();
	wall->draw(0, 0);
	glPopMatrix();

	// Board A
	glPushMatrix();
	glTranslated(4, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	slidesAppearance->apply();
	boardA->draw(0, 0);
	glPopMatrix();

	//PlaneB
	glPushMatrix();
	glTranslated(10.5, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	boardAppearance->apply();
	boardB->draw(0, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 7, 5);
	materialC->apply();
	lamp1->draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6, 6, -0.5);
	clock->draw();
	glPopMatrix();

	//Paisagem

	glPushMatrix();
	glTranslated(-20, 4, 7.5);
	glRotated(90.0, 1, 0, 0);
	glRotated(-90.0, 0, 0, 1);
	glScaled(30, 0.2, 16);
	landscapeAppearance->apply();
	wall->draw(0, 0);
	glPopMatrix();

	if (wired)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	robot->draw();
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// ---- END Primitive drawing section

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() {
	delete (light0);
	delete (light1);
	delete (light2);
	delete (light3);

	delete (materialA);
	delete (materialB);
}
