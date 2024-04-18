#include "Shape.h"

void drawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint sides, GLint rings) {
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-4.5f, -2.0f, -12.0f); // Move left and into the screen
	glRotatef(angleTorus, 1.0f, 1.0f, 1.0f); // Rotate about the (1,1,1)-axis
	glEnable(GL_TEXTURE_2D);
	// glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int uSteps = sides, vSteps = rings;

	// Radii of the torus
	GLdouble R2 = (outerRadius - innerRadius) / 2;
	GLdouble R1 = R2 + innerRadius;

	// Range for the parameters
    GLdouble uMin = 0.0, uMax = 2.0 * M_PI;
    GLdouble vMin = 0.0, vMax = 2.0 * M_PI;

    glBegin(GL_QUADS);
    // draw the torus
    for (int i = 0; i < uSteps; ++i) {
        for (int j = 0; j < vSteps; ++j) {
            // Compute the four corners of the quad
            GLdouble u0 = uMin + i * (uMax - uMin) / uSteps;
            GLdouble u1 = uMin + (i + 1) * (uMax - uMin) / uSteps;
            GLdouble v0 = vMin + j * (vMax - vMin) / vSteps;
            GLdouble v1 = vMin + (j + 1) * (vMax - vMin) / vSteps;
            // Compute the coordinates of the four corners
            GLdouble x0 = (R1 + R2 * cos(v0)) * cos(u0), y0 = (R1 + R2 * cos(v0)) * sin(u0), z0 = R2 * sin(v0);
            GLdouble x1 = (R1 + R2 * cos(v1)) * cos(u0), y1 = (R1 + R2 * cos(v1)) * sin(u0), z1 = R2 * sin(v1);
            GLdouble x2 = (R1 + R2 * cos(v1)) * cos(u1), y2 = (R1 + R2 * cos(v1)) * sin(u1), z2 = R2 * sin(v1);
            GLdouble x3 = (R1 + R2 * cos(v0)) * cos(u1), y3 = (R1 + R2 * cos(v0)) * sin(u1), z3 = R2 * sin(v0);
            // Draw the quad
            glTexCoord2f((float)i / uSteps, (float)j / vSteps); glVertex3f(x0, y0, z0);
            glTexCoord2f((float)(i + 1) / uSteps, (float)j / vSteps); glVertex3f(x1, y1, z1);
            glTexCoord2f((float)(i + 1) / uSteps, (float)(j + 1) / vSteps); glVertex3f(x2, y2, z2);
            glTexCoord2f((float)i / uSteps, (float)(j + 1) / vSteps); glVertex3f(x3, y3, z3);
        }
    }
    glEnd();

	// glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	angleTorus += 0.3f;
}