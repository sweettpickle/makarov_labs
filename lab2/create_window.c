#include "library.h"

void create_points()
{
    int i;

    i = 0;
    glPointSize(3);
    glColor3ub(255, 255, 255);
    glBegin(GL_POINTS);
    while (i < size)
    {
        if (!mas_points[i][0] && mas_points[i][1])
            glVertex3d(mas_points[i][0] + start, mas_points[i][1], 0);
        else if (!mas_points[i][1] && mas_points[i][0])
            glVertex3d(mas_points[i][0], mas_points[i][1] + start, 0);
        else
            glVertex3d(mas_points[i][0] + start, mas_points[i][1] + start, 0);
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
    glVertex2f(start, 400);
    glVertex2f(start, start);
    glVertex2f(400, start);
    glEnd();
    
    create_points();

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