#include <iostream>
#include <string>

void fizzBuzz(int limit)
{
	constexpr int divisors[]{ 3, 5, 7, 11, 13, 17, 19};
	constexpr std::string_view words[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
	static_assert(std::size(divisors) == std::size(words));

	constexpr int arrSize{ static_cast<int>(std::size(divisors)) };

	for (int num{ 1 }; num <= limit; ++num)
	{
		bool printed{ false };
		for (int index{ 0 }; index < arrSize; ++index)
		{
			if (num % divisors[index] == 0)
			{
				std::cout << words[index];
				printed = true;
			}
		}

		if (!printed)
			std::cout << num;

		std::cout << '\n';
	}
}

#if 0
int main()
{
	fizzBuzz(21);
	return 0;
}
#endif 