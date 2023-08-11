#include <iostream>

template <typename T>
void bubbleSort(T& container)
{
	const int length{ static_cast<int>(std::size(container)) };
	
	for (int i{ length - 2}; i >= 0; --i)
	{
		bool swap{ false };
		for (int j{ 0 }; j <= i; ++j)
		{
			if (container[j] > container[j + 1])
			{
				std::swap(container[j], container[j + 1]);
				swap = true;
			}
		}

		if (!swap)
			break;
	}
}

// Note: This is basically just question 4 instead. I've seen bubble sort before and just recreated it from memory

#if 0
int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8, 14, 17, 19, 135, 56, 32, 78, 49 };
	bubbleSort(array);
	for (int num : array)
	{
		std::cout << num << ' ';
	}
	return 0;
}
#endif