#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_dpa{};
	int m_gold{};

public:
	Creature(std::string_view name, char symbol, int health, int dpa, int gold);

	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDPA() const { return m_dpa; }
	int getGold() const { return m_gold; }

	void reduceHealth(int hp) {m_health -= hp;}

	bool isDead() { return m_health <= 0; }

	void addGold(int gold) { m_gold += gold; }

};

#endif 
