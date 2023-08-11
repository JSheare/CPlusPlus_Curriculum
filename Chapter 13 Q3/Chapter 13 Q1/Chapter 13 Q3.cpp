#include <iostream>
#include <array>
#include "Monster.h"
#include "Random.h"

namespace MonsterGenerator
{
	Monster generate()
	{
		int maxIndex{ Monster::Type::max_monster_types };
		auto type{ static_cast<Monster::Type>(Random::get(0, maxIndex)) };
		int hitPoints{ Random::get(1, 100) };

		static constexpr std::array s_names{"Barry", "Larry", "Moe", "Curly", "John", "Jane"};
		static constexpr std::array s_roars{"*rattle*", "*purr*", "*squeak*", "*crash*", "*grunt*", "*bark*"};

		auto name{ s_names[Random::get<std::size_t>(0, s_names.size() - 1)] };
		auto roar{ s_roars[Random::get<std::size_t>(0, s_roars.size() - 1)] };

		return Monster(type, name, roar, hitPoints);
	}
}


int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
