#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x = 0, int y = 0);

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

#endif
