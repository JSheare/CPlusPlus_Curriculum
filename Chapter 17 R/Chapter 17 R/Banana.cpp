#include "Banana.h"

Banana::Banana(std::string_view name, std::string_view color)
	: Fruit(name, color)
{}

std::ostream& operator<<(std::ostream& out, const Banana& banana)
{
	out << "Banana(" << banana.getName() << ", "
		<< banana.getColor() << ')';

	return out;
}