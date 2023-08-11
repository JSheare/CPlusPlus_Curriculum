#include <iostream>

#if 0
int main()
{

	int number{};
	do
	{
		std::cout << " Enter a number between 1 and 9: ";
		std::cin >> number;

		// if the user entered something invalid
		if (std::cin.fail())
		{
			std::cin.clear(); // reset any error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
		}

	} while (number < 1 || number > 9);

	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

	for (int num : array)
	{
		std::cout << num << ' ';
	}

	std::cout << '\n';

	for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
	{
		if (array[i] == number)
		{
			std::cout << number << " has index " << i << '\n';
			break;
		}
	}

	return 0;
}
#endif 