#include "library.h"

void create_line()
{
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3d(1,0,0);
    if (side < 0)
    {
        printf("%d %d %d %d",x1, x2, y1, y2);
        glVertex3d(start + (x1) * 5, start + (y1 + 5) * 5, 0);
        glVertex3d(start + (x2) * 5, start + (y2 + 5) * 5, 0);
    }
    else {
        glVertex3d(start + (x1 - 5) * 5, start + (y1 - 5) * 5, 0);
        glVertex3d(start + (x2 + 5) * 5, start + (y2 - 5) * 5, 0);
    }
    glEnd();
}

void create_point(int mas[50][2], int is_black, int count)
{
    int i;

    i = 0;
    glPointSize(3);
    if (is_black)
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

    create_point(mas_black, 1, len_b);
    create_point(mas_white, 0, len_w);
    create_line();

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
void Keyboard(unsigned char key)
{
#define ESCAPE '\033'

    if( key == ESCAPE )
        exit(0);
}