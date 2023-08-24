#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "Tile.h"
#include "Point.h"

class Board
{
private:
	static constexpr int SIZE = 4;
	Tile m_tiles[SIZE][SIZE]
	{
		Tile{1}, Tile{2}, Tile{3}, Tile{4},
		Tile{5}, Tile{6}, Tile{7}, Tile{8},
		Tile{9}, Tile{10}, Tile{11}, Tile{12},
		Tile{13}, Tile{14}, Tile{15}, Tile{0} };
public:
	Board() = default;

	static void printEmptyLines(int count);

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	static bool isValidTilePoint(Point& point);

	Point getEmptyTilePos() const;

	void swapTiles(Point& point1, Point& point2);

	bool moveTile(Direction direction);

	void randomize(int moves = 1000);

	friend bool operator==(Board& board1, Board& board2);

	bool playerWon();
};

#endif
