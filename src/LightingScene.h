#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "myTable.h"
#include "Plane.h"
#include "myClock.h"
#include "MyRobot.h"
#include "Impostor.h"
class LightingScene: public CGFscene {
public:
	void init();
	void display();
	void update(unsigned long sysTime);
	void toggleLight(int i);
	void toggleSomething();
	void applyTexture(int i);
	int sceneVar;
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	Impostor* Imp;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* materialC;
	CGFappearance* tableAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* landscapeAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	bool lght0on,lght1on,lght2on,lght3on;
	bool clockRun;
	bool wired;
	myClock* clock;
	myLamp* lamp1;
	MyRobot* robot;
	~LightingScene();
};

#endif
