#pragma once
#include <array>

namespace me
{
	const int windowW = 800;
	const int windowH = 600;
	struct Point
	{
		int x, y;
		Point(int x, int y);
		Point();
	private: 
		Point(float x, float y);
	};
	void drawPoint(Point point);
	void drawLine(std::array<Point, 2> vertices);
	void drawTriangle(std::array<Point, 3> vertices);
	void drawCircle();
	void drawRectangle();
}