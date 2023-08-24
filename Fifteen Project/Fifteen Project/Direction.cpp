#include <iostream>
#include <cassert>

#include "Random.h"
#include "Direction.h"

Direction::Direction(Type direction)
	: m_direction{ direction }
{}

Direction Direction::operator-() const
{
	switch (m_direction)
	{
	case up: return Direction{ down };
	case down: return Direction{ up };
	case left: return Direction{ right };
	case right: return Direction{ left };
	}

	assert(0 && "Not a valid direction");
	return Direction{ up };
}

std::ostream& operator<<(std::ostream& out, Direction direction)
{
	switch (direction.m_direction)
	{
	case Direction::up:		return(out << "up");
	case Direction::down:	return(out << "down");
	case Direction::left:	return(out << "left");
	case Direction::right:	return(out << "right");
	default:
		return(out << '?');
	}
}

Direction Direction::getRandomDirection()
{
	Type random{ static_cast<Type>(Random::get(0, Type::max_directions - 1)) };
	return Direction{ random };
}