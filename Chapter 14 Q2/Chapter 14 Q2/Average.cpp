#include "Average.h"

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	out << static_cast<double>(avg.m_sum) / avg.m_length;

	return out;
}

Average& Average::operator+=(int value)
{
	m_sum += value;
	++m_length;
	return *this;
}