/*
 * myClock.h
 *
 *  Created on: Apr 23, 2014
 *      Author: pim
 */

#ifndef MYCLOCK_H_
#define MYCLOCK_H_
#include "myCylinder.h"
#include "myClockHand.h"
#include "CGFappearance.h"
class myClock : public CGFobject{

	myCylinder* base;
	CGFappearance* clockAppearance;
	myClockHand* pntrSegundos;
	myClockHand* pntrMinutos;
	myClockHand* pntrHoras;
	unsigned long s;


	public:
		myClock();
		~myClock();
		void update(unsigned long sysTime);
		void draw();
};




#endif /* MYCLOCK_H_ */
