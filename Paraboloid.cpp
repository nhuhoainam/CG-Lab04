#include "Shape.h"

void drawParaboloid(GLdouble focal, GLdouble height, GLint slices, GLint stacks) {
	// Render a solid paraboloid
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(4.0f, -3.5f, -15.0f); // Move right and into the screen
	glRotatef(angleParaboloid, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis [NEW]
	glEnable(GL_TEXTURE_2D);

	// Compute p
	double p = 2 * focal;

	// Resolution for the paraboloid
	int uSteps = 50, vSteps = 50;

	// Range for the parameters
	double uMin = 0.0, uMax = sqrt(height / (2 * p));
	double vMin = 0.0, vMax = 2.0 * M_PI;

	// calculate the top radius
	double top = 2 * p * uMax;

	glBegin(GL_QUADS);

	for (int i = 0; i < uSteps; ++i) {
		for (int j = 0; j < vSteps; ++j) {
			// Compute the four corners of the quad
			double u0 = uMin + i * (uMax - uMin) / uSteps;
			double u1 = uMin + (i + 1) * (uMax - uMin) / uSteps;
			double v0 = vMin + j * (vMax - vMin) / vSteps;
			double v1 = vMin + (j + 1) * (vMax - vMin) / vSteps;

			// Compute the coordinates of the four corners
			double x0 = 2 * p * u0 * cos(v0), y0 = 2 * p * u0 * sin(v0), z0 = 2 * p * u0 * u0;
			double x1 = 2 * p * u1 * cos(v0), y1 = 2 * p * u1 * sin(v0), z1 = 2 * p * u1 * u1;
			double x2 = 2 * p * u1 * cos(v1), y2 = 2 * p * u1 * sin(v1), z2 = 2 * p * u1 * u1;
			double x3 = 2 * p * u0 * cos(v1), y3 = 2 * p * u0 * sin(v1), z3 = 2 * p * u0 * u0;

			// Draw the quad with texture coordinates
			glTexCoord2f((float)i / uSteps, (float)j / vSteps); glVertex3f(x0, y0, z0);
			glTexCoord2f((float)(i + 1) / uSteps, (float)j / vSteps); glVertex3f(x1, y1, z1);
			glTexCoord2f((float)(i + 1) / uSteps, (float)(j + 1) / vSteps); glVertex3f(x2, y2, z2);
			glTexCoord2f((float)i / uSteps, (float)(j + 1) / vSteps); glVertex3f(x3, y3, z3);
		}
	}

	glEnd();

	GLUquadricObj* quadric = gluNewQuadric();

	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	glTranslatef(0.0f, 0.0f, height);
	gluDisk(quadric, 0.0, top, slices, stacks);

	gluDeleteQuadric(quadric);

	glDisable(GL_TEXTURE_2D);

	angleParaboloid -= 0.25f;
}