#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
#include <iostream>
class MyString
{
public:
	MyString(std::string string) 
		: m_string{string}
	{}

	friend std::ostream& operator<<(std::ostream& out, const MyString& string);

	std::string_view substr(int index, int length) const;

	std::string operator()(int index, int length);

private:
	std::string m_string{};
};
#endif
