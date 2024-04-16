#include "Shape.h"

void drawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint sides, GLint rings) {
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-4.5f, -2.0f, -12.0f); // Move left and into the screen
	glRotatef(angleTorus, 1.0f, 1.0f, 1.0f); // Rotate about the (1,1,1)-axis
	glEnable(GL_TEXTURE_2D);
	// glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS); // Begin drawing the torus
	for (int i = 0; i < sides; i++) {
		for (int j = 0; j < rings; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					GLfloat theta = (2.0f * M_PI * i) / sides;
					GLfloat phi = (2.0f * M_PI * j) / rings;
					GLfloat theta2 = (2.0f * M_PI * (i + 1)) / sides;
					GLfloat phi2 = (2.0f * M_PI * (j + 1)) / rings;

					GLfloat x1 = (outerRadius + innerRadius * cos(phi)) * cos(theta);
					GLfloat y1 = (outerRadius + innerRadius * cos(phi)) * sin(theta);
					GLfloat z1 = innerRadius * sin(phi);

					GLfloat x2 = (outerRadius + innerRadius * cos(phi2)) * cos(theta);
					GLfloat y2 = (outerRadius + innerRadius * cos(phi2)) * sin(theta);
					GLfloat z2 = innerRadius * sin(phi2);

					GLfloat x3 = (outerRadius + innerRadius * cos(phi2)) * cos(theta2);
					GLfloat y3 = (outerRadius + innerRadius * cos(phi2)) * sin(theta2);
					GLfloat z3 = innerRadius * sin(phi2);

					GLfloat x4 = (outerRadius + innerRadius * cos(phi)) * cos(theta2);
					GLfloat y4 = (outerRadius + innerRadius * cos(phi)) * sin(theta2);
					GLfloat z4 = innerRadius * sin(phi);

					glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, y1, z1);
					glTexCoord2f(1.0f, 0.0f); glVertex3f(x2, y2, z2);
					glTexCoord2f(1.0f, 1.0f); glVertex3f(x3, y3, z3);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(x4, y4, z4);
				}
			}
		}
	}
	glEnd(); // End of drawing the torus

	// glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	angleTorus += 0.3f;
}