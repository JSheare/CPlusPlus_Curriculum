#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

class IntArray
{
public:
	IntArray(int length);

	IntArray(const IntArray& array);

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array);

	int& operator[](int index);

	IntArray& operator=(const IntArray& array);

	~IntArray();

private:
	int m_length{ 0 };
	int* m_array{nullptr};
};

#endif
