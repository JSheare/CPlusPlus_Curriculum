#include <iostream>

void fizzbuzzpop(int limit)
{
	for (int i{ 1 }; i <= limit; ++i)
	{
		bool printed{ false };

		if (i % 3 == 0)
		{
			std::cout << "fizz";
			printed = true;
		}

		if (i % 5 == 0)
		{
			std::cout << "buzz";
			printed = true;
		}

		if (i % 7 == 0)
		{
			std::cout << "pop";
			printed = true;
		}

		if (!printed)
			std::cout << i;

		std::cout << '\n';
	}
}


#if 0
int main()
{
	fizzbuzzpop(150);
	return 0;
}
#endif