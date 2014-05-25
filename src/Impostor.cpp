#include "Impostor.h"

Impostor::Impostor(void) {
}

Impostor::~Impostor(void) {
}

void Impostor::draw() {
	double t1 = -2.7, t2 = 0.04, t3 = 0.96, t4 = 2.7;

	glPushMatrix();
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t4, t1);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t4, t2);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t3, t2);
	glVertex3d(0, 2, 6);
	glTexCoord2d(t3, t1);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 6);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t3, t1);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t3, t2);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t2, t2);
	glVertex3d(0, 2, 3);
	glTexCoord2d(t2, t1);
	glVertex3d(0, 0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 9);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t2, t1);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t2, t2);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t1, t2);
	glVertex3d(0, 2, 6);
	glTexCoord2d(t1, t1);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 0);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t4, t2);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t4, t3);
	glVertex3d(0, 3, 0);
	glTexCoord2d(t3, t3);
	glVertex3d(0, 3, 6);
	glTexCoord2d(t3, t2);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5, 0);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t4, t3);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t4, t4);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t3, t4);
	glVertex3d(0, 2, 6);
	glTexCoord2d(t3, t3);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 9);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t2, t2);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t2, t3);
	glVertex3d(0, 3, 0);
	glTexCoord2d(t1, t3);
	glVertex3d(0, 3, 6);
	glTexCoord2d(t1, t2);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5, 6);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t3, t3);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t3, t4);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t2, t4);
	glVertex3d(0, 2, 3);
	glTexCoord2d(t2, t3);
	glVertex3d(0, 0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5, 9);
	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(t2, t3);
	glVertex3d(0, 0, 0);
	glTexCoord2d(t2, t4);
	glVertex3d(0, 2, 0);
	glTexCoord2d(t1, t4);
	glVertex3d(0, 2, 6);
	glTexCoord2d(t1, t3);
	glVertex3d(0, 0, 6);
	glEnd();
	glPopMatrix();

}
