#ifndef APPLE_H
#define APPLE_H

#include <iostream>
#include <string>

#include "Fruit.h"

class Apple : Fruit
{
private:
	double m_fiber{};

public:
	Apple(std::string_view name, std::string_view color, double fiber);

	const double getFiber() const { return m_fiber; }

	friend std::ostream& operator<<(std::ostream& out, const Apple& apple);
};

#endif