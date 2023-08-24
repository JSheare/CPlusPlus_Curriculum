#ifndef FIXEDPOINT2_H
#define FIXEDPOINT2_H

#include <cstdint>
#include <iostream>

using int16 = std::int16_t;
using int8 = std::int8_t;

class FixedPoint2
{
public:
	FixedPoint2(int16 whole, int8 decimal);

	FixedPoint2(double number);

	operator double() const;

	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& point);

private:
	int16 m_whole{};
	int8 m_decimal{};
};
#endif
