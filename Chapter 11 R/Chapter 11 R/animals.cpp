#include <iostream>

namespace Animal
{
	enum AnimalTypes
	{
		chicken, 
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals,
	};
}

#if 0
int main()
{
	int numLegs[Animal::max_animals]{ 2, 4, 4, 4, 2, 0 };
	std::cout << "An elephant has " << numLegs[Animal::elephant] << " legs.\n";
	return 0;
}
#endif