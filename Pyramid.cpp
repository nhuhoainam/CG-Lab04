#include "Shape.h"

void drawPyramid() {
	// Render a pyramid consists of 4 triangles
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-1.0f, -2.0f, -12.0f); // Move left and into the screen
	glRotatef(anglePyramid, 1.0f, 1.0f, 1.0f); // Rotate about the (1,1,1)-axis
	glEnable(GL_TEXTURE_2D);
	// glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Draw the pyramid
	glBegin(GL_TRIANGLES);

		// Front face
		glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 1.0);

		// Right face
		glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);

		// Back face
		glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);

		// Left face
		glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);

	glEnd();

	// glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	anglePyramid += 0.2f;
}