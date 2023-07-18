#include <iostream>

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

int main()
{
	int num1 = { readNumber() };
	int num2 = { readNumber() };
	writeAnswer(num1 + num2);
	return 0;
}
