#include "Monster.h"

#include <iostream>

Monster::Monster(Type type, std::string name, std::string roar, int hitPoints)
	: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
{
}

std::string_view Monster::getTypeString() const
{
	switch (m_type)
	{
	case dragon:	return "dragon";
	case goblin:	return "goblin";
	case ogre:		return "ogre";
	case orc:		return "orc";
	case skeleton:	return "skeleton";
	case troll:		return "troll";
	case vampire:	return "vampire";
	case zombie:	return "zombie";

	default:
		return "???";
	}
}

void Monster::print() const
{
	std::cout << m_name << " the " << getTypeString() << " has " 
		<< m_hitPoints << " hit points and says " << m_roar << '\n';
}