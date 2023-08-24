#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);

	virtual ~Shape() = default;
};

#endif
