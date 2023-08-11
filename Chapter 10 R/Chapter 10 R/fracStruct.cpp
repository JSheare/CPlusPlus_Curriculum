#include <iostream>
#include <stdexcept>

struct Fraction
{
	int numerator{ 0 };
	int denominator{ 1 };
};

Fraction enterFrac()
{
	Fraction temp;
	std::cout << "Enter a value for the numerator: ";
	std::cin >> temp.numerator;
	int denom;
	std::cout << "Enter a value for the denominator: ";
	std::cin >> denom;
	if (denom == 0)
		throw std::runtime_error("Division by zero is not allowed");
	temp.denominator = denom;

	std::cout << '\n';
	return temp;
}

Fraction operator*(const Fraction& x, const Fraction& y)
{
	Fraction temp;
	temp.numerator = x.numerator * y.numerator;
	temp.denominator = x.denominator * y.denominator;

	return temp;
}

void printFraction(const Fraction& frac)
{
	std::cout << frac.numerator << '/' << frac.denominator << '\n';
}


#if 0
int main()
{
	Fraction x{ enterFrac() };
	Fraction y{ enterFrac() };
	std::cout << "Your fractions multiplied together: ";
	printFraction(x * y);
	return 0;
}
#endif