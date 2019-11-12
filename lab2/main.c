#include "library.h"

void max_rad(int *par)
{

}

int solve()
{

}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    printf("Number of point: \n");
    scanf("%d", &size);

    while (i < size)
    {
        printf("Input %d point: ", i + 1);
        scanf("%d%d", &mas_points[i][0], &mas_points[i][1]);
        i++;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(500, 200);
    glutInitWindowSize(410, 410);
    glutCreateWindow("Graphic:");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc((void (*)(unsigned char, int, int)) Keyboard);
    glutMainLoop();
    return 0;
}