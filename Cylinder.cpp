#include "Shape.h"

void drawCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks) {
	// Render a solid cylinder
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(1.2f, 1.5f, -12.0f); // Move right and into the screen
	glRotatef(angleCylinder, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis [NEW]
	glEnable(GL_TEXTURE_2D);

	GLUquadricObj* quadric = gluNewQuadric();

	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluCylinder(quadric, base, top, height, slices, stacks);
	// draw the top disk
	gluDisk(quadric, 0.0, top, slices, stacks);
	// draw the bottom disk
	glTranslatef(0.0f, 0.0f, height);
	gluDisk(quadric, 0.0, base, slices, stacks);

	gluDeleteQuadric(quadric);

	glDisable(GL_TEXTURE_2D);

	angleCylinder -= 0.15f;
}