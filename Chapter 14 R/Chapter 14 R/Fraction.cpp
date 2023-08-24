#include "Fraction.h"
#include <iostream>
#include <limits>
#include <cassert>
#include <numeric>

Fraction::Fraction(int numerator, int denominator)
	: m_numerator{numerator}
{
	assert(denominator != 0 && "A denominator of zero is invalid");
	m_denominator = denominator;
	reduce();
}

void Fraction::print() const
{
	std::cout << m_numerator << '/' << m_denominator << '\n';
}

Fraction operator*(const Fraction& fraction, int integer)
{
	return { fraction.m_numerator * integer, fraction.m_denominator };
}

Fraction operator*(int integer, const Fraction& fraction)
{
	return { fraction.m_numerator * integer, fraction.m_denominator };
}

Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
{
	return { fraction1.m_numerator * fraction2.m_numerator,
		fraction1.m_denominator * fraction2.m_denominator };
}

void Fraction::reduce()
{
	int gcd{ std::gcd(m_numerator, m_denominator) };
	if (gcd)
	{
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.m_numerator << '/' << fraction.m_denominator;

	return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	in >> fraction.m_numerator;

	in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

	in >> fraction.m_denominator;

	fraction.reduce();

	return in;
}

bool operator>(const Fraction& fraction1, const Fraction& fraction2)
{
	return (fraction1.m_numerator * fraction2.m_denominator > fraction2.m_numerator * fraction1.m_denominator);
}

bool operator<(const Fraction& fraction1, const Fraction& fraction2)
{
	return (!operator>(fraction1, fraction2));
}

bool operator==(const Fraction& fraction1, const Fraction& fraction2)
{
	return (fraction1.m_numerator == fraction2.m_numerator && fraction1.m_denominator == fraction2.m_denominator);
}

bool operator!=(const Fraction& fraction1, const Fraction& fraction2)
{
	return (!operator==(fraction1, fraction2));
}

bool operator>=(const Fraction& fraction1, const Fraction& fraction2)
{
	return (!operator<(fraction1, fraction2));
}

bool operator<=(const Fraction& fraction1, const Fraction& fraction2)
{
	return (!operator>=(fraction1, fraction2));
}