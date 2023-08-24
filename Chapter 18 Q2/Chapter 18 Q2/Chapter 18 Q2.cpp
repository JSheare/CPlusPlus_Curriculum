#include <vector>
#include <iostream>

#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"

int getLargestRadius(std::vector<Shape*>& vector)
{
	int currentMax{ 0 };
	for (const Shape* shape : vector)
	{
		const Circle* tempCircle{ dynamic_cast<const Circle*>(shape) };
		if (tempCircle)
		{
			if (tempCircle->getRadius() >= currentMax)
			{
				currentMax = tempCircle->getRadius();
			}
		}
	}

	return currentMax;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	for (Shape* shape : v)
	{
		std::cout << *shape << '\n';
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here

	return 0;
}
