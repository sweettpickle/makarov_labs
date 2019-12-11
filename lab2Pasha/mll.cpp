#include "mll.h"

using namespace std;

mll::mll()
{
}
mll::~mll()
{
}
////////////////////////////////////////////////////// POINT //////////////////////////////////////////////////////////////////

void mll::pointi::setCood(char typeCoord, int val)
{
	std::string message = "Invalid type coord - ";
	if (typeCoord == 'x')
	{
		m_x = val;
	}
	else if (typeCoord == 'y')
	{
		m_y = val;
	}
	else
	{
		message = message + typeCoord;
		MessageBox(nullptr, message.c_str(), "mll::vectori::getCoord", MB_OK);
	}

}
int mll::pointi::getCoord(char typeCoord)
{
	std::string message = "Invalid type coord - ";
	if (typeCoord == 'x')
	{
		return m_x;
	}
	else if (typeCoord == 'y')
	{
		return m_y;
	}
	else
	{
		message = message + typeCoord;
		MessageBox(nullptr, message.c_str(), "mll::vectori::getCoord", MB_OK);
		return 65536;
	}
}

void mll::pointi::print()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	SetPixel(mydc, m_x, m_y, green);
}
////////////////////////////////////////////////// VECTOR //////////////////////////////////////////////////////////////////////////////////////

mll::vectori::vectori(pointi source, pointi dir_point)
{
	m_x = dir_point.getCoord('x') - source.getCoord('x');
	m_y = dir_point.getCoord('y') - source.getCoord('y');
}

double mll::vectori::getModule()
{
	return  sqrt((m_x * m_x) + (m_y * m_y));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const double PI = 3.141592653589793238462643383;

void drawCircle(double lenght, mll::pointi center, COLORREF insideColor)
{
	double rad = lenght;
	HWND handle = GetConsoleWindow();
	HDC dc = GetDC(handle);
	HBRUSH hBrush = CreateSolidBrush(insideColor); //������ ������-�����
	SelectObject(dc, hBrush);

	HPEN hPen = CreatePen(0, 1, red); //�������� ������ //����������� �����
	SelectObject(dc, hPen); //������ �������� �������

	Ellipse(dc, center.getCoord('x') - rad , center.getCoord('y') - rad, center.getCoord('x') + rad, center.getCoord('y') + rad);
}

void drawRect(RECT & RectWorkWindow, int & borders, const COLORREF & colorRef)
{
	/*
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC dc = GetDC(myconsole);
	

	RectWorkWindow.left += borders;
	RectWorkWindow.top += borders;
	RectWorkWindow.right -= borders;
	RectWorkWindow.bottom -= borders;

	// ���������� ������
		MoveToEx(dc, RectWorkWindow.left, RectWorkWindow.bottom, NULL);
		LineTo(dc, RectWorkWindow.right,  RectWorkWindow.bottom);
		LineTo(dc, RectWorkWindow.right, RectWorkWindow.top);
		LineTo(dc, RectWorkWindow.left, RectWorkWindow.top);
		LineTo(dc, RectWorkWindow.left, RectWorkWindow.bottom);
		MoveToEx(dc, 0, 0, NULL);
	*/
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);
	HBRUSH hBrush = CreateSolidBrush(black); //������ ������-�����
	SelectObject(dc, hBrush);
	HPEN hPen = CreatePen(0, borders, colorRef); //�������� ������ //����������� �����
	SelectObject(dc, hPen); //������ �������� �������
	Rectangle(dc, RectWorkWindow.left, RectWorkWindow.top, RectWorkWindow.right, RectWorkWindow.bottom);

}

void setBlackWindow(RECT & RectWorkWindow)
{
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);
	HBRUSH hBrush = CreateSolidBrush(black); //������ ������-�����
	SelectObject(dc, hBrush);
	Rectangle(dc, RectWorkWindow.left, RectWorkWindow.top, RectWorkWindow.right, RectWorkWindow.bottom);
}

void createRect(RECT & RectWorkWindow, long left, long top, long right, long bottom)
{
	RectWorkWindow.left = left;
	RectWorkWindow.right = right;
	RectWorkWindow.bottom = bottom;
	RectWorkWindow.top = top;
}

void drawRect(RECT & RectWorkWindow, const COLORREF & colorRef)
{
	
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC dc = GetDC(myconsole);
	// ���������� ������
	HBRUSH hBrush = CreateSolidBrush(black); //������ ������-�����
	SelectObject(dc, hBrush);
	HPEN hPen = CreatePen(0, 1, colorRef); //�������� ������ //����������� �����
	SelectObject(dc, hPen); //������ �������� �������
		MoveToEx(dc, RectWorkWindow.left, RectWorkWindow.bottom, NULL);
		LineTo(dc, RectWorkWindow.right,  RectWorkWindow.bottom);
		LineTo(dc, RectWorkWindow.right, RectWorkWindow.top);
		LineTo(dc, RectWorkWindow.left, RectWorkWindow.top);
		LineTo(dc, RectWorkWindow.left, RectWorkWindow.bottom);
		MoveToEx(dc, 0, 0, NULL);
	
}

// ���� ������� false, ������ ��� ������� �����
bool findBlackPixel(RECT & RectWorkWindow, mll::pointi & point)
{
	long curColor;
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);

	for (int i = RectWorkWindow.left; i < RectWorkWindow.right; i++)
	{
		for (int j = RectWorkWindow.top; j < RectWorkWindow.bottom; j++)
		{
			curColor = GetPixel(dc, i, j);
			if (curColor == black)
			{
				point.setCood('x', i);
				point.setCood('y', j);
				return true;
			}
		}
	}
	return false;
}

void subRect(RECT & rectWorkWindow, int subValue)
{


	rectWorkWindow.left += subValue;
	rectWorkWindow.top += subValue;
	rectWorkWindow.right -= subValue;
	rectWorkWindow.bottom -= subValue;
}
int mll::vectori::getCoord(char typeCoord)
{
return pointi::getCoord(typeCoord);
}