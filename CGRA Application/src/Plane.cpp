#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}


void Plane::draw(double xOffset, double yOffset) {
	glRotatef(180.0, 1, 0, 0);
		glTranslatef(-0.5, 0.0, -0.5);
		glScalef(1.0 / (double) _numDivisions, 1, 1.0 / (double) _numDivisions);
		glNormal3f(0, -1, 0);

		for (int bx = 0; bx < _numDivisions; bx++) {
			glBegin(GL_TRIANGLE_STRIP);

			glTexCoord2d(1.0 * bx / _numDivisions - xOffset / 2, -yOffset / 2);
			glVertex3f(bx, 0, 0);

			for (int bz = 0; bz < _numDivisions; bz++) {
				glTexCoord2d(
						(1.0 + xOffset) * (bx + 1) / _numDivisions - xOffset / 2,
						(1.0 + yOffset) * bz / _numDivisions - yOffset / 2);
				glVertex3f(bx + 1, 0, bz);

				glTexCoord2d((1.0 + xOffset) * bx / _numDivisions - xOffset / 2,
						(1.0 + yOffset) * (bz + 1) / _numDivisions - yOffset / 2);
				glVertex3f(bx, 0, bz + 1);
			}

			glTexCoord2d((1.0 + xOffset) * (bx + 1) / _numDivisions - xOffset / 2,
					1.0 + yOffset - yOffset / 2);
			glVertex3d(bx + 1, 0, _numDivisions);

			glEnd();
		}
}
