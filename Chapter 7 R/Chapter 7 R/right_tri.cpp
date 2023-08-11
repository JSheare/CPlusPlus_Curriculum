#include <iostream>

#if 0
int main()
{
	int outer{ 1 };
	int gap{ 4 };
	while (outer <= 5)
	{
		int inner{ outer };
		int inner_gap{ gap };
		while (inner_gap > 0)
		{
			std::cout << "  ";
			--inner_gap;
		}

		while (inner > 0)
		{
			std::cout << ' ' << inner;
			--inner;
		}

		std::cout << '\n';
		++outer;
		--gap;
	}




	return 0;
}
#endif