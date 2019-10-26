#include "library.h"

int solve(int mas_b[][2], int mas_w[][2], int *x[][4], int *y[][4])
{

}

int main(int argc, char **argv) {
    int i;
    int *x[4];
    int *y[4];

    printf("Number of black point: \n");
    scanf("%d", &len_b);
    printf("Number of white point: \n");
    scanf("%d", &len_w);

    if (len_b < 2 || len_w < 2 || len_b > 50 || len_w > 50)
        return 0;

    int mas_black[len_b][2];
    int mas_white[len_w][2];

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
    if (solve(mas_black, mas_white, &x, &y))
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