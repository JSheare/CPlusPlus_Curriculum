#include <iostream>

/*
    CHAPTER M R
*/

/*
    M.1
*/
// A smart pointer is a composition class that is designed to manage dynamically allocated memory and ensure that memory gets deleted when the smart pointer object goes out of scope
// Move semantics means the class will transfer ownership of the object rather than making a copy
// A smart pointer with move semantics:
template <typename T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

//int main()
//{
//	Auto_ptr2<Resource> res1(new Resource());
//	Auto_ptr2<Resource> res2; // Start as nullptr
//
//	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
//	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
//
//	res2 = res1; // res2 assumes ownership, res1 is set to null
//
//	std::cout << "Ownership transferred\n";
//
//	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
//	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
//
//	return 0;
//}

// This is dangerous to use and is broken because pointers that have been nullified can still be used, leading to errors
// C++11 rectifies this by defining the concept of a move and move semantics

/*
	M.2
*/
// C++11 introduces a new type of reference called an r-value reference
// An r-value reference is a reference that is designed to be initialized with an r-value (only)
// Created using a double ampersand

// R-value references have two properties that are useful:
// First, r-value references extend the lifespan of the object they are initialized to with the lifespan of the r-value reference
// Second, non-const r-value references allow you to modify the r-value!

// R-value references are most often used as function parameters. This is most useful for function overloads when you want to have different behavior for l-value and r-value args

// R-value reference variables are lvalues

/*
	M.3
*/
// C++ defined two new function in service of move semantics: a move constructor and a move assignment operator
// Whereas the goal of the copy constructor and copy assignment is to make a copy of one object to another, the goal of the move constructor and move assignment
//		is to move ownership of the resources from one object to another (which is typically much less expensive than making a copy)

// Defining a move constructor and move assignment work analogously to their copy counterparts. However, whereas the copy flavors of these functions take a const-lvalue reference
//		parameter, the move flavors use non-const r-value reference parameters

// The compiler will create an implicit move constructor and move assignment operator if all of the following are true:
// There are no user-declared copy constructors or copy assignment operators
// There are no user-declared move constructors or move assignment operators
// There is no user-declared destructor

// Do not implement move semantics using std::swap. This will lead to an infinite recursion

// The rule of five says that if the copy constructor, copy assignment, move constructor, move assignment, or destructor are defined or deleted, then each of those functions
//		should be defined or deleted

/*
	M.4
*/
// In C++11, std::move is a standard library function that casts (using static_cast) its argument into an r-value reference, so that move semantics can be invoked
// Thus, we can use std::move to cast an l-value into a type that will prefer being moved over being copied
// It's defined in the utility header

// Moved from objects will be in a valid, but possibly indeterminite state

// std::move can also be useful in sorting algorithms that do swaps, as std::move is more efficient

/*
	M.5
*/
// We can use the standard library function std::move_if_noexcept() to determine whether a move or a copy should be performed
// std::move_if_noexcept is a counterpart to std::move and is used in exactly the same way

// If the compiler can tell that an object passed as an argument to std::move_if_noexcept won’t throw an exception when it is move constructed 
//		(or if the object is move-only and has no copy constructor), then std::move_if_noexcept will perform identically to std::move() 
//				(and return the object converted to an r-value)
// Otherwise, std::move_if_noexcept will return a normal l-value reference to the object

/*
	M.6
*/
// Smart pointers should never be dynamically allocated themselves

// std::unique_ptr is a smart pointer that should be used to manage any dynamically allocated object that is not shared by multiple objects
// That is, std::unique_ptr should completely own the object it manages, not share that ownership with other classes
// It lives in the memory header

// Copy initialization and assignment are disabled with unique_ptr; you must use move semantics

// Remember that std::unique_ptr may not always be managing an object--either because it was created empty (using the default constructor or passing in a nullptr as the parameter),
//		or because the resource that it was managing got moved to another std::unique_ptr
// So before we use either of these operators, we should check whether the std::unique_ptr actually has a resource
// Fortunately, std::unique_ptr has a cast to bool that returns true if the std::unique_ptr is managing a resource

// Best practice: favor std::array, std::vector, or std::String over a smart pointer managing a fixed array, dynamic array, or C-style string

// C++14 comes with an additional function called std::make_unique() that will construct a unique_ptr that points to the type of the objects entered as arguments

// Best practice: use std::make_unique() instead of creating std::unique_ptr and using new yourself

// std::unique can safely be returned by value from a function

// If you want the function to take ownership of the contents of the pointer, pass the std::unique_ptr by value
// Note that you'll need to use std::move to actually pass the variable in
// However, most of the time, you won’t want the function to take ownership of the resource
// Although you can pass a std::unique_ptr by reference (which will allow the function to use the object without assuming ownership), 
//		you should only do so when the called function might alter or change the object being managed
// Instead, it’s better to just pass the resource itself (by pointer or reference, depending on whether null is a valid argument)
// This allows the function to remain agnostic of how the caller is managing its resources
// To get a raw resource pointer from a std::unique_ptr, you can use the get() member function

/*
	M.7
*/
// std::shared_ptr is designed to let multiple smart pointers manage a resource

// Best practice: always make a copy of an existing std::shared_ptr if you need more than one std::shared_ptr pointing to the same resource
// use std::make_shared() to make new shared smart pointers

// std::unique_ptr can be converted into std::shared_ptr

/*
	M.8
*/
// A circular reference is a series of references where each object references the next, and the last object references back to the first, causing a referential loop
// std::weak_ptr was created to solve the circular reference problem
// It is an oversver--it can observe and access the same object as a std::shared_ptr (or other std::weak_ptrs) but it is not considered an owner
// 

