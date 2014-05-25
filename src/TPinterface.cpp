#include "TPinterface.h"
#include "LightingScene.h"
#include <math.h>
#include <cmath>
TPinterface::TPinterface(LightingScene* lght) {
	testVar = 0;
	this->lght = lght;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	CGFinterface::processKeyboard(key, x, y);

	switch (key) {
	case ' ': {
		float vy = 0.54;
		if(!lght->robot->isJumping())
		lght->robot->setVel(0, vy, 0, true);



		break;
	}
	case 'l': {
		int tp1 = lght->robot->getRTy();
		tp1 -= 10;
		if (tp1 > 360)
			tp1 = tp1 + 360;
		lght->robot->setRotation(tp1);
		break;
	}
	case 'j': {
		int tp2 = lght->robot->getRTy();
		tp2 += 10;
		if (tp2 < 0)
			tp2 = tp2 - 360;
		lght->robot->setRotation(tp2);
		break;
	}
	case 'i': {

		float vz = 0.37 * cos((M_PI / 180) * (lght->robot->getRTy() + 90));
		float vx = 0.37 * sin((M_PI / 180) * (lght->robot->getRTy() + 90));
		lght->robot->setVel(vx, 0, vz, false);
		break;
	}
	case 'k': {

		float vz = -0.2 * cos((M_PI / 180) * (lght->robot->getRTy() + 90));
		float vx = -0.2 * sin((M_PI / 180) * (lght->robot->getRTy() + 90));
		lght->robot->setVel(vx, 0, vz, false);
		break;
	}

	}
}

void TPinterface::initGUI() {

	GLUI_Panel *painel = addPanel("Luz", 1);

	addCheckboxToPanel(painel, "luz 0", &light1, 1);
	addCheckboxToPanel(painel, "luz 1", &light2, 2);
	addCheckboxToPanel(painel, "luz 2", &light3, 3);
	addCheckboxToPanel(painel, "luz 3", &light4, 4);
	addColumn();
	GLUI_Panel *RobotPanel = addPanel("Robot", 2);
	GLUI_Listbox *textures = addListboxToPanel(RobotPanel, "Texture", &texture,
			5);
	textures->add_item(0, "normal");
	textures->add_item(1, "Metal");
	GLUI_RadioGroup *texMode = addRadioGroupToPanel(RobotPanel, &robot, 6);

	addRadioButtonToGroup(texMode, "Wireframe");
	addRadioButtonToGroup(texMode, "Textured");

	addColumn();
	addSeparator();
	addButton("Stop/Restart clock", 7);

}

void TPinterface::processGUI(GLUI_Control *ctrl) {

	switch (ctrl->user_id) {

	case 1:
		lght->toggleLight(0);
		break;
	case 2:
		lght->toggleLight(1);
		break;
	case 3:
		lght->toggleLight(2);
		break;
	case 4:
		lght->toggleLight(3);
		break;
	case 5:
		if (texture == 0) {
			lght->applyTexture(0);
		} else if (texture == 1) {
			lght->applyTexture(1);
		}

		break;
	case 6:
		if (lght->wired)
			lght->wired = false;
		else
			lght->wired = true;
		break;
	case 7:
		if (lght->clockRun)
			lght->clockRun = false;
		else
			lght->clockRun = true;
		break;

	};
}

