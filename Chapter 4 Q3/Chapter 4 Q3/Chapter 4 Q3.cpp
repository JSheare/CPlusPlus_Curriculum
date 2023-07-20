#include <iostream>

double getNum()
{
	std::cout << "Enter a double value: ";
	double num = {};
	std::cin >> num;
	return num;
}

char getSymbol()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char symbol = {};
	std::cin >> symbol;
	return symbol;
}

void printAnswer(double x, double y, char symbol)
{
	if (symbol == '+') 
		std::cout << x << " + " << y << " is " << x + y << '\n';

	else if (symbol == '-') 
		std::cout << x << " - " << y << " is " << x - y << '\n';

	else if (symbol == '*')
		std::cout << x << " * " << y << " is " << x * y << '\n';

	else if (symbol == '/')
		std::cout << x << " / " << y << " is " << x / y << '\n';

}


int main()
{
	double x = { getNum() };
	double y = { getNum() };
	char symbol = { getSymbol() };
	printAnswer(x, y, symbol);

	return 0;
}
