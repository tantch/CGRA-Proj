#include "myCylinder.h"
#include <math.h>
#include <cmath>
#define PI 3.14159265
myCylinder::myCylinder(int slices, int stacks, bool smooth) {

	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;
	this->alturaStack = 1.0 / stacks;
}

void myCylinder::draw() {
	double alpha = 360.0 / slices;
	double x1, y1, x2, y2, z1, z2;
	double stackHeight;

	// 1st base
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = cos((M_PI / 180) *(alpha * i));
		y1 = sin((M_PI / 180) *(alpha * i));

		glTexCoord2d(0.5 + x1 * 0.5, 0.5 + y1 * 0.5);
		glVertex3d(x1, y1, 1);
	}
	glEnd();

	// 2nd base
	glPushMatrix();
	glRotated(180.0, 1, 0, 0);
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = cos((M_PI / 180) *(alpha * i));
		y1 = sin((M_PI / 180) *(alpha * i));

		glVertex3d(x1, y1, 0);
	}
	glEnd();
	glPopMatrix();

	// body
	x2 = cos((M_PI / 180) *(0));
	y2 = sin((M_PI / 180) *(0));
	stackHeight = 1.0 / stacks;

	for (int i = 0; i < slices; i++) {
		x1 = x2;
		y1 = y2;
		x2 = cos((M_PI / 180) *(alpha * (i + 1)));
		y2 = sin((M_PI / 180) *(alpha * (i + 1)));
		z2 = 1;

		// flat shading
		if (!smooth) {
			double ax, ay;
			ax = (x1 + x2) / 2;
			ay = (y1 + y2) / 2;

			double nx, ny, nc;
			nc = sqrt(ax * ax + ay * ay);
			nx = ax / nc;
			ny = ay / nc;

			glNormal3d(nx, ny, 0);
		}

		for (int j = 0; j < stacks; j++) {
			z1 = z2;
			z2 -= stackHeight;

			glBegin(GL_QUADS);

			if (smooth)
				glNormal3d(x1, y1, 0);
			glVertex3d(x1, y1, z1);
			glVertex3d(x1, y1, z2);

			if (smooth)
				glNormal3d(x2, y2, 0);
			glVertex3d(x2, y2, z2);
			glVertex3d(x2, y2, z1);

			glEnd();
		}
	}
}
