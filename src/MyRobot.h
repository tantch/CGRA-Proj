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
	int cx,cy,cz,rty;
	int stacks,slices;
	double basexC[12]={0.5,1/3.0,0.5/3.0,0,-0.5/3.0,-1/3.0,-0.5,-1/3.0,-0.5/3.0,0,0.5/3.0,1/3.0};
	double baseyC[12]={0,0.5/3.0,1/3.0,0.5,1/3.0,0.5/3.0,0,-0.5/3.0,-1/3.0,-0.5,-1/3.0,-0.5/3.0};
	double topxC[12];
	double topyC[12];
public:
	void setCoord();
	MyRobot(int st);
	void draw();
	virtual ~MyRobot();
	void setPosition(int x,int y,int z);
	void setRotation(int rt);
	int getRTy(){
		return rty;
	}
	int getX(){
		return cx;
	}
	int getY(){
			return cy;
		}
	int getZ(){
			return cz;
		}

};

#endif /* MYROBOT_H_ */
