#include <iostream>
/*
    CHAPTER 21 R
*/

/*
    21.1
*/
// The standard library

/*
    21.2
*/
// The STL contains many different containr classes that can be used in different situations
// Generally speaking, the container classes fall into three basic categories: Sequence containters, Associative containers, and Container adapters

// Sequence containers are container classes that maintain the ordering of elements in the container
// A defining characteristic of sequence containers is that you can choose where to insert your element by position
// As of C++11, the STL contains 6 sequence containers: std::vector, std:deque, std::array, std::forward_list, and std::basic_string
// deque is a double-ended queue class
// list is a doubly-linked list

// Associative containers are containers that automatically sort their inputs when those inputs are inserted into the container
// By default, associative containers compare elements using operator<
// A set is a container that stores unique elements, with duplicate elements disallowed. The elements are sorted according to their values
// A multiset is a set where duplicate elements are allowed
// A map (also called an associative array) is a set where each element is a pair, called a key/value pair
// A multimap (also called a dictionary) is a map that allows duplicate keys

// Container adapters are special predefined containers that are adapted to specific uses
// Stacks
// Queues
// Priority queues

/*
    21.3
*/
// An iterator is an object that can traverse (iterate over) a container class without the user having to know how the container is implemented

// An iterator is best visualized as a pointer to a given element in the container, with a set of overloaded operators to provide a set of well-defined functions:
// Operator* -- Dereferencing the iterator returns the element that the iterator is currently pointing at
// Operator++ -- Moves the iterator to the next element in the container. Most iterators also provide Operator-- to move to the previous element
// Operator== and Operator!= -- Basic comparison operators to determine if two iterators point to the same element
//      To compare the values that two iterators are pointing at, dereference the iterators first, and then use a comparison operator
// Operator= -- Assign the iterator to a new position (typically the start or end of the container’s elements)
//      To assign the value of the element the iterator is pointing at, dereference the iterator first, then use the assign operator

// Each container includes four basic member functions for use with Operator=:
// begin() returns an iterator representing the beginning of the elements in the container
// end() returns an iterator representing the element just past the end of the elements
// cbegin() returns a const (read-only) iterator representing the beginning of the elements in the container
// cend() returns a const (read-only) iterator representing the element just past the end of the elements

// Finally, all containers provide at least two types of iterators:
// container::iterator provides a read/write iterator
// container::const_iterator provides a read-only iterator

/*
    21.4
*/
// In addition to container classes and iterators, STL also provides a number of generic algorithms for working with the elements of the container classes
// Note that algorithms are implemented as functions that operate using iterators
// This means that each algorithm only needs to be implemented once, and it will generally automatically work for all containers that provides a set of iterators 
//      (including your custom container classes)

// The std::min_element and std::max_element algorithms find the min and max element in a container class
// std::iota generates a contiguous series of values

// The std::find() algorithm finds a value within a container

// The std::sort algorithm sorts the items in a container
// You can pass your own custom comparison functions to it
// Doesn't work on list container classes

# if 0
int main()
{
    return 0;
}
#endif

