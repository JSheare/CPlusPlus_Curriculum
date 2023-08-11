#include <iostream>
#include <string>

#if 1
int main()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	std::cout << "Your age + length of name is: " << static_cast<int>(name.length()) + age << ".\n";

	return 0;
}
#endif