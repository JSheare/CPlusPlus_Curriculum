#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
	double heightNow = { initialHeight - (myConstants::gravity * (seconds * seconds) / 2) };

	if (heightNow < 0.0)
	{
		return 0.0;
	}
	else
	{
		return heightNow;
	}

}

bool calculateAndPrintHeight(double initialHeight, int time)
{
	double currentHeight = { calculateHeight(initialHeight, time) };
	std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << '\n';
	return (currentHeight == 0.0);
}

int main()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight = {};
	std::cin >> initialHeight;
	int seconds = { 0 };
	while (!calculateAndPrintHeight(initialHeight, seconds))
	{
		++seconds;
	}

	return 0;
}
