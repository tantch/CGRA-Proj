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
	float amb[3] = { 0.8, 0.8, 0.8 };
	float dif[3] = { 0.2, 0.2, 0.2 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 120.f;
	text = 0;
	vel[0] = 0;
	vel[1] = 0;
	vel[2] = 0;

	appearance1 = new CGFappearance(amb, dif, spec, shininess);
	appearance1->setTexture("pyramid.jpg");
	appearance1->setTextureWrap(GL_CLAMP, GL_CLAMP);

	appearance2 = new CGFappearance(amb, dif, spec, shininess);
	appearance2->setTexture("robot1.png");
	appearance2->setTextureWrap(GL_CLAMP, GL_CLAMP);
	cx = 7;
	cy = 4;
	cz = 7;
	rty = 90;
	stacks = st;
	slices = 12;

	calculateDrawPoints();
	calculateTexturePoints();
	cout << 1.0 / 3.0 << endl;
}
void MyRobot::applyTexture(int i) {
	text = i;
}
void MyRobot::update() {

	cx += vel[0];
	cy += vel[1];
	cz += vel[2];

	vel[0] = 0;
	vel[1] = 0;
	vel[2] = 0;

}

MyRobot::~MyRobot() {
	// TODO Auto-generated destructor stub
}
void MyRobot::addNormal(vector<Ponto> pnts) {
	Ponto normal(0, 0, 0);
	for (unsigned int i = 0; i < pnts.size(); ++i) {
		Ponto A = pnts[i];
		Ponto B = pnts[(i + 1) % pnts.size()];

		normal.x = normal.x + ((A.y - B.y) * (A.z + B.z));
		normal.y = normal.y + ((A.z - B.z) * (A.x + B.x));
		normal.z = normal.z + ((A.x - B.x) * (A.y + B.y));
	}

	double tamanho = normal.getTamanho();
	normal.x = normal.x / tamanho;
	normal.y = normal.y / tamanho;
	normal.z = normal.z / tamanho;
	glNormal3d(normal.x, normal.y, normal.z);

}
void MyRobot::setVel(float x, float y, float z) {
	vel[0] = x;
	vel[1] = y;
	vel[2] = z;

}
void MyRobot::setRotation(int rt) {
	rty = rt;
}

void MyRobot::calculateDrawPoints() {
	double alpha = -5 * PI / 4, dalpha = -PI / 6;
	double dx = 1 / 3;

	double xin, yin, delx, dely, kx, ky;

	for (int i = 0; i < 3; i++) {
		fc.push_back(vector<Ponto>());
		double x1 = cos((alpha + dalpha * (i))) * 0.25;
		double z1 = sin((alpha + dalpha * (i))) * 0.25;
		double x2 = cos((alpha + dalpha * (i + 1))) * 0.25;
		double z2 = sin((alpha + dalpha * (i + 1))) * 0.25;
		double px1 = -0.5 + (1 / 3.0) * i;
		double px2 = -0.5 + (1 / 3.0) * (i + 1);
		double pz1 = 0.5, pz2 = 0.5;
		double py = 0;
		double dkx;
		double dex1 = abs((x1 - px1) / stacks), dey = abs((1 - py) / stacks),
				dez1 = abs((z1 - pz1) / stacks);
		double dex2 = abs((x2 - px2) / stacks), dez2 = abs((z2 - pz2) / stacks);

		//base
		fc[i].push_back(Ponto(px1, py, pz1));
		fc[i].push_back(Ponto(px2, py, pz2));

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

			//meio
			fc[i].push_back(Ponto(px1, py, pz1));
			fc[i].push_back(Ponto(px2, py, pz2));

		}

		fc[i].push_back(Ponto(x1, 1, z1));
		fc[i].push_back(Ponto(x2, 1, z2));

	}

}
void MyRobot::calculateTexturePoints() {
	double tstep = 0.45 / stacks;
	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 3; i++) {
			tc.push_back(vector<Ponto>());

			double dkx;

			//base
			if (j == 0) {
				tc[j].push_back(Ponto(0 + 1 / 3.0 * i, 0, 0));
				tc[j].push_back(Ponto(0 + 1 / 3.0 * (i + 1), 0, 0));
			} else if (j == 1) {
				tc[j].push_back(Ponto(1, 0 + 1 / 3.0 * i, 0));
				tc[j].push_back(Ponto(1, 0 + 1 / 3.0 * (i + 1), 0));
			} else if (j == 2) {
				tc[j].push_back(Ponto(1 - 1 / 3.0 * i, 1, 0));
				tc[j].push_back(Ponto(1 - 1 / 3.0 * (i + 1), 1, 0));
			} else if (j == 3) {
				tc[j].push_back(Ponto(0, 1 - 1 / 3.0 * i, 0));
				tc[j].push_back(Ponto(0, 1 - 1 / 3.0 * (i + 1), 0));
			}

			for (double k = 1; k <= stacks; k++) {

				dkx = ((1.0 - k * tstep) - (0.0 + k * tstep)) / 3.0;

				//meio
				if (j == 0) {
					tc[j].push_back(
							Ponto(0 + k * tstep + dkx * i, 0 + k * tstep, 0));
					tc[j].push_back(
							Ponto(0 + k * tstep + dkx * (i + 1), 0 + k * tstep,
									0));
				} else if (j == 1) {
					tc[j].push_back(
							Ponto(1 - k * tstep, 0 + k * tstep + dkx * i, 0));
					tc[j].push_back(
							Ponto(1 - k * tstep, 0 + k * tstep + dkx * (i + 1),
									0));
				} else if (j == 2) {
					tc[j].push_back(
							Ponto(1 - k * tstep - dkx * i, 1 - k * tstep, 0));
					tc[j].push_back(
							Ponto(1 - k * tstep - dkx * (i + 1), 1 - k * tstep,
									0));
				} else if (j == 3) {
					tc[j].push_back(
							Ponto(0 + k * tstep, 1 - k * tstep - dkx * i, 0));
					tc[j].push_back(
							Ponto(0 + k * tstep, 1 - k * tstep - dkx * (i + 1),
									0));
				}

			}

		}
	}

}
void MyRobot::draw() {

	glPushMatrix();
	if (text == 0)
		appearance1->apply();
	if (text == 1)
		appearance2->apply();
	glTranslated(cx, cy, cz);
	glRotated(rty, 0, 1, 0);
	for (int k = 0; k < 4; k++) {
		glRotated(90, 0, 1, 0);

		for (int i = 0; i < 3; i++) {
			glBegin(GL_TRIANGLE_STRIP);

			for (int j = 0; j < fc[i].size(); j++) {
				glTexCoord2d(tc[k][j + i * (tc[k].size() / 3)].x,
						tc[k][j + i * (tc[k].size() / 3)].y);
				glNormal3d(fc[i][j].x, 0, fc[i][j].z);
				glVertex3d(fc[i][j].x, fc[i][j].y, fc[i][j].z);

			}
			int j = fc[i].size() - 2;
			glTexCoord2d(tc[k][j + i * (tc[k].size() / 3)].x,
					tc[k][j + i * (tc[k].size() / 3)].y);
			glNormal3d(0, 1, 0);
			glVertex3d(fc[i][j].x, fc[i][j].y, fc[i][j].z);
			j = fc[i].size() - 1;
			glTexCoord2d(tc[k][j + i * (tc[k].size() / 3)].x,
					tc[k][j + i * (tc[k].size() / 3)].y);
			glNormal3d(0, 1, 0);
			glVertex3d(fc[i][j].x, fc[i][j].y, fc[i][j].z);

			glTexCoord2d(0.5, 0.5);
			glNormal3d(0, 1, 0);
			glVertex3d(0, 1, 0);
			glEnd();
		}

	}
	glPopMatrix();
}

