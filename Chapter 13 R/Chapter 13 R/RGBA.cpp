#include <iostream>
#include <cstdint>

class RGBA
{
	using Uint8 = std::uint8_t;

private:
	Uint8 m_red{};
	Uint8 m_green{};
	Uint8 m_blue{};
	Uint8 m_alpha{};

public:
	RGBA(Uint8 red = 0, Uint8 green = 0, Uint8 blue = 0, Uint8 alpha = 255) : 
		m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{
	}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red)
			<< " g=" << static_cast<int>(m_green)
			<< " b=" << static_cast<int>(m_blue)
			<< " a=" << static_cast<int>(m_alpha) 
			<< '\n';
	}
};


# if 0
int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}
#endif