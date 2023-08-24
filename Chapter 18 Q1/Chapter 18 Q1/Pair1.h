#ifndef PAIR1_H
#define PAIR1_H

template <typename T>
class Pair1
{
private:
	T m_first{};
	T m_second{};
public:
	Pair1(T first, T second)
		: m_first{ first }, m_second{ second }
	{}

	const T& first() const { return m_first; }
	const T& second() const { return m_second; }
};

#endif
