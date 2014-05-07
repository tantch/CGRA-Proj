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
void MyRobot::setPosition(int x, int y, int z) {
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

void MyRobot::setCoord() {
	double a = 360.0 / slices;
	for (int i = 0; i < 12; i++) {
		topxC[i] = cos((M_PI / 180) * (a * (i))) * 0.5;
		topyC[i] = sin((M_PI / 180) * (a * (i))) * 0.5;

	}

	for (int i = 0; i < 12; i++) {
		cout << " i : " << endl;
	}

}

void MyRobot::draw() {
	double alturaStack = 1.0 / stacks;

	double x1, y1, x2, y2, z1, z2;
	setCoord();
	//base
	glBegin(GL_POLYGON);
	for (int i = 0; i < 12; i++) {
		//glVertex3d(basexC[i], baseyC[i], 0.5);
	}
	glEnd();

	//topo
	glBegin(GL_POLYGON);
	for (int i = 0; i < 12; i++) {
		glVertex3d(topxC[i], topyC[i], -0.5);
	}
	glEnd();

	// body
	x2 = -0.5;
	y2 = -0.5;
	/*double incx, incy;
	 for (int i = 0; i < slices; i++) {

	 for (int j = 0; j < stacks; j++) {
	 z1 = z2;
	 z2 = alturaStack;

	 glBegin(GL_POLYGON);

	 glVertex3d(x1, y1, z1);
	 glVertex3d(x1 - kx1 * (i + 1), y1 - ky1 * (i + 1), z2);

	 glVertex3d(x2 - kx2 * (i + 1), y2 - ky2 * (i + 1), z2);
	 glVertex3d(x2, y2, z1);

	 glEnd();
	 }
	 }*/
}
