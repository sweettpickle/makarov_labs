#include <stdio.h>
//for win or linux
//#include <GL/glew.h>
//#include <GL/glut.h>

//for mac
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <stdlib.h>

#define start 10
int m;
int n;
int mas_black[100][2];
int mas_white[100][2];

int solve(int mas_b[100][2], int mas_w[100][2]);
void create_point(int mas_b[100][2], int flag, int count);

int search_d(const int *par1, const int *par2, const int *par3)
{
	int a;
	int b;

	a = (par3[0] - par1[0]) * (par2[1] - par1[1]);
	b = (par3[1] - par1[1]) * (par2[0] - par1[0]);
	return (a - b);
}

int on_one_side(const int *mas)
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

int one_color(const int *par1, const int *par2, int mas_col[100][2], int side1)
{
	int i;
	int mas[n];
	int side2;

	i = 0;
	while (i < n)
	{
		mas[i] = search_d(par1, par2, mas_col[i]);
		i++;
	}
	side2 = on_one_side(mas);
	if (side2 != 0 && side2 != side1)
		return (1);
	return (0);
}

int solve(int mas_b[100][2], int mas_w[100][2])
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
			side = on_one_side(mas);
			if (side == 1 || side == -1)
			{
				if (one_color(mas_b[i], mas_b[j], mas_w, side))
					return (1);
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			z = 0;
			while (z < n)
			{
				mas[z] = search_d(mas_w[i], mas_w[j], mas_w[z]);
				z++;
			}
			side = on_one_side(mas);
			if (side == 1 || side == -1)
			{
				if (one_color(mas_w[i], mas_w[j], mas_b, side))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void create_point(int mas[100][2], int flag, int count)
{
	int i;

	i = 0;
	glPointSize(3);
	if (flag)
		glColor3ub(255, 0, 255);
	else
		glColor3ub(255, 255, 255);
	glBegin(GL_POINTS);
	while (i < count)
	{
		if (!mas[i][0] && mas[i][1])
			glVertex3d(mas[i][0] * 5 + start, mas[i][1] * 5, 0);
		else if (!mas[i][1] && mas[i][0])
			glVertex3d(mas[i][0] * 5, mas[i][1] * 5 + start, 0);
		else
			glVertex3d(mas[i][0] * 5 + start, mas[i][1] * 5 + start, 0);
		i++;
	}

	glEnd();
}

/* эта функция управляет всем выводом на экран */
void Display(void)
{
	glClearColor(0, 0, 0, 0); // цвет окна
	glClear(GL_COLOR_BUFFER_BIT); //очистка буфера цвета и буфера глубины

	glLineWidth(2); // ширина линий кооринатных осей

    glBegin(GL_LINES); // ось ОХ, ось OY
    	glColor3f(255, 0, 0); // цвет координатных осей (черный)
		glVertex2f(start, start);
    	glVertex2f(start, 500);
		glVertex2f(start, start);
		glVertex2f(500, start);
	glEnd();

	create_point(mas_black, 1, m);
	create_point(mas_white, 0, n);

	glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
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
	int i;

    printf("Number of black point: \n");
    scanf("%d", &m);
    printf("Number of white point: \n");
    scanf("%d", &n);
//    if (m < 2 || n < 2)
//        return 0;
	i = 0;
	if (m > 100 || n > 100)
		return (0);
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

	if (solve(mas_black, mas_white))
	{
		printf("line is here!");
	}
	printf("not found line:(");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1000,300);
	glutInitWindowSize(550, 550);
	glutCreateWindow("Graphic:");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);

	glutMainLoop(); //Контроль всех событий и вызов нужных функций происходит внутри бесконечного цикла в этой функции
	return 0;
}