#include <iostream>
int factorial(int N = { 0 })
{
	if (N <= 0)
		return 1;

	return N * factorial(N - 1);
}



#if 0
int main()
{
	for (int i{ 1 }; i <= 7; ++i)
	{
		std::cout << i << "! = " << factorial(i) << '\n';
	}
	return 0;
}
#endif