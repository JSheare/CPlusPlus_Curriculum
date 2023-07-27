#include <iostream>
#include <string_view>
#include <string>


enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime,
};

struct Monster
{
	MonsterType type{};
	std::string_view name{};
	int health{};
};

constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
		case MonsterType::ogre:			return "Ogre";
		case MonsterType::dragon:		return "Dragon";
		case MonsterType::orc:			return "Orc";
		case MonsterType::giant_spider: return "Giant Spider";
		case MonsterType::slime:		return "Slime";
		default:						return "";
	}
}

void printMonster(const Monster& ourMonster)
{
	std::cout << "This " << getMonsterTypeString(ourMonster.type) << 
		" is named " << ourMonster.name << 
		" and has " << ourMonster.health << " health.\n";
}


int main()
{
	Monster torg{ MonsterType::ogre, "Torg", 145 };
	Monster blurp{ MonsterType::slime, "Blurp", 23 };
	printMonster(torg);
	printMonster(blurp);
	return 0;
}