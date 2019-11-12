#ifndef LAB2_LIBRARY_H
#define LAB2_LIBRARY_H

#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>

#define start 10
int max_r;

int mas_points[20][2];
int size;

void create_points();
void Display(void);
void Reshape(GLint w, GLint h);
void Keyboard(unsigned char key);

#endif
