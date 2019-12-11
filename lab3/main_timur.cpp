#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    HPEN pen; //Объявляется кисть
    pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    int x1, y1;
    int i, j, k;
    int l = 0;
    int x = 0;
    int y = 0;
    int cl = 0;
    float s1 = 0;
    float s2 = 0;
    float s = 0;
    bool fl = false;
    vector<vector<int>> dots;

    while (x != -1) {
        cout << "Enter coordinate X ((-1) to stop): " << endl;
        cin >> x;
        if (x != -1) {
            dots.resize(l + 1);
            dots[l].resize(3);
            cout << "Enter coordinate Y: " << endl;
            cin >> y;
            cout << "Enter point color (0 - top; 1 - bottom): " << endl;
            cin >> cl;
            dots[l][0] = x;
            dots[l][1] = y;
            dots[l][2] = cl;
            l++;
        }
        system("cls");
    }

    /*SelectObject(mydc, pen);
    MoveToEx(mydc, 49, 49, NULL);
    LineTo(mydc, 352, 49);
    LineTo(mydc, 352, 352);
    LineTo(mydc, 49, 352);
    LineTo(mydc, 49, 49);*/

    for (i = 0; i <= 500; i++)
        for (j = 0; j <= 500; j++) {
            for (k = 0; k < dots.size(); k++) {
                if (dots[k][2] == 0)	s1 = s1 + 1 / (1 + sqrt((i - dots[k][0])*(i - dots[k][0]) + (j - dots[k][1])*(j - dots[k][1])));
                if (dots[k][2] == 1)	s2 = s2 + 1 / (1 + sqrt((i - dots[k][0])*(i - dots[k][0]) + (j - dots[k][1])*(j - dots[k][1])));
            }
            s = s1 - s2;
            if (s < 0) SetPixel(mydc, i, j, RGB(65, 111, 233));
            else SetPixel(mydc, i, j, RGB(101, 67, 33));
            s = 0;
            s1 = 0;
            s2 = 0;
        }

    for (j = 0; j < dots.size(); j++) {
        x1 = dots[j][0];
        y1 = dots[j][1];
        if (dots[j][2] == 0) {
            SetPixel(mydc, x1, y1, RGB(0, 255, 0));
            SetPixel(mydc, x1, y1 - 1, RGB(0, 255, 0));
            SetPixel(mydc, x1 + 1, y1, RGB(0, 255, 0));
            SetPixel(mydc, x1, y1 + 1, RGB(0, 255, 0));
            SetPixel(mydc, x1 - 1, y1, RGB(0, 255, 0));
        }
        else {
            SetPixel(mydc, x1, y1, RGB(255, 255, 0));
            SetPixel(mydc, x1, y1 - 1, RGB(255, 255, 0));
            SetPixel(mydc, x1 + 1, y1, RGB(255, 255, 0));
            SetPixel(mydc, x1, y1 + 1, RGB(255, 255, 0));
            SetPixel(mydc, x1 - 1, y1, RGB(255, 255, 0));
        }
    }


    int z;
    cin >> z;
}