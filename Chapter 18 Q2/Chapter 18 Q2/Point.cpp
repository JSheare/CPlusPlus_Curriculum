#include "Point.h"

Point::Point(int x, int y)
	: m_x{ x }, m_y{ y }
{}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	return out << "Point(" << point.m_x << ", " << point.m_y << ')';
}