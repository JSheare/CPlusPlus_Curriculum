#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

#include <iostream>

class Banana : Fruit
{
public:

	Banana(std::string_view name, std::string_view color);

	friend std::ostream& operator<<(std::ostream& out, const Banana& banana);
};
#endif
