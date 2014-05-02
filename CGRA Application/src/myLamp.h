/*
 * myLamp.h
 *
 *  Created on: Mar 21, 2014
 *      Author: pim
 */

#ifndef MYLAMP_H_
#define MYLAMP_H_

#include "CGF/CGFobject.h"

class myLamp : public CGFobject {
	int slices;
	int stacks;
	int raio=1;
	bool smooth;
	float alturaStack;

	public:
		myLamp(int slices, int stacks, bool smooth);
		void draw();
};




#endif /* MYLAMP_H_ */
