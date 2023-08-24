#include "Monster.h"

#include <array>

int getRandomNumber(int min, int max);

Monster::Monster(Type type)
	: Creature{ getDefaultCreature(type) }
{}

const Creature& Monster::getDefaultCreature(Type type)
{
	static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
	  { { "dragon", 'D', 20, 4, 100 },
		{ "orc", 'o', 4, 2, 25 },
		{ "slime", 's', 1, 1, 10 } }
	};

	return monsterData.at(static_cast<std::size_t>(type));
}

const Monster Monster::getRandomMonster()
{
	int number{ getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };

	return Monster{ static_cast<Type>(number)};
}
