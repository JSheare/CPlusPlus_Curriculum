#include <cstdint> // for std::uint8_t
#include <iostream>

int main()
{
    std::cout << "How old are you?\n";

    std::uint8_t age{}; // Why use uint8_t when you can just use int?
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    if (age >= 16) // 16 is a magic number
        std::cout << "x"; // use single quotes instead
    else
        std::cout << " "; // use single quotes here too

    std::cout << "]\n";

    return 0;
}