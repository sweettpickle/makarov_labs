#include "library.h"

//void max_rad(int *par)
//{
//
//}
//

int min_lenght()
{

}

int solve()
{
    int i;
    int j;
    int max_size;
    int size;

    i = 10;
    while (i < 600)
    {
        j = 10;
        while (j < 600)
        {
            max_size = j;
            size = min_lenght(i, j);
        }
    }

}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    printf("Number of point: \n");
    scanf("%d", &size);

    while (i < size)
    {
        printf("Input %d point 0-60: ", i + 1);
        scanf("%d%d", &mas_points[i][0], &mas_points[i][1]);
        i++;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(500, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Graphic:");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc((void (*)(unsigned char, int, int)) Keyboard);
    glutMainLoop();
    return 0;
}