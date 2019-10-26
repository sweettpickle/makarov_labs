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

//int x1 = 0;
//int x2 = 0;
//int y1 = 0;
//int y2 = 0;

int side = 0;
int len_b = 0;
int len_w = 0;
//int mas_black[50][2];
//int mas_white[50][2];


void create_line();
void create_point(int mas[50][2], int flag, int count);
void Display(void);
void Reshape(GLint w, GLint h);
void Keyboard(unsigned char key);

#endif //LABA1_LIBRARY_H
