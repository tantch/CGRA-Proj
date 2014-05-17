/*
 * MyRobot.cpp
 *
 *  Created on: May 2, 2014
 *      Author: pim
 */

#include "MyRobot.h"
#include <math.h>
#include <cmath>
#include <iostream>
using namespace std;
#define PI 3.14159265
MyRobot::MyRobot(int st) {
	cx = 7;
	cy = 4;
	cz = 7;
	rty = 90;
	stacks = st;
	slices = 12;

}

MyRobot::~MyRobot() {
	// TODO Auto-generated destructor stub
}
void MyRobot::setPosition(float x, float y, float z) {
	if (x > 0)
		cx = x;
	if (y > 0)
		cy = y;
	if (z > 0)
		cz = z;

}
void MyRobot::setRotation(int rt) {
	rty = rt;
}

void MyRobot::draw() {

	double alpha = -5 * PI / 4, dalpha = -PI / 6;
	double dx = 1 / 3;

	//lados

	glPushMatrix();
	glTranslated(cx, cy, cz);
	glRotated(rty,0,1,0);
	for (int j = 0; j < 4; j++) {

		glRotated(90 * j, 0, 1, 0);
		for (int i = 0; i < 3; i++) {
			double x1 = cos((alpha + dalpha * (i))) * 0.25;
			double z1 = sin((alpha + dalpha * (i))) * 0.25;
			double x2 = cos((alpha + dalpha * (i + 1))) * 0.25;
			double z2 = sin((alpha + dalpha * (i + 1))) * 0.25;
			double px1 = -0.5 + (1 / 3.0) * i;
			double px2 = -0.5 + (1 / 3.0) * (i + 1);
			double pz1 = 0.5, pz2 = 0.5;
			double py = 0;
			double dex1 = abs((x1 - px1) / stacks), dey = abs(
					(1 - py) / stacks), dez1 = abs((z1 - pz1) / stacks);
			double dex2 = abs((x2 - px2) / stacks), dez2 = abs(
					(z2 - pz2) / stacks);
			glBegin(GL_TRIANGLE_STRIP);
			glNormal3d(px1, 0, pz1);
			glVertex3f(px1, py, pz1);
			glNormal3d(px2, 0, pz2);
			glVertex3f(px2, py, pz2);
			for (int k = 1; k < stacks; k++) {
				if (px1 < 0)
					px1 = px1 + dex1;
				else
					px1 = px1 - dex1;
				if (px2 < 0)
					px2 = px2 + dex2;
				else
					px2 = px2 - dex2;
				py = py + dey;
				pz1 = pz1 - dez1;
				pz2 = pz2 - dez2;

				glNormal3d(px1, 0, pz1);
				glVertex3f(px1, py, pz1);
				glNormal3d(px2, 0, pz2);
				glVertex3f(px2, py, pz2);

			}

			glNormal3d(x1, 0, z1);
			glVertex3f(x1, 1, z1);
			glNormal3d(x2, 0, z2);
			glVertex3f(x2, 1, z2);
			glEnd();
		}
	}

	//topo
		glNormal3d(0,1,0);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 12; i++) {
		double x1 = cos((alpha + dalpha * (i))) * 0.25;
		double z1 = sin((alpha + dalpha * (i))) * 0.25;
		double x2 = cos((alpha + dalpha * (i + 1))) * 0.25;
		double z2 = sin((alpha + dalpha * (i + 1))) * 0.25;

		glNormal3d(0,1,0);
		glVertex3f(x1, 1, z1);
		glNormal3d(0,1,0);
		glVertex3f(x2, 1, z2);

	}

	glEnd();

	glPopMatrix();
}
