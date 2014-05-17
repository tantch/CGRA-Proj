/*
 * MyRobot.h
 *
 *  Created on: May 2, 2014
 *      Author: pim
 */

#ifndef MYROBOT_H_
#define MYROBOT_H_
#include "CGFobject.h"
class MyRobot : public CGFobject {
	float cx,cy,cz;
	int rty;
	int stacks,slices;


public:
	void setCoord();
	MyRobot(int st);
	void draw();
	virtual ~MyRobot();
	void setPosition(float x,float y,float z);
	void setRotation(int rt);
	int getRTy(){
		return rty;
	}
	float getX(){
		return cx;
	}
	float getY(){
			return cy;
		}
	float getZ(){
			return cz;
		}

};

#endif /* MYROBOT_H_ */
