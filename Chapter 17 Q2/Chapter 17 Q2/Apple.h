#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"

class Apple : public Fruit
{
public:
	Apple(std::string_view color = "red");

	Apple(std::string_view name, std::string_view color);
};

#endif