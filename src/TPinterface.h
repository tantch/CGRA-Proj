#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"
#include "LightingScene.h"

class TPinterface: public CGFinterface {
	LightingScene* lght;
	int light1=1;
	int light2=1;
	int light3=1;
	int light4=1;
	int robot=1;
	int texture=0;
	public:
		TPinterface(LightingScene* lght);

		virtual void initGUI();
		virtual void processGUI(GLUI_Control *ctrl);

		virtual void processKeyboard(unsigned char key, int x, int y);

		int testVar;
};


#endif
