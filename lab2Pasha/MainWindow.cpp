#include "mll.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <chrono>
int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int f = 1;
	std::vector<mll::pointi> points{ {431, 495}, { 467, 456 }, { 362, 370 }, { 574, 366 }, { 490, 456 }, { 450, 488 }, { 311, 352 },{500, 370} };
	bool flag = true;
	RECT rectWorkWindow;
	createRect(rectWorkWindow, 100, 100, 600, 500);
	setBlackWindow(rectWorkWindow);
	for (auto & it : points)
	{
		it.print();
	}
	std::map<double, mll::pointi> radLenghts;
	double lenght = 10000;
	mll::vectori vec;
	mll::pointi centerCircle;
	int arr;
	std::cin >> arr;
	for (int source = 0; source < points.size(); source++)
	{
		for (int otherPoints = 0; otherPoints < points.size(); otherPoints++)
		{
			if (source == otherPoints)
				continue;
			vec = mll::vectori(points[source], points[otherPoints]);
			auto deb = vec.getModule();
			if (lenght > vec.getModule())
			{
				lenght = vec.getModule();
			}
		}
		radLenghts.insert(std::make_pair(lenght, points[source]));
		lenght = 10000;
	}
	double radiusCircle = radLenghts.rbegin()->first / 2;


	int checkLine = (int)radiusCircle;
	int redLine = (int)radiusCircle * 2;
	RECT shortRect(rectWorkWindow);
	subRect(shortRect, checkLine);
	while (flag)
	{
		
		drawRect(rectWorkWindow, redLine, red);
		drawRect(shortRect, white);
		for (auto & it : points)
		{
			drawCircle(radiusCircle, it, red);
			it.print();
		}
		flag = findBlackPixel(shortRect, centerCircle);
			radiusCircle += 1;
		redLine += 2;
		subRect(shortRect, 1);
	}
		radiusCircle -= 2;
	drawRect(rectWorkWindow, redLine, black);
	drawRect(rectWorkWindow, f, blue);
	drawCircle(radiusCircle, centerCircle, black);
	for (auto & it : points)
	{
		it.print();
	}

	end = std::chrono::system_clock::now();
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds> (end - start).count();
	std::cout << elapsed_seconds << std::endl;
	int a;
	std::cin >> a;
	return 0;
}