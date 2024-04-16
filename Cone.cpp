#include "Shape.h"

void drawCone(GLdouble base, GLdouble height, GLint slices, GLint stacks) {
	// Render a solid cone
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(4.0f, 2.0f, -12.0f); // Move right and into the screen
	glRotatef(angleCone, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis [NEW]
	glEnable(GL_TEXTURE_2D);

	GLUquadricObj* quadric = gluNewQuadric();

	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluCylinder(quadric, base, 0.0, height, slices, stacks);

	gluDeleteQuadric(quadric);

	glDisable(GL_TEXTURE_2D);

	angleCone -= 0.15f;
}