/*
 * myClockHand.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: pim
 */

#include "myClockHand.h"
myClockHand::myClockHand(float size) {
	pointer = new myCylinder(12, 1, true);
	this->size = size;
	angle = 0;
	float amb[3] = { 0.2, 0.2, 0.2 };
	float dif[3] = { 0.1, 0.1, 0.1 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 60.f;
	pointerAppearance = new CGFappearance(amb, dif, spec, shininess);
}

void myClockHand::draw() {
	glPushMatrix();
	pointerAppearance->apply();
	glRotated(-angle, 0, 0, 1);
	glRotated(-90, 1, 0, 0);
	glScaled(0.02, 0.02, size);
	pointer->draw();
	glPopMatrix();
}

myClockHand::~myClockHand() {

}

float myClockHand::getAngle() {
	return angle;
}

void myClockHand::setAngle(float angle) {
	this->angle = angle;
}

void myClockHand::incAngle(float angle) {
	this->angle += angle;
}

