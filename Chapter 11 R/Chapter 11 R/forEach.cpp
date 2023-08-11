#include <iostream>
#include <string>

#if 0
int main()
{
	constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::string name{};
	std::cout << "Enter a name: ";
	std::cin >> name;

	bool found{ false };
	for (std::string_view n : names)
	{
		if (n == name)
		{
			found = true;
			break;
		}
	}

	if (found)
		std::cout << name << " was found.\n";
	else
		std::cout << name << " was not found.\n";

	return 0;
}
#endif