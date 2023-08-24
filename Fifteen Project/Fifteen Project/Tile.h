#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
	int m_number{};
public:
	explicit Tile(int number);

	int getNum() const;

	bool isEmpty() const;

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

#endif
