#include <cassert>

#include "Point.h"

Point::Point(int x, int y)
	: m_x{ x }, m_y{ y }
{}

bool operator==(Point p1, Point p2)
{
	return (p1.m_x == p2.m_x && p1.m_y == p2.m_y);
}

bool operator!=(Point p1, Point p2)
{
	return !(p1 == p2);
}

Point Point::getAdjacentPoint(Direction direction) const
{
	switch (direction.getType())
	{
	case Direction::up:		return Point(m_x,		m_y - 1); 
	case Direction::down:	return Point(m_x,		m_y + 1);
	case Direction::left:	return Point(m_x - 1,	m_y);
	case Direction::right:	return Point(m_x + 1,	m_y);
	}

	return *this;
}