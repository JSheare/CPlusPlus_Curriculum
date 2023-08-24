#ifndef PAIR2_H
#define PAIR2_H

template <typename T, typename U>
class Pair
{
private:
	T m_first{};
	U m_second{};

public:
	Pair(const T first, const U second)
		: m_first{ first }, m_second{ second }
	{} 

	T& first() { return m_first; }
	U& second() {return m_second; }
	const T& first() const { return m_first; }
	const U& second() const { return m_second; }

};

#endif
