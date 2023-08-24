#include <iostream>
#include <algorithm>

#include "Board.h"
#include "Tile.h"
#include "Constants.h"
#include "Point.h"

void Board::printEmptyLines(int count)
{
	for (int i{ 0 }; i < count; ++i)
	{
		std::cout << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{

	Board::printEmptyLines(Constants::g_consoleLines);

	for (int y{ 0 }; y < Board::SIZE; ++y)
	{
		for (int x{ 0 }; x < Board::SIZE; ++x)
		{
			out << board.m_tiles[y][x];
		}
		
		out << '\n';
	}

	return out;
}

bool Board::isValidTilePoint(Point& point)
{
	int x{ point.getX() };
	int y{ point.getY() };
	return(x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

Point Board::getEmptyTilePos() const
{
	for (int y{ 0 }; y < SIZE; ++y)
	{
		for (int x{ 0 }; x < SIZE; ++x)
		{
			if (m_tiles[y][x].getNum() == 0)
			{
				return Point(x, y);
			}
		}
	}

	return Point(0, 0);  // shouldn't happen
}

void Board::swapTiles(Point& point1, Point& point2)
{
	std::swap(m_tiles[point1.getY()][point1.getX()], m_tiles[point2.getY()][point2.getX()]);
}

bool Board::moveTile(Direction direction)
{
	Point emptyTile{ getEmptyTilePos() };
	Point adjacent{ emptyTile.getAdjacentPoint(-direction) };

	if (!isValidTilePoint(adjacent))
	{
		return false;
	}

	swapTiles(adjacent, emptyTile);
	return true;
}

void Board::randomize(int moves)
{
	while (moves > 0)
	{
		Direction randomDir{ Direction::getRandomDirection() };
		if (moveTile(randomDir))
			--moves;
	}
}

bool operator==(Board& board1, Board& board2)
{
	for (int y{ 0 }; y < board1.SIZE; ++y)
	{
		for (int x{ 0 }; x < board1.SIZE; ++x)
		{
			if (board1.m_tiles[y][x].getNum() != board2.m_tiles[y][x].getNum())
				return false;
		}
	}

	return true;
}

bool Board::playerWon()
{
	Board tempBoard{};
	return (*this == tempBoard);
}
