#include <iostream>
#include <string>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

constexpr std::string_view getAnimalName(const Animal& animal)
{
	switch (animal)
	{
	case Animal::pig:
		return "pig";
	case Animal::chicken:
		return "chicken";
	case Animal::goat:
		return "goat";
	case Animal::cat:
		return "cat";
	case Animal::dog:
		return "dog";
	case Animal::duck:
		return "duck";

	default:
		return "?";
	}
}

void printNumberOfLegs(const Animal& animal)
{
	std::cout << "A " << getAnimalName(animal) << " has ";

	switch (animal)
	{
	case Animal::pig:
		std::cout << 4;
		break;
	case Animal::chicken:
		std::cout << 2; 
		break;
	case Animal::goat:
		std::cout << 4;
		break;
	case Animal::cat:
		std::cout << 4;
		break;
	case Animal::dog:
		std::cout << 4;
		break;
	case Animal::duck:
		std::cout << 2;
		break;

	default:
		std::cout << '?';
		break;
	}

	std::cout << " legs.\n";
}

#if 0
int main()
{
	Animal kitty{ Animal::cat };
	Animal chicky{ Animal::chicken }; 
	printNumberOfLegs(kitty);
	printNumberOfLegs(chicky);
	return 0;
}
#endif 