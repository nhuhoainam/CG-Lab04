//#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <iostream>
#include "Shape.h"

char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;
GLfloat angleCube = 0.0f;
GLfloat angleTorus = 0.0f;
GLfloat angleSphere = 0.0f;
GLfloat angleCylinder = 0.0f;
GLfloat angleCone = 0.0f;
GLfloat angleHyperboloid = 0.0f;
GLfloat angleParaboloid = 0.0f;
int refreshMills = 15;
GLuint texture[1];

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f); // Set background depth to farthest
	glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL); // Set the type of depth-test
	glShadeModel(GL_SMOOTH); // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
	std::cout << LoadGLTextures(); // Load textures
}

/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix
	
	drawCube();
	// drawPyramid();
	drawTorus(0.5f, 1.0f, 50, 50);
	drawSphere(1.0f, 50, 50);
	drawCylinder(1.0, 1.0, 2.0, 32, 32);
	drawCone(1.0, 2.0, 32, 32);
	drawHyperboloid(1.0, 1.0, 1.0, 32, 32);
	drawParaboloid(0.5, 2.5, 32, 32);
	
	glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}
/* Called back when timer expired [NEW] */
void timer(int value) {
	glutPostRedisplay(); // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) { // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1; // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);
	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
	glLoadIdentity(); // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480); // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title); // Create window with the given title
	glutDisplayFunc(display); // Register callback handler for window re-paint event
	glutReshapeFunc(reshape); // Register callback handler for window re-size event
	initGL(); // Our own OpenGL initialization
	glutTimerFunc(0, timer, 0); // First timer call immediately [NEW]
	glutMainLoop(); // Enter the infinite event-processing loop
	return 0;
}
