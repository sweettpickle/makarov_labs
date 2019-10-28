#ifndef LABA1_LIBRARY_H
#define LABA1_LIBRARY_H
#include <stdio.h>

//for win or linux
#include <GL/glew.h>
#include <GL/glut.h>

//for mac
//#include <OpenGL/glext.h>
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
#include <stdlib.h>

#define start 10

int x1;
int x2;
int y1;
int y2;

int len_b;
int len_w;
int mas_black[50][2];
int mas_white[50][2];


void create_line();
void create_point(int mas[50][2], int is_black, int count);
void Display(void);
void Reshape(GLint w, GLint h);
void Keyboard(unsigned char key);

#endif //LABA1_LIBRARY_H
