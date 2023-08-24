#ifndef PLAYER_H
#define PLAYER_H

class Deck;

class Player
{
public:
	int score() const;

	int drawCard(Deck& deck);

	bool isBust() const;

private:
	int m_score{ 0 };
};

#endif
