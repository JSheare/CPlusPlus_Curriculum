#include <iostream>
#include "io.h"

int readNumber()
{
	int num = {};
	std::cout << "Please enter a number to add (integers only)\n";
	std::cin >> num;
	return num;
}

void writeAnswer(int num)
{
	std::cout << "The answer is " << num << '\n';
}