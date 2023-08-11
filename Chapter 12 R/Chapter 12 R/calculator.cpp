#include <iostream>
#include <functional>

int getInt()
{
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;
	return num;
}

char getOperation()
{
	char op{};
	do
	{
		std::cout << "Enter an operation (+, -, *, /): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return &add;
	case '-': return &subtract;
	case '*': return &multiply;
	case '/': return &divide;
	}

	return nullptr;

}

#if 0
int main()
{
	int x{ getInt() };
	char op{ getOperation() };
	int y{ getInt() };

	ArithmeticFunction function{ getArithmeticFunction(op) };
	if (function)
		std::cout << x << ' ' << op << ' ' << y << " = " << function(x, y) << '\n';

	return 0;
}
#endif