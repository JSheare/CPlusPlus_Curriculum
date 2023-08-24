#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction
{
public:
	Fraction(int numerator = 0, int denominator = 1);

	void print() const;

	void reduce();

	friend Fraction operator*(const Fraction& fraction, int integer);
	friend Fraction operator*(int integer, const Fraction& fraction);
	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);

	friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
	friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
	friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
	friend bool operator!=(const Fraction& fraction1, const Fraction& fraction2);
	friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);
	friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);

private:
	int m_numerator{};
	int m_denominator{};
};
#endif