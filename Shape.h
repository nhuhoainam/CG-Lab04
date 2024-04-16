#pragma once
#include <GL/glut.h>
#include <cmath>
#include <corecrt_math_defines.h>

/* Global variables */
extern char title[];
extern GLfloat anglePyramid; // Rotational angle for pyramid
extern GLfloat angleCube; // Rotational angle for cube
extern GLfloat angleTorus; // Rotational angle for torus
extern GLfloat angleSphere; // Rotational angle for sphere
extern GLfloat angleCylinder; // Rotational angle for cylinder
extern GLfloat angleCone; // Rotational angle for cone
extern GLfloat angleHyperboloid; // Rotational angle for circular hyperboloid
extern GLfloat angleParaboloid; // Rotational angle for paraboloid
extern int refreshMills; // refresh interval in milliseconds

extern GLuint texture[1]; // Storage for one texture

bool LoadGLTextures();

void drawCube();
void drawPyramid();
void drawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint sides, GLint rings);
void drawSphere(GLdouble radius, GLint slices, GLint stacks);
void drawCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
void drawCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
void drawHyperboloid(GLdouble a, GLdouble b, GLdouble c, GLint slices, GLint stacks);
void drawParaboloid(GLdouble focal, GLdouble height, GLint slices, GLint stacks);