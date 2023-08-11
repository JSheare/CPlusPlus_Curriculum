#include <iostream>

#if 0
int readNumber()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The answer is " << x << ".\n";
}
#endif

#if 0
int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnswer(x + y);
	return 0;
}
#endif