#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"

class myCylinder : public CGFobject {
	int slices;
	int stacks;
	int raio=1;
	bool smooth;
	float alturaStack;

	public:
		myCylinder(int slices, int stacks, bool smooth);
		void draw();
};



#endif
