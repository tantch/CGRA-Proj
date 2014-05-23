/*
 * MyRobot.h
 *
 *  Created on: May 2, 2014
 *      Author: pim
 */

#ifndef MYROBOT_H_
#define MYROBOT_H_
#include "CGFobject.h"
#include "CGFappearance.h"
#include "Ponto.h"
#include <vector>
class MyRobot: public CGFobject {
	float cx, cy, cz;
	int rty,text;
	int stacks, slices;
	vector <vector <Ponto> > fc,tc;
	CGFappearance* appearance1,*appearance2;
	float vel[3];

public:
	void setCoord();
	MyRobot(int st);
	void draw();
	virtual ~MyRobot();
	void setVel(float x, float y, float z);
	void setRotation(int rt);
	void calculateDrawPoints();
	void calculateTexturePoints();
	void applyTexture(int i);
	void update();
	void addNormal(vector<Ponto> pnts);
	int getRTy() {
		return rty;
	}
	float getX() {
		return cx;
	}
	float getY() {
		return cy;
	}
	float getZ() {
		return cz;
	}

};

#endif /* MYROBOT_H_ */
