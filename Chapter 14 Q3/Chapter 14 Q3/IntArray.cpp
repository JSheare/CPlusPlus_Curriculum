#include "IntArray.h"

#include <cassert>

IntArray::IntArray(int length)
	: m_length{ length }
{
	assert(length > 0 && "IntArray length should be a positive integer");

	m_array = new int[length] {};
}

IntArray::IntArray(const IntArray& array)
	: m_length{array.m_length}
{
	m_array = new int[array.m_length]{};

	for (int index{ 0 }; index < array.m_length; ++index)
	{
		m_array[index] = array.m_array[index];
	}
}

IntArray::~IntArray()
{
	delete[] m_array;
}

std::ostream& operator<<(std::ostream& out, const IntArray& array)
{
	for (int index{ 0 }; index < array.m_length; ++index)
	{
		out << *(array.m_array + index) << ' ';
	}

	out << '\n';

	return out;
}

int& IntArray::operator[](int index)
{
	assert(index >= 0 && "Index outside of range");

	assert(index < m_length && "Index outside of range");

	return m_array[index];
}

IntArray& IntArray::operator=(const IntArray& array)
{
	if (this == &array)
	{
		return *this;
	}

	delete[] m_array;

	m_length = array.m_length;

	m_array = new int[m_length] {};

	for (int index{ 0 }; index < m_length; ++index)
	{
		m_array[index] = array.m_array[index];
	}

	return *this;
}