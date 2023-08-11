#include <iostream>

int sumTo(int value)
{
	int sum{ 0 };
	for (int i{ 1 }; i <= value; ++i)
	{
		sum += i;
	}

	return sum;
}


#if 0
int main()
{
	std::cout << sumTo(5);
	return 0;
}
#endif