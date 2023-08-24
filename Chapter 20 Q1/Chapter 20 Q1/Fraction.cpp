#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
	: m_numerator{ numerator }, m_denominator{ denominator }
{
	if (m_denominator == 0)
		throw std::runtime_error("Invalid Denominator");

	if (m_numerator < 0 && !(m_denominator < 0))
	{
		m_denominator = -m_denominator;
	}

	if (m_denominator < 0 && !(m_numerator < 0))
	{
		m_numerator = -m_numerator;
	}

}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.m_numerator << '/' << fraction.m_denominator;

	return out;
}