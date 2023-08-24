#include "Deck.h"
#include "Card.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
#include <cassert>

Deck::Deck()
{
	int index{ 0 };
	for (int suit{ 0 }; suit < Card::max_suits; ++suit)
	{
		for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
		{
			m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
			++index;
		}
	}
}

void Deck::print() const
{
	for (const auto& card : m_deck)
	{
		card.print();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffle()
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(m_deck.begin(), m_deck.end(), mt);

	m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
	assert(m_cardIndex < m_deck.size());

	return m_deck[m_cardIndex++];
}