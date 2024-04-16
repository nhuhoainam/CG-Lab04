#include "Shape.h"

void drawHyperboloid(GLdouble a, GLdouble b, GLdouble c, GLint slices, GLint stacks) {
	// Render a solid hyperboloid
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-0.7f, -2.0f, -12.0f); // Move right and into the screen
	glRotatef(angleHyperboloid, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis [NEW]
	glEnable(GL_TEXTURE_2D);

	// Resolution for the hyperboloid
	int vSteps = 50, thetaSteps = 50;

	// Range for the parameters
	GLdouble vMin = -1.0, vMax = 1.0;
	GLdouble thetaMin = 0.0, thetaMax = 2.0 * M_PI;
	// calculate base and top using the range of v
	GLdouble height = 2.0 * c * sinh(vMax);
	GLdouble base = a * cosh(vMin), top = a * cosh(vMax);

	glBegin(GL_QUADS);

	// draw the hyperboloid
	for (int i = 0; i < vSteps; ++i) {
		for (int j = 0; j < thetaSteps; ++j) {
			// Compute the four corners of the quad
			GLdouble v0 = vMin + i * (vMax - vMin) / vSteps;
			GLdouble v1 = vMin + (i + 1) * (vMax - vMin) / vSteps;
			GLdouble theta0 = thetaMin + j * (thetaMax - thetaMin) / thetaSteps;
			GLdouble theta1 = thetaMin + (j + 1) * (thetaMax - thetaMin) / thetaSteps;

			// Compute the coordinates of the four corners
			GLdouble x0 = a * cosh(v0) * cos(theta0), y0 = b * cosh(v0) * sin(theta0), z0 = c * sinh(v0);
			GLdouble x1 = a * cosh(v1) * cos(theta0), y1 = b * cosh(v1) * sin(theta0), z1 = c * sinh(v1);
			GLdouble x2 = a * cosh(v1) * cos(theta1), y2 = b * cosh(v1) * sin(theta1), z2 = c * sinh(v1);
			GLdouble x3 = a * cosh(v0) * cos(theta1), y3 = b * cosh(v0) * sin(theta1), z3 = c * sinh(v0);

			// Draw the quad
			glTexCoord2f((float)i / vSteps, (float)j / thetaSteps); glVertex3f(x0, y0, z0);
			glTexCoord2f((float)(i + 1) / vSteps, (float)j / thetaSteps); glVertex3f(x1, y1, z1);
			glTexCoord2f((float)(i + 1) / vSteps, (float)(j + 1) / thetaSteps); glVertex3f(x2, y2, z2);
			glTexCoord2f((float)i / vSteps, (float)(j + 1) / thetaSteps); glVertex3f(x3, y3, z3);
		}
	}
	glEnd();

	GLUquadricObj* quadric = gluNewQuadric();
	// draw the top disk
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	glTranslatef(0.0f, 0.0f, -height / 2);
	gluDisk(quadric, 0.0, top, slices, stacks);


	// draw the bottom disk
	glTranslatef(0.0f, 0.0f, height);
	gluDisk(quadric, 0.0, base, slices, stacks);
	
	gluDeleteQuadric(quadric);

	angleHyperboloid -= 0.15f;
}