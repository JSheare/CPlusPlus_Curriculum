#include "Fruit.h"

#include <iostream>

Fruit::Fruit(std::string_view name, std::string_view color)
	: m_name{ name }, m_color{ color }
{}