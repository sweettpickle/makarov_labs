#include <stdio.h>
//for win or linux
//#include <GL/glew.h>
//#include <GL/glut.h>

//for mac
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <stdlib.h>

int solve(int mas_b[100][2], int mas_w[100][2], int m, int n);

//void display(int mas_b[100][2], int mas_w[100][2], int m, int n)
//{
//
//}

void input(int m, int n)
{
    int mas_black[100][2];
    int mas_white[100][2];
    int i;

    i = 0;
    if (m > 100 || n > 100)
        return;
    while (i < m)
    {
        printf("Input %d black point: ", i + 1);
        scanf("%d%d", &mas_black[i][0], &mas_black[i][1]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        printf("Input %d white point: ", i + 1);
        scanf("%d%d", &mas_white[i][0], &mas_white[i][1]);
        i++;
    }
    if (solve(mas_black, mas_white, m, n))
    	printf("line is here!");
    else
    {
    	printf("not found line:(");
        return ;
    }
}

int search_d(const int *par1, const int *par2, const int *par3)
{
	int a;
	int b;

	a = (par3[0] - par1[0]) * (par2[1] - par1[1]);
	b = (par3[1] - par1[1]) * (par2[0] - par1[0]);
	return (a - b);
}

int on_one_side(const int *mas, int m)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < m)
	{
		if (mas[i] <= 0)
			c++;
		i++;
	}
	if (c == m)
		return (-1);
	i = 0;
	c = 0;
	while (i < m)
	{
		if (mas[i] >= 0)
			c++;
		i++;
	}
	if (c == m)
		return (1);
	return (0);
}

int one_color(const int *par1, const int *par2, int mas_w[100][2], int n, int side1)
{
	int i;
	int mas[n];
	int side2;

	i = 0;
	while (i < n)
	{
		mas[i] = search_d(par1, par2, mas_w[i]);
		i++;
	}
	side2 = on_one_side(mas, n);
	if (side2 != 0 && side2 != side1)
		return (1);
	return (0);
}

int solve(int mas_b[100][2], int mas_w[100][2], int m, int n)
{
	int mas[m];
	int i;
	int j;
	int z;
	int side;

	i = 0;
	while (i < m - 1)
	{
		j = i + 1;
		while (j < m)
		{
			z = 0;
			while (z < m)
			{
				mas[z] = search_d(mas_b[i], mas_b[j], mas_b[z]);
				z++;
			}
			side = on_one_side(mas, m);
			if (side == 1 || side == -1)
			{
				if (one_color(mas_b[i], mas_b[j], mas_w, n, side))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}




GLint Width = 550, Height = 550;

//void Display()
//{
//    glClearColor(0, 255, 0, 1); // цвет окна
//    glClear(GL_COLOR_BUFFER_BIT); //очистка буфера цвета и буфера глубины
//    glLineWidth(1); // ширина линий кооринатных осей
//    glColor3f(255, 0, 0); // цвет координатных осей (черный)
//    glBegin(GL_LINES); // ось ОХ, ось OY
////    glVertex2f(-10, 0);
//    glVertex2f(10, 0);
//    glVertex2f(0, 10);
////    glVertex2f(0, -10);
//    glEnd();
//}


const int CubeSize = 200;

/* эта функция управляет всем выводом на экран */
void Display(void)
{
	glClearColor(1, 1, 1, 1); // цвет окна
	glClear(GL_COLOR_BUFFER_BIT); //очистка буфера цвета и буфера глубины

	glLineWidth(3); // ширина линий кооринатных осей
    glColor3f(255, 0, 0); // цвет координатных осей (черный)

    glBegin(GL_LINES); // ось ОХ, ось OY
	glVertex2f(50, 50);
    glVertex2f(50, 450);
	glVertex2f(50, 50);
	glVertex2f(450, 50);
	glEnd();

	glLineWidth(3);
	glColor3ub(0,255,0);
	glBegin(GL_POINTS);
	glVertex2d(150, 150);
	glVertex2d(150, 150);

//	GLfloat BlueCol[3] = {0,0,1};
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1.0, 0.0, 0.0);   /* красный */
//	glVertex3f(0.0, 0.0, 0.0);
//	glColor3ub(0,255,0);    /* зеленый */
//	glVertex3f(1.0, 0.0, 0.0);
//	glColor3fv(BlueCol);    /* синий */
//	glVertex3f(1.0, 1.0, 0.0);

	glEnd();

	glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;

	/* устанавливаем размеры области отображения */
	glViewport(0, 0, w, h);

	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

	if( key == ESCAPE )
		exit(0);
}


int main(int argc, char **argv) {
//    int m;
//    int n;
//
//    printf("Number of black point: \n");
//    scanf("%d", &m);
//    printf("Number of white point: \n");
//    scanf("%d", &n);
//    if (m < 2 || n < 2)
//        return 0;
//    input(m, n);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Graphic:");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();

	return 0;
}