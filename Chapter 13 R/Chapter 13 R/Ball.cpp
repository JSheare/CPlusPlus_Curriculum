#include <iostream>
#include <string>

#if 0  // Another ball class in 13.7 Q1
class Ball
{
private:
	std::string m_color{};
	double m_radius{};

public:
	Ball(float radius)
	{
		m_color = "black";
		m_radius = radius;
	}

	Ball(std::string_view color = "black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		std::cout << "Color: " << m_color << ", radius: " << m_radius << '\n';
	}
};
#endif


#if 0
int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}
#endif