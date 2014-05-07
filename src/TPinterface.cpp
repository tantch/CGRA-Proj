#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface(LightingScene* lght) {
	testVar = 0;
	this->lght = lght;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch (key) {
	case 'a': {
		// This is an example of accessing the associated scene
		// To test, create the function toggleSomething in your scene to activate/deactivate something
		((LightingScene *) scene)->toggleSomething();
		break;
	}
	case 'j': {
		int tp1 = lght->robot->getRTy();
		tp1 += 90;
		if (tp1 > 360)
			tp1 = tp1 - 360;
		lght->robot->setRotation(tp1);
		break;
	}
	case 'l': {
		int tp2 = lght->robot->getRTy();
		tp2 -= 90;
		if (tp2 < 0)
			tp2 = tp2 + 360;
		lght->robot->setRotation(tp2);
		break;
	}
	}
}

void TPinterface::initGUI() {
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel = addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2,
			&(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl) {
	printf("GUI control id: %d\n  ", ctrl->user_id);
	switch (ctrl->user_id) {
	case 1: {
		printf("New Val 1(interface): %d\n", testVar);
		break;
	}
		;

	case 2: {
		printf("New Val 2(scene): %d\n", ((LightingScene*) scene)->sceneVar);
		break;
	}
		;
	};
}

