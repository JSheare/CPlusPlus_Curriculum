#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster
{
public:
	enum Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,

		max_monster_types,
	};

	Monster(Type type, std::string name, std::string roar, int hitPoints);

	std::string_view getTypeString() const;

	void print() const;

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

};

#endif
