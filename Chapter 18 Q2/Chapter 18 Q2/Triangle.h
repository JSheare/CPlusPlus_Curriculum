#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
private:
	Point m_point1{};
	Point m_point2{};
	Point m_point3{};
public:
	Triangle(Point point1, Point point2, Point point3);

	std::ostream& print(std::ostream& out) const override;
};

#endif