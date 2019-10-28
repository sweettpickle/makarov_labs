#include "library.h"

int search_const(const int *par1, const int *par2, const int *par3)
{
    int a;
    int b;

    a = (par3[0] - par1[0]) * (par2[1] - par1[1]);
    b = (par3[1] - par1[1]) * (par2[0] - par1[0]);
    return (a - b);
}

int what_side(const int *mas, int z)
{
    int i, c;

    i = 0;
    c = 0;
    while (i < z)
    {
        if (mas[i++] <= 0)
            c++;
    }
    if (c == z)
        return (0);
    i = 0;
    c = 0;
    while (i < z)
    {
        if (mas[i++] >= 0)
            c++;
    }
    if (c == z)
        return (1);
    return (-1);
}

int what_two_side(const int *mas, int z)
{
    int i, c;

    i = 0;
    c = 0;
    while (i < z)
    {
        if (mas[i++] < 0)
            c++;
    }
    if (c == z)
        return (0);
    i = 0;
    c = 0;
    while (i < z)
    {
        if (mas[i++] > 0)
            c++;
    }
    if (c == z)
        return (1);
    return (-1);
}

int different_side(const int *par1, const int *par2, int mas_points[][2], int side1, int len)
{
    int i;
    int side2;
    int mas[len];

    i = 0;
    while (i < len)
    {
        mas[i] = search_const(par1, par2, mas_points[i]);
        i++;
    }
    side2 = what_two_side(mas, len);
    if (side2 != -1 && side1 != side2)
        return (0);
    return (1);
}

int solve(int mas_b[][2], int mas_w[][2])
{
    int mas_const[50];
    int point, next_point, z;
    int side; // -1 - error, 0 - left, 1 - right

    point = 0;
    while (point < len_b - 1)
    {
        next_point = point + 1;
        while (next_point < len_b)
        {
            z = 0;
            while (z < len_b)
            {
                mas_const[z] = search_const(mas_b[point], mas_b[next_point], mas_b[z]);
                z++;
            }
            side = what_side(mas_const, len_b);
            if (len_b == 2 && !different_side(mas_b[point], mas_b[next_point], mas_w, 2, len_w))
            {
                printf("line here!");
                x1 = mas_b[point][0]; y1 = mas_b[point][1];
                x2 = mas_b[next_point][0]; y2 = mas_b[next_point][1];
                return (0);
            }
            if (side != -1 && !different_side(mas_b[point], mas_b[next_point], mas_w, side, len_w))
            {
                printf("line here!");
                x1 = mas_b[point][0]; y1 = mas_b[point][1];
                x2 = mas_b[next_point][0]; y2 = mas_b[next_point][1];
                return (0);
            }
            next_point++;
        }
        point++;
    }

    point = 0;
    while (point < len_w - 1)
    {
        next_point = point + 1;
        while (next_point < len_w)
        {
            z = 0;
            while (z < len_w)
            {
                mas_const[z] = search_const(mas_w[point], mas_w[next_point], mas_w[z]);
                z++;
            }
            side = what_side(mas_const, len_w);
            if (len_w == 2 && !different_side(mas_w[point], mas_w[next_point], mas_b, 2, len_b))
            {
                printf("line here!");
                x1 = mas_w[point][0]; y1 = mas_w[point][1];
                x2 = mas_w[next_point][0]; y2 = mas_w[next_point][1];
                return (0);
            }
            if (side != -1 && !different_side(mas_w[point], mas_w[next_point], mas_b, side, len_b))
            {
                printf("line here!");
                x1 = mas_w[point][0]; y1 = mas_w[point][1];
                x2 = mas_w[next_point][0]; y2 = mas_w[next_point][1];
                return (0);
            }
            next_point++;
        }
        point++;
    }
    return (1);
}

int main(int argc, char **argv) {
    int i;

    printf("Number of black point: \n");
    scanf("%d", &len_b);
    printf("Number of white point: \n");
    scanf("%d", &len_w);

    if (len_b < 2 || len_w < 2 || len_b > 50 || len_w > 50)
        return 0;

    i = 0;
    while (i < len_b)
    {
        printf("Input %d black point: ", i + 1);
        scanf("%d%d", &mas_black[i][0], &mas_black[i][1]);
        i++;
    }
    i = 0;
    while (i < len_w)
    {
        printf("Input %d white point: ", i + 1);
        scanf("%d%d", &mas_white[i][0], &mas_white[i][1]);
        i++;
    }

    if (solve(mas_black, mas_white))
    {
        printf("%s", "Error. Line not found.");
        return (1);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(1000, 300);
    glutInitWindowSize(550, 550);
    glutCreateWindow("Graphic:");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc((void (*)(unsigned char, int, int)) Keyboard);
    glutMainLoop(); //Контроль всех событий и вызов нужных функций происходит внутри бесконечного цикла в этой функции
        return (0);
}