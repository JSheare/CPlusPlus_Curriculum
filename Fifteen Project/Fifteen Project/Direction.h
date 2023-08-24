#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction
{
public:
	enum Type
	{
		up,
		down,
		left,
		right,

		max_directions,
	};

	Direction(Type direction);

	Direction operator-() const;

	Type getType() const { return m_direction; }

	friend std::ostream& operator<<(std::ostream& out, Direction direction);

	static Direction getRandomDirection();

private:
	Type m_direction{};
};
#endif
