#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw(double x, double y);

private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

