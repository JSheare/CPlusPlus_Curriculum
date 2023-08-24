#include "Player.h"
#include "Deck.h"
#include "Constants.h"
#include "Card.h"

int Player::score() const
{
	return m_score;
}

int Player::drawCard(Deck& deck)
{
	int value = deck.dealCard().value();
	m_score += value;
	return value;
}

bool Player::isBust() const
{
	return (m_score > constants::maximumScore);
}