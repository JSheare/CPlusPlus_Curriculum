#include "MyString.h"

#include <iostream>
#include <string>
#include <cassert>

std::ostream& operator<<(std::ostream& out, const MyString& string)
{
	out << string.m_string;

	return out;
}

std::string_view MyString::substr(int index, int length) const
{
	assert(index >= 0);
	assert(index + length <= static_cast<int>(m_string.length())
		&& "Provided length out of range");

	return std::string_view { m_string }.substr(
		static_cast<std::string_view::size_type>(index),
		static_cast<std::string_view::size_type>(length));
}

std::string MyString::operator()(int index, int length)
{
	assert(index >= 0);
	assert(index + length <= static_cast<int>(m_string.length())
	&& "Provided length out of range");

	return m_string.substr(
		static_cast<std::string::size_type>(index), 
		static_cast<std::string::size_type>(length));
}