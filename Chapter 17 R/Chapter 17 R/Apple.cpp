#include "Apple.h"

#include <iostream>
#include <string>

Apple::Apple(std::string_view name, std::string_view color, double fiber)
	: Fruit(name, color), m_fiber{fiber}
{}

std::ostream& operator<<(std::ostream& out, const Apple& apple)
{
	out << "Apple(" << apple.getName() << ", "
		<< apple.getColor() << ", "
		<< apple.getFiber() << ')';

	return out;
}