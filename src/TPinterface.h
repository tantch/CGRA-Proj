#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"
#include "LightingScene.h"

class TPinterface: public CGFinterface {
	LightingScene* lght;
	public:
		TPinterface(LightingScene* lght);

		virtual void initGUI();
		virtual void processGUI(GLUI_Control *ctrl);

		virtual void processKeyboard(unsigned char key, int x, int y);

		int testVar;
};


#endif
