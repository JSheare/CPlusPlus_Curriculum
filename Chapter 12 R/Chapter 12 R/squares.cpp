#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

using VectorInt = std::vector<int>;

namespace Config
{
	constexpr int multiplierMin{ 2 };
	constexpr int multiplierMax{ 4 };
	constexpr int maxWrongAnswer{ 4 };
}

int getRandomInt(int min, int max)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	return std::uniform_int_distribution{ min, max }(mt);
}

VectorInt makeNumbers(int start, int size, int multiplier)
{
	VectorInt numbers(static_cast<VectorInt::size_type>(size));

	int i{ start };

	for (auto& number : numbers)
	{
		number = (i * i) * multiplier;
		++i;
	}

	return numbers;
}

VectorInt getUserNumbers(int multiplier)
{
	int start{};
	int size{};
	
	std::cout << "Start where? ";
	std::cin >> start;

	std::cout << "How many? ";
	std::cin >> size;

	return makeNumbers(start, size, multiplier);
}

void printMessage(VectorInt::size_type size, int multiplier)
{
	std::cout << " I generated " << size
			  << " square numbers. Do you know what each number is after multiplying it by "
			  << multiplier << "?\n";
}

int getGuess()
{
	int guess{ };

	std::cout << "> ";
	std::cin >> guess;

	return guess;
}

void printSuccess(VectorInt::size_type numsLeft)
{
	std::cout << "Nice! ";

	if (numsLeft == 0)
	{
		std::cout << " You found all the numbers, good job!\n";
	}
	else
	{
		std::cout << numsLeft << " number(s) left. \n";
	}
}

int findClosest(const VectorInt& numbers, int guess)
{
	return *(std::min_element(numbers.begin(), numbers.end(),
		[=](int a, int b) {
			return (std::abs(a - guess) < std::abs(b - guess)); }));
}

void printFailure(const VectorInt& numbers, int guess)
{
	int closest{ findClosest(numbers, guess) };

	std::cout << guess << " is wrong! ";

	if (std::abs(closest - guess) < Config::maxWrongAnswer)
	{
		std::cout << "Try " << closest << " next time.\n";
	}
	else
	{
		std::cout << '\n';
	}
}

bool findAndRemove(VectorInt& numbers, int guess)
{
	auto found{ std::find(numbers.begin(), numbers.end(), guess) };

	if (found == numbers.end())
	{
		return false;
	}
	else
	{
		numbers.erase(found);
		return true;
	}
}

bool playRound(VectorInt& numbers)
{
	int guess{ getGuess() };

	if (findAndRemove(numbers, guess))
	{
		printSuccess(numbers.size());
		return !numbers.empty();
	}
	else
	{
		printFailure(numbers, guess);
		return false;
	}
}

#if 0
int main()
{
	int multiplier{ getRandomInt(Config::multiplierMin, Config::multiplierMax) };
	VectorInt numbers{ getUserNumbers(multiplier) };

	printMessage(numbers.size(), multiplier);

	while (playRound(numbers))
		;
	return 0;
}
#endif