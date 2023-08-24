#include "Creature.h"

Creature::Creature(std::string_view name, char symbol, int health, int dpa, int gold)
	: m_name{ name }
	, m_symbol{ symbol }
	, m_health{ health }
	, m_dpa{ dpa }
	, m_gold{ gold }
{}