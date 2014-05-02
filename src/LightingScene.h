#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "myTable.h"
#include "Plane.h"
#include "myClock.h"
class LightingScene: public CGFscene {
public:
	void init();
	void display();
	void update(unsigned long sysTime);
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* materialC;
	CGFappearance* tableAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;

	myClock* clock;
	myLamp* lamp1;

	~LightingScene();
};

#endif
