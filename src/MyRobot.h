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
	CGFappearance* appearance1,*appearance2,*appearance3;
	float vel[3];
	bool jumped=false;
public:
	bool isJumping(){
		return jumped;
	}
	void setCoord();
	MyRobot(int st);
	void draw();
	virtual ~MyRobot();
	void setVel(float x, float y, float z,bool jump);
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
