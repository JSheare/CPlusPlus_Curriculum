#include <iostream>

void printBinary(unsigned int x)
{
	if (x > 1)
	{
		printBinary(x / 2);
	}

	std::cout << x % 2;
}

#if 0
int main()
{
	printBinary(static_cast<unsigned int>(148));
	return 0;
}
#endif 