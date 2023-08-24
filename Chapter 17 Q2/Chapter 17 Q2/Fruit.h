#ifndef FRUIT_H
#define FRUIT_H

#include <string>

class Fruit
{
public:
	Fruit(std::string_view name, std::string_view color);

	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }

private:
	std::string m_name{};
	std::string m_color{};
};

#endif
