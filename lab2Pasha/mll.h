#pragma once
#include <map>
#include <Windows.h>
#include <string>
#include <cmath>

using namespace std;

const COLORREF white = RGB(255, 255, 255);
const COLORREF black = RGB(0, 0, 0);
const COLORREF red = RGB(255, 0, 0);
const COLORREF green = RGB(0, 255, 0);
const COLORREF blue = RGB(0, 0, 255);
const COLORREF yellow = RGB(0, 255, 255);

class mll
{
public:
	mll();
	~mll();
	class pointi
	{
	protected:
		int m_x;
		int m_y;
	public:
		pointi(): m_x(0), m_y(0) { }
		pointi(int x, int y) : m_x(x), m_y(y) {}
		void setCood(char typeCoord, int val);
		int getCoord(char typeCoord);
		void print();
        ~pointi() {};
	};

	class vectori : pointi
	{

	public:
		vectori()
		{
			m_x = 0;
			m_y = 0;
		}

		vectori(int x, int y)
		{
			m_x = x;
			m_y = y;
		}
		vectori(pointi source, pointi dir_point);

		~vectori()
        {
		}
		void setCood(char typeCoord, int val)
		{
			pointi::setCood(typeCoord, val);
		}
		int getCoord(char typeCoord);

		double getModule();
	};
};

void drawCircle(double lenght, mll::pointi center, COLORREF insideColor);
void drawRect(RECT & RectWorkWindow, int & borders, const COLORREF & colorRef);
void drawRect(RECT & RectWorkWindow, const COLORREF & colorRef);
void createRect(RECT & RectWorkWindow, long left, long bottom, long right, long top);
bool findBlackPixel(RECT & RectWorkWindow, mll::pointi & point);
void setBlackWindow(RECT & RectWorkWindow);
void subRect(RECT & RectWorkWindow, int subValue);