/*
 * myLamp.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: pim
 */
#include "myLamp.h"
#include <math.h>
#define PI 3.14159265
myLamp::myLamp(int slices, int stacks, bool smooth) {

	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;
	this->alturaStack = 1.0 / stacks;
}

void myLamp::draw() {

	float xa = 1, xb, za = 0, zb, xn, zn, xc, zc, xd, zd, yc, yd, ya, yb;
	float ang = 2 * PI / slices;
	float ang2 = (PI / 2.0) / stacks;
	for (float j = 0; j < stacks; j++) {

		for (int i = slices; i > 0; i--) {

			xa = raio * sin((PI / 2) - (ang2 * j)) * sin(ang * i);
			ya = raio * cos((PI / 2) - (ang2 * j));
			za = raio * sin((PI / 2) - (ang2 * j)) * cos(ang * i);

			xb = raio * sin((PI / 2) - (ang2 * j)) * sin(ang * (i - 1));
			yb = raio * cos((PI / 2) - (ang2 * j));
			zb = raio * sin((PI / 2) - (ang2 * j)) * cos(ang * (i - 1));

			xc = raio * sin((PI / 2) - (ang2 * (j + 1))) * sin(ang * i);
			yc = raio * cos((PI / 2) - (ang2 * (j + 1)));
			zc = raio * sin((PI / 2) - (ang2 * (j + 1))) * cos(ang * i);

			xd = raio * sin((PI / 2) - (ang2 * (j + 1))) * sin(ang * (i - 1));
			yd = raio * cos((PI / 2) - (ang2 * (j + 1)));
			zd = raio * sin((PI / 2) - (ang2 * (j + 1))) * cos(ang * (i - 1));

			glBegin(GL_QUADS);
			if (smooth)
				glNormal3f(xa, ya, za);
			glVertex3f(xa, ya, za);
			if (smooth)
				glNormal3f(xc, yc, zc);
			glVertex3f(xc, yc, zc);
			if (smooth)
				glNormal3f(xd, yd, zd);
			glVertex3f(xd, yd, zd);
			if (smooth)
				glNormal3f(xb, yb, zb);
			glVertex3f(xb, yb, zb);
			glEnd();

		}

	}
	glNormal3f(0, -1, 0);
	glBegin(GL_POLYGON);

	for (int i = 0; i <= slices; i++) {
		za = sin(ang * i) * raio; //raio=1
		xa = cos(ang * i) * raio;
		glVertex3f(xa, 0, za);
	}
	glEnd();

}

