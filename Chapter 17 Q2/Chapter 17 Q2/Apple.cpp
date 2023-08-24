#include "Apple.h"

Apple::Apple(std::string_view color)
	: Fruit{ "apple", color }
{}

Apple::Apple(std::string_view name, std::string_view color)
	: Fruit{ name, color }
{}