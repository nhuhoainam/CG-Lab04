#include "Shape.h"

void drawSphere(GLdouble radius, GLint slices, GLint stacks) {
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-1.5f, 2.0f, -12.0f); // Move left and into the screen
	glRotatef(angleSphere, 1.0f, 1.0f, 1.0f); // Rotate about the (1,1,1)-axis
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Draw the sphere
	GLUquadricObj* quadric = gluNewQuadric();

	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluSphere(quadric, radius, slices, stacks);

	gluDeleteQuadric(quadric);

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	angleSphere += 0.25f;
}