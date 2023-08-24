#ifndef POINT_H
#define POINT_H

#include "Direction.h"

class Point
{
private:
	int m_x{};
	int m_y{};
public:
	Point(int x = 0, int y = 0);

	friend bool operator==(Point p1, Point p2);

	friend bool operator!=(Point p1, Point p2);

	Point getAdjacentPoint(Direction direction) const;

	int getX() const {return m_x;}
	int getY() const { return m_y; }
};

#endif
