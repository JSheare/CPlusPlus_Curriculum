#include "FixedPoint2.h"

#include <cstdint>
#include <cmath>

using int16 = std::int16_t;
using int8 = std::int8_t;

FixedPoint2::FixedPoint2(int16 whole, int8 decimal)
	: m_whole{ whole }, m_decimal{ decimal }
{

	if (m_whole < 0 || m_decimal < 0)
	{
		if (m_whole > 0)
		{
			m_whole = -m_whole;
		}

		if (m_decimal > 0)
		{
			m_decimal = -m_decimal;
		}
	}
}

FixedPoint2::FixedPoint2(double number)
	: m_whole{static_cast<int16>(std::trunc(number))}, 
		m_decimal{static_cast<int8>(std::round(number * 100) - m_whole * 100)}
{
}

FixedPoint2::operator double() const
{
	return m_whole + (static_cast<double>(m_decimal) / 100);
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& point)
{
	out << static_cast<double>(point);

	return out;
}