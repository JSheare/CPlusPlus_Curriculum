#include <iostream>

template <typename T>
struct Triad
{
    T member1{};
    T member2{};
    T member3{};
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& tri)
{
	std::cout << '[' << tri.member1 << ", " << tri.member2 << ", " << tri.member3 << ']';
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
