#include <iostream>

int digitSum(int n)
{
	if (n < 10)
		return n;

	return n % 10 + digitSum(n / 10);
}

#if 0
int main()
{
	std::cout << digitSum(93427) << '\n';
	return 0;
}
#endif