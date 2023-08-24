#ifndef DECK_h
#define DECK_H
#include "Card.h"

#include <array>

class Deck
{
public:
	Deck();

	void print() const;

	void shuffle();

	const Card& dealCard();

private:
	std::array<Card, 52> m_deck{};
	int m_cardIndex{ 0 };
};
#endif
