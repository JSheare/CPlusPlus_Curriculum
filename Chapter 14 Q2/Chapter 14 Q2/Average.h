#ifndef AVERAGE_H
#define AVERAGE_H
#include <cstdint>
#include <iostream>
class Average
{
public:
	Average()
	{}

	friend std::ostream& operator<<(std::ostream& out, const Average& avg);

	Average& operator+=(int value);

private:
	std::int32_t m_sum{};
	std::int8_t m_length{};
};
#endif
