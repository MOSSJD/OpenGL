#include "Utils.h"
#include <GLFW/glfw3.h>
#include <cmath>

void me::drawCircle()
{

}

void me::drawRectangle()
{

}

void me::drawTriangle(std::array<me::Point, 3> vertices)
{
	for (int i = 0; i < 3; i++)
	{
		me::drawLine(std::array<me::Point, 2>{vertices.at(i), vertices.at((i + 1) % 3)});
	}
}

me::Point::Point(int x, int y) : 
	x(x),
	y(y)
{ }

me::Point::Point() : 
	Point(0, 0)
{ }

me::Point::Point(float x, float y) :
	Point((int)std::round(x), (int)std::round(y))
{ }

void me::drawPoint(Point point)
{
	glBegin(GL_POINTS);
	glVertex2f(point.x / (float)me::windowW * 2.0f - 1.0f, 
			   point.y / (float)me::windowH * 2.0f - 1.0f);
	glEnd();
}

void me::drawLine(std::array<me::Point, 2> vertices)
{
	int dx = abs(vertices.at(0).x - vertices.at(1).x);
	int dy = abs(vertices.at(0).y - vertices.at(1).y);
	bool reverse_xy = false;
	if (dy > dx)
	{
		std::swap(dy, dx);
		std::swap(vertices.at(0).x, vertices.at(0).y);
		std::swap(vertices.at(1).x, vertices.at(1).y);
		reverse_xy = true;
	}
	if (vertices.at(0).x > vertices.at(1).x)
		std::swap(vertices.at(0), vertices.at(1));
	int x = vertices.at(0).x, y = vertices.at(0).y, e = 2 * dy - dx;
	for (int i = 0; i <= dx; i++)
	{
		if (!reverse_xy)
			drawPoint(Point{x, y});
		else
			drawPoint(Point{y, x});
		if (e >= 0)
		{
			y += 1;
			e -= 2 * dx;
		}
		x += 1;
		e += 2 * dy;
	}
}