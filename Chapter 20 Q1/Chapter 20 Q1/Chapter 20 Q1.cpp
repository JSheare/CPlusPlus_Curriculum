#include <iostream>

#include "Fraction.h"

int main()
{
		std::cout << "Enter the numerator: ";
		int numerator{};
		std::cin >> numerator;

		std::cout << "Enter the denominator: ";
		int denominator{};
		std::cin >> denominator;

	try
	{
		Fraction fraction{ numerator, denominator };
		std::cout << "Your fraction is " << fraction << '\n';
	}
	catch (std::runtime_error error)
	{
		std::cout << error.what() << '\n';
	}
}
