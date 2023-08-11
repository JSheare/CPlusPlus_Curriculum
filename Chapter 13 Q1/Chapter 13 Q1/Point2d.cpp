#include "Point2d.h"

#include <iostream>
#include <cmath>

Point2d::Point2d(double x, double y)
	: m_x{ x }, m_y{ y }
{
}

void Point2d::print() const
{
	std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

double Point2d::distanceTo(const Point2d& p) const
{
	return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}