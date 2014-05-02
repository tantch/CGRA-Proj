/*
 * myClockHand.h
 *
 *  Created on: Apr 23, 2014
 *      Author: pim
 */

#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_
#include "CGFappearance.h"
#include "myCylinder.h"

class myClockHand: public CGFobject {

	myCylinder* pointer;
	float size;
	float angle;

	CGFappearance* pointerAppearance;

public:
	myClockHand(float size);
	void draw();
	virtual ~myClockHand();

	float getAngle();
	void setAngle(float angle);
	void incAngle(float angle);

};

#endif /* MYCLOCKHAND_H_ */
