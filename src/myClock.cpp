/*
 * myClock.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: pim
 */
#include "myClock.h"


myClock::myClock() {
	s=0;
	pntrHoras = new myClockHand(0.4);
	pntrHoras->setAngle(0);

	pntrMinutos = new myClockHand(0.6);
	pntrMinutos->setAngle(30);

	pntrSegundos = new myClockHand(0.7);
	pntrSegundos ->setAngle(60);

	base = new myCylinder(40, 1, true);
	float ambB[3] = { 0.2, 0.2, 0.2 };
	float difB[3] = { 0.6, 0.6, 0.6 };
	float specB[3] = { 0.2, 0.2, 0.2 };
	float shininessB = 120.f;
	clockAppearance = new CGFappearance(ambB, difB, specB, shininessB);
	clockAppearance->setTexture("clock.png");
	clockAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

}
void myClock::update(unsigned long sysTime) {

	if (sysTime / 1000 != s) {
		s = sysTime / 1000;
		pntrSegundos->incAngle(360 / 60);

		if ((int) (pntrSegundos->getAngle()) % 360 == 0) {
			pntrMinutos->incAngle(360 / 60);

			if ((int) (pntrMinutos->getAngle()) % 360 == 0)
				pntrHoras->incAngle(360 / 12);
		}
	}
}

void myClock::draw() {

	glPushMatrix();

	clockAppearance->apply();
	base->draw();

	glTranslated(0, 0, 1);
	 pntrHoras->draw();
	 pntrSegundos->draw();
	 pntrMinutos->draw();

	glPopMatrix();

}
myClock::~myClock() {
	delete (base);
	delete (pntrHoras);
	delete (pntrSegundos);
	delete (pntrMinutos);

	delete (clockAppearance);
}


