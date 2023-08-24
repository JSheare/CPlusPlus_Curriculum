#include "Tile.h"

Tile::Tile(int number)
	: m_number{ number }
{}

int Tile::getNum() const
{
	return m_number;
}


bool Tile::isEmpty() const
{
	return m_number == 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	if (tile.m_number > 9)
		out << ' ' << tile.m_number << ' ';
	else if (tile.m_number > 0)
		out << "  " << tile.m_number << ' ';
	else if (tile.m_number == 0)
		out << "    ";

	return out;
}