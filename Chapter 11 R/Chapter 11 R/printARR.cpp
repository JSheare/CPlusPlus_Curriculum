#include <iostream>

#if 0
int main()
{
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	int array_size = sizeof(array) / sizeof(int);

	for (int i{ 0 }; i < array_size; ++i)
		std::cout << array[i] << '\n';

	/*for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
		std::cout << array[i] << '\n';*/
	//std::size returns an unsigned 64 bit integer
	return 0;
}
#endif