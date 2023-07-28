#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

enum Items
{
	health_potions,
	torches,
	arrows,
};

using Inventory = std::array<int, 3>;

int countTotalItems(const Inventory& inventory)
{
	return std::reduce(inventory.begin(), inventory.end());
}

int main()
{
	Inventory playerInventory{2, 5, 10};
	std::cout << "The player has " << countTotalItems(playerInventory) << " items total.\n";
	std::cout << "This includes " << playerInventory[torches] << " torches.\n";
	return 0;
}


