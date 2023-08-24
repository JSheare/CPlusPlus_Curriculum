#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "Monster.h"
#include "Player.h"


int getRandomNumber(int min, int max)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

	std::uniform_int_distribution die6{ min, max };

	return die6(mt);
}

char chooseAction()
{
	char choice{};
	while (true)
	{
		std::cout << " (R)un or (F)ight: ";
		std::cin >> choice;

		if (choice == 'r' || choice == 'f'
			|| choice == 'R' || choice == 'F')
			break;
	}

	return choice;
}

// handles the monster attacking the player
void attackPlayer(Player& player, Monster& monster)
{
	if (monster.isDead())
	{
		return;
	}

	std::cout << "The " << monster.getName() << " hit you for " << monster.getDPA() << " damage.\n";
	player.reduceHealth(monster.getDPA());
}

// handles the player attacking the monster, including leveling up
void attackMonster(Player& player, Monster& monster)
{
	if (player.isDead())
	{
		return;
	}

	monster.reduceHealth(player.getDPA());
	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << ".\n";

		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";

		player.addGold(monster.getGold());
		std::cout << "You found " << monster.getGold() << " gold.\n";
	}
	else
	{
		attackPlayer(player, monster);
	}
}

// handles the fight between the Player and a single Monster, including asking the player what they want to do, handling the run or fight cases
void fightMonster(Player& player)
{
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";

	while (!monster.isDead() && !player.isDead())
	{
		char choice{ chooseAction() };
		if (choice == 'r' || choice == 'R')
		{
			int successChance{ getRandomNumber(0, 1) };
			if (successChance == 0)
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(player, monster);
			}
			else
			{
				std::cout << "You successfully fled.\n";
				break;
			}
		}
		else
		{
			attackMonster(player, monster);
		}
	}


}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	std::cout << "Enter your name: ";
	std::string playerName{};
	std::cin >> playerName;
	Player player{ playerName };
	std::cout << "Welcome, " << player.getName() << '\n';

	while (!player.hasWon() && !player.isDead())
	{
		fightMonster(player);
	}

	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won with " << player.getGold() << "gold!\n";
	}

	return 0;
}
