#include <iostream>

/*
    CHAPTER 19 R
*/

/*
    19.1
*/
// Making class templates works pretty much identically to making function templates:
#include <cassert>

template <typename T> // added
class Array
{
private:
    int m_length{};
    T* m_data{}; // changed type to T

public:

    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{}; // allocated an array of objects of type T
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    // templated operator[] function defined below
    T& operator[](int index); // now returns a T&

    int getLength() const { return m_length; }
};

// member functions defined outside the class need their own template declaration
template <typename T>
T& Array<T>::operator[](int index) // now returns a T&
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

// Note: each templated member function defined outside the class declaration needs its own template declaration
// Note also that it's Array<T>, not just Array

// Note that template classes and their template member functions cannot be defined in different files
// Ways around this:
// Define the class template and class member templates in the same header file
//      The downside of this is that you'll end up with a lot of redundant copies of the class template code wherever you've included the header, which increases compile and link times
// You could also move all the code into a .inl file and #include the .inl file in the header

// Just put everything in the header, who cares about compile/linker times

/*
    19.2
*/
// A template non-type parameter is a template parameter where the type of the parameter is predefined and substituted for a consterxpr value passed in as an argument
// A non-type parameter can be any of the following types:
// An integral type
// An enumeration type
// A pointer or reference to a class object
// A pointer or reference to a function
// A pointer or reference to a class member function
// std::nullptr_t
// A floating point type (since C++20)

//Ex:
template <typename T, int size> // size is an integral non-type parameter
class StaticArray
{
private:
    // The non-type parameter controls the size of the array
    T m_array[size]{};

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

// Showing how a function for a class with a non-type parameter is defined outside of the class
template <typename T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

//int main()
//{
//    // declare an integer array with room for 12 integers
//    StaticArray<int, 12> intArray;
//
//    // Fill it up in order, then print it backwards
//    for (int count{ 0 }; count < 12; ++count)
//        intArray[count] = count;
//
//    for (int count{ 11 }; count >= 0; --count)
//        std::cout << intArray[count] << ' ';
//    std::cout << '\n';
//
//    // declare a double buffer with room for 4 doubles
//    StaticArray<double, 4> doubleArray;
//
//    for (int count{ 0 }; count < 4; ++count)
//        doubleArray[count] = 4.4 + 0.1 * count;
//
//    for (int count{ 0 }; count < 4; ++count)
//        std::cout << doubleArray[count] << ' ';
//
//    return 0;
//}

// int size is the non-type parameter in this case

/*
    19.3
*/
// We can use a function template specialization to create a specialized version of functions for specific types
// It's extremely simple: define the specialized function, replacing the template type with the specific type you wish to redefine the function for:
//template <>
//void Storage<double>::print()
//{
//    std::cout << std::scientific << m_value << '\n';
//}

// Making a template specialization for the destructor requires you to explicitly define the regular template destructor

/*
    19.4
*/
// You can also make template specialization for entire classes:
template <typename T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(int index) const
    {
        return m_array[index];
    }
};

#include <cstdint>

template <> // the following is a template class with no templated parameters
class Storage8<bool> // we're specializing Storage8 for bool
{
    // What follows is just standard class implementation details
private:
    std::uint8_t m_data{};

public:
    void set(int index, bool value)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        auto mask{ 1 << index };

        if (value)  // If we're setting a bit
            m_data |= mask;   // use bitwise-or to turn that bit on
        else  // if we're turning a bit off
            m_data &= ~mask;  // bitwise-and the inverse mask to turn that bit off
    }

    bool get(int index)
    {
        // Figure out which bit we're getting
        auto mask{ 1 << index };
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask);
    }
};


// It's worth noting that keeping the public interface between your template class and all of the specialization similar is generally a good idea, as it makes them easier to use
// However, it's not strictly necessary

/*
    19.5
*/
// Partial template specialization (optional reading)
// Partial template specialization can only be used with classes, not template functions

/*
    19.6
*/
// Partial template specialization for pointers (optional reading)
// 

#if 0
int main()
{
    return 0;
}
#endif