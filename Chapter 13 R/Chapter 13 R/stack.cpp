#include <iostream>
#include <cassert>
#include <array>

class Stack
{
private:
	using Array = std::array<int, 10>;
	using Index = std::array<int, 10>::size_type;

	Array m_array{};
	Index m_index{ 0 };


public:
	void reset()
	{
		m_index = 0;
	}

	bool push(int value)
	{
		if (m_index == m_array.size())
		{
			return false;
		}

		m_array[m_index++] = value;
		return true;
	}

	int pop()
	{
		assert(m_array.size() > 0 && "Stack empty");

		return m_array[--m_index];
	}

	void print()
	{
		std::cout << '(';
		for (Index i{0}; i < m_index; ++i)
		{
			std::cout << ' ' << m_array[i] << ' ';
		}
		std::cout << ")\n";
	}

};

#if 0
int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
#endif