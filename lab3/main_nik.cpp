#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

#define PEAK 7
#define CAVITY 5

double height(int* X, int x_len, int* Y, int y_len, int z1, int z2) 
{
	double x1 = 0.0;
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;
	double x_sum = 0.0;
	double y_sum = 0.0;
	for (int i = 0; i < x_len; i++) 
	{
		x1 = X[i * 2 + 0];
		x2 = X[i * 2 + 1];
		
		x_sum +=                         1.0
//				-----------------------------------------------------
			   / ( 1 + sqrt(pow((z1 - x1), 2) + pow((z2 - x2), 2)) );
	}

	for (int i = 0; i < y_len; i++)
	{
		y1 = Y[i * 2 + 0];
		y2 = Y[i * 2 + 1];

		y_sum +=                       1
//				-----------------------------------------------------
			/ ( 1 + sqrt(pow((z1 - y1), 2) + pow((z2 - y2), 2)) );
	}
	return x_sum - y_sum;
}

int main()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	HPEN land_pen;
	HPEN sea_pen;
	HPEN border_pen;
	HBRUSH brush;
	land_pen = CreatePen(PS_SOLID, 1, RGB(208, 101, 8));
	sea_pen = CreatePen(PS_SOLID, 1, RGB(65, 0, 245));
	border_pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	brush = CreateHatchBrush(PS_SOLID, RGB(0, 255, 255));
	

	SelectObject(mydc, border_pen);
	MoveToEx(mydc, 49, 49, NULL);
	LineTo(mydc, 352, 49);
	LineTo(mydc, 352, 352);
	LineTo(mydc, 49, 352);
	LineTo(mydc, 49, 49);

	int X[PEAK][2] = { {100, 100}, {50, 100}, {100, 50},
					{340, 300}, {340, 310}, {340, 305},
					{330, 320} };
	int Y[CAVITY][2] = { {200, 200}, {70, 340}, {100, 200},
					{250, 170}, {300, 100} };

	height(&X[0][0], 3, &Y[0][0], 3, 1, 1);

	for (int i = 50; i < 350; i++) 
	{
		for (int j = 50; j < 350; j++) 
		{
			if (height(&X[0][0], PEAK, &Y[0][0], CAVITY, i, j) >= 0.0) 
			{
				SetPixel(mydc, i, j, RGB(208, 101, 8));
			}
			else 
			{
				SetPixel(mydc, i, j, RGB(65, 0, 245));
			}
		}
	}

	for (int i = 0; i < PEAK; i++)
	{
		SetPixel(mydc, X[i][0], X[i][1], RGB(0, 0, 0));
	}
	for (int i = 0; i < CAVITY; i++)
	{
		SetPixel(mydc, Y[i][0], Y[i][1], RGB(255, 255, 255));
	}

	int kek;
	cin >> kek;
}