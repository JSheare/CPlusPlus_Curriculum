#include "Player.h"

Player::Player(std::string_view name)
	: Creature{ name, '@', 10, 1, 0 }
{}

void Player::levelUp()
{
	++m_level;
	++m_dpa;
}