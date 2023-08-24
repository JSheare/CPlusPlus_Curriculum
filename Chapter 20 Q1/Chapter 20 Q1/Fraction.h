#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

#include <stdexcept>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

#endif
