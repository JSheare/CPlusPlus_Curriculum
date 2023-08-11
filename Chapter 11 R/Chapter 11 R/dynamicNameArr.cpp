#include <iostream>
#include <string>
#include <algorithm>

void getNames(std::string* arr, std::size_t length)
{
	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::getline(std::cin >> std::ws, arr[i]);
	}
}

void printNames(std::string* arr, std::size_t length)
{

	std::cout << "\nHere is your sorted list:\n";

	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << "Name #" << i + 1 << ": " << arr[i] << '\n';
	}
}

std::size_t getLength()
{
	std::size_t length{};
	std::cout << "How many names would you like to enter? ";
	std::cin >> length;

	return length;
}

#if 0
int main()
{

	std::size_t length{getLength()};

	std::string* names{new std::string[length]{}};

	getNames(names, length);

	std::sort(names, names+length);
	
	printNames(names, length);

	delete[] names;
	names = nullptr;
	
	return 0;
}
#endif