#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
private:
	Point m_center{};
	int m_radius{};
public:
	Circle(Point center, int radius = 0);

	std::ostream& print(std::ostream& out) const override;

	int getRadius() const { return m_radius; }
};

#endif
