#include <iostream>

/*
	CHAPTER 11 R
*/

/*
	11.1
*/
// An array is an aggregate data type that lets us access many variables of the same type through a single identifier
// int testScore[30]{};  // allocate 30 integer variablse in a fixed array
// In an array variable declaration, we use square brackets to tell the compiler both that this is an array variable (instead of a normal variable), as well as
//		how many variables to allocate (called the array length)
// A fixed array is an array where the length is known at compile time

// Use the subscript operator to access array entries
// testScore[0]  // first entry

// Arrays can also be made from structs

// Arrays can even be made from arrays

// Array subscripts must always be an integral type

// When declaring a fixed array, the length of the array (between the square brackets) must be a compile time constant 
// You can use things like int literals or constexpr, for example
// Non-const variables or runtime constants cannot be used

/*
	11.2
*/
// You can use an initializer list to initialize entire arrays:
// int prime[5]{2, 3, 5, 7, 11};
// If there are less initializers in the list than the array can hold, the remaining elements are zero initialized

// Best practice: explicitly initialize your arrays (even when the element type is self-initializing) 

// If you are initializing a fixed array of elements using an initializer list, the compiler can figure out hte length of the array for you, and you can 
//		omit explicitly declaring the length of the array

// You can use enums (not enum classes) to give array subscripts names

// When array is given as a function argument, the *actual* array is passed (not a copy). This means that functions can change array values
// If you want to ensure that a function does not modify the array elements you passed into it, you can make the array const

// The std::size function from the <iterator> header can be used to determine the length of arrays (C++17 or greater)
// You can also use sizeof()
// But for sizeof() you need to do something like this: sizeof(array) / sizeof(array[0]) to get the size by element
// This will not work, however, for arrays that have been passed into functions

// When using an index that's larger than the array range or a negative index, C++ will actually insert the value into memory wherever that index would've been

// Best practice: when using arrays, ensure that your indices are valid for the range of your array!

/*
	11.3
*/
// When a loop is used to access each array element in turn, this is often called iterating through the array
// When using loops with arrays, always double check  your loop conditions to make sure you do not introduce off-by-one errors

/*
	11.4
*/
// Array sorting with selection sort
// To swap two elements, we can use the std::swap() function from the <utility> header
// The C++ standard library includes a sorting function named std::sort in the <algorithm> header

/*
	11.5
*/
// An array of arrays is called a multidimensional array
// int array[3][5]
// It's easiest to initialize multidimensional arrays with nested braces:
//int array[3][5]
//{
//  { 1, 2, 3, 4, 5 }, // row 0
//  { 6, 7, 8, 9, 10 }, // row 1
//  { 11, 12, 13, 14, 15 } // row 2
//};
// Two-dimensional arrays with initializer lists can omit (only) the leftmost length specification

/*
	11.6
*/
// A C-style string is simply an array of characters that uses a null terminator
// A null terminator is a special character ('\0', ascii code 0) used to indicate the end of the string
// A C-style string is also sometimes called a null-terminated string
// You can explicity declare a C-style string like this:
// char myString[]{"string"};
// C-style strings follow all the same rules as arrays
// It's okay for the array to be larger than the string it holds

// Use std::cin.getline() when using C-style strings with std::cin

// C++ provides many functions to manipulate C-style strings as part of the <cstring> header
// strcpy() allows you to copy a string to another string
// Many programmers recommend using strncpy() instead, which allows you to specify the size of the buffer, and ensures overflow doesn't occur
// strlen() returns the length of the C-style string without the null terminator
// See https://www.learncpp.com/cpp-tutorial/c-style-strings/ for a longer list

// Rule: use std::string or std::string_view instead of C-style strings

/*
	11.7
*/
// In all but two cases, when a fixed array is used in an expression, the fixed array will decay (be implicitly converted) into a pointer that points to the first element
// A pointer to an array (of type int*, for example) would have a value corresponding to the address of the first element in the array
// We can initialize a pointer to point at the array:
// int* ptr{ array };

// Differences between pointers and fixed-length arrays
// When used on a fixed array, sizeof returns the size of the entire array. When used on a pointer, sizeof returns the size of the pointer (in bytes)
// The second difference occurs when using the address-of operator (&). Taking the address of a pointer yields the memory address of the pointer variable. 
//		Taking the address of the array returns a pointer to the entire array. This pointer also points to the first element of the array, but the type information is different.
//			(It's unlikely you'll ever need to use this)

// When passing an array as an argument to a function, a fixed array decays into a pointer, and the pointer is passed to the function

// Best practice: favor the pointer (*) syntax over the array syntax for array function parameters

// It is worth noting that arrays that are part of structs or classes do not decay when the whole struct or class is passed to a function
// This yields a useful way to prevent decay if desired

// Arrays passed by reference will also not decay

/*
	11.8
*/
// The C++ language allows you to perform integer addition or subtraction operations on pointers
// If ptr points to an integer, ptr + 1 is the address of the next integer in memory after ptr
// Similar wiht ptr - 1
// Note that these operations return the next memory address *of the same type*
// If ptr points to an integer (assuming 4 bytes), ptr + 3 means 3 integers (12 bytes) after ptr. If ptr points to a char, which is always 1 byte,
//		ptr + 3 means 3 chars (3 bytes) after ptr

// When calculating the result of a pointer arithmetic expression, the compiler always multiplies the integer operand by the size of the object being pointed to
// This is called scaling

// Arrays are laid out sequentially in memory
// Generalizing, array[n] is the same as *(array + n), where n is an integer

/*
	11.9
*/
// C-style string symbolic constants
// C++ supports a way to create C-style string symbolic constants using pointers:
// const char* myName{ "Alex" }; // pointer to string literal
// The compiler handles this a little differently than the fixed array method
// The exact behavior is implementation-defined, but what usually happens is that the compiler places the string "Alex\0" into read-only memory somewhere,
//		and then sets the pointer to point to it
// Because string literals can't be changed, the string must be const
// These have a static duration

/*
	11.10
*/
// C++ supports three basic types of memory allocation:
/*
	* Static memory allocation happens for static and global variables. They die when the program is finished executing
	* Automatic memory allocation happens for function parameters and local variables. They die when they go out of scope
	* Dynamic memory allocation
*/

// Both static and automatic allocation have two things in common:
// The size of the variable / array must be known at compile time
// Memory allocation and deallocation happens automatically (when the variable is inistantiated/destroyed)
// Most of the time this is fine, but you will ocassionally come across situations where one or both of these constraints cause problems

// Most variables are allocated a portion in memory called the stack. The amount of stack memory for a program is generally quite small
// if you exceed this number, stack overflow will result, and the operating system will probably close down the program 

// Dynamic memory allocation is a way for running programs to request memory from the operating system when needed
// This memory does not come from the program's limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating 
//		system called the heap
// The heap is usually gigabytes 

// To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator:
// new int; // dynamically allocate an integer (and discard the result)
// The new operator creates the object using that memory, and hten returns a pointer containing the address of the memory that has been allocated
// Most often, we'll assign the return value to our own pointer variable so we can accedd the allocated memory later
// int* ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later
// We can then dereference the pointer to access the memory
// *ptr = 7; // assign value of 7 to allocated memory
// Note that accessing heap-allocated objects is generally slower than accessing stack-allocated objects

// Unlike static or automatic memory, the program itself is responsible for requesting and disposing of dynamically allocated memory

// When you dynamically allocate a variable, you can also initialize it via direct intialization or uniform initialization
// int* ptr1{ new int (5) }; // use direct initialization
// int* ptr2{ new int { 6 } }; // use uniform initialization

// When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse
// For single variables, this is done via the scalar (non-array) form of the delete operator
// assume ptr has previously been allocated with operator new
// delete ptr; // return the memory pointed to by ptr to the operating system
// ptr = nullptr; // set ptr to be a null pointer

// Best practice: set deleted pointers to nullptr (like in the example above) unless they are going out of scope immediately afterward

// By default, if new fails, a bad_alloc exception is thrown
// To get around this (without handling the exception), there's an alternate form of new that can be used instead to tell new to return a null pointer if memory can't be allocated
// This is done by adding the constant std:nothrow between the new keyword and the allocation type:
// int* value { new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails
// Note that if you then attempt to dereference this pointer, undefined behavior will result
// Consequently, the best practice is to check all memory requests to ensure they actually succeeded before using the allocated memory

// Best practice: deleting a null pointer is okay, and does nothing. There is not need to conditionalize your delete statements

// Pointers used to hold dynamically allocated memory addresses follow the normal scoping rules for local variables
// Memory leaks happend when your program loses the address of some bit of dynamically allocated memory before giving it back to the operating system

/*
	11.11
*/
// Unlike a fixed array, where the array size must be fixed at compile time, dynamically allocating an array allows us to choose an array length at runtime
// This means that our length does not need to be constexpr

// To allocate an array dynamically, we use the array form of new and delete (often called new[] and delete[])
// int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!
// array[0] = 5; // set element 0 to value 5
// delete[] array; // use array delete to deallocate array

// Dynamic arrays are almost identical to fixed arrays

// You can initialize dynamic arrays with initializer lists

/*
	11.12
*/
// for-each loops (also called range-based for-loops) can be used in cases where we want to iterate through every element in an array (or other list-type structure)
// This is the syntax:
// for (element_declaration : array)
// statement;
// When this statement is encountered, the loop will iterate through each element in array, assigning the value of the current array element to the variable declared 
//			in element_declaration
// For best results, element_declaration should have the same type as the array elements, otherwise type conversion will occur
// Just use auto in the element declaration

// During the loop, each array element is copied into the element declaration variable, and this can be expensive
// To get around this, we can make element declaration a reference:
// std::string array[]{ "peter", "likes", "frozen", "yogurt" };
// for (auto& element : array) // The ampersand makes element a reference to the actual array element, preventing a copy from being made
// {
// 	std::cout << element << ' ';
// }

// Best practice: in for-each loops element declarations, if your elements are non-fundamental types, use references or const references for performance reasons

// For-each loops don't only work with fixed arrays, they work with many kinds of list-like structures
// including vectors, linked lists, trees, and maps

// For-each doesn't work with pointers to an array

// As of C++20 you can also include an init-statement in a for-each loop, right before the element declaration
// Good way to make index tracker or counter if you need it

/*
	11.13
*/
// The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects of any data type
// However, because the void pointer does not know what type of object it it pointing to, dereferencing a void pointer is illegal
// Instead, the void pointer must first be cast to another pointer type before the dereference can be performed

// Void pointers can be set to a null value

// It is not possible to do pointer arithmetic on a void pointer

// Avoid using void pointers

/*
	11.14
*/
// A pointer to a pointer is declared using to asterisks
// int** ptrptr; 
// Works like a normal pointer

// Pointers to pointers have few uses. The most common use is to dynamically allocate an array of pointers
// int** array { new int*[10] }; // allocate an array of 10 int pointers
// This works just like a standard dynamically allocated array, except the array elements are of type “pointer to integer” instead of integer

// Another common use for pointers to pointers is to facilitate dynamically allocated multidimensional arrays

// Stay the hell away from these

/*
	11.15
*/
// std::array provides fixed array functionality that won't decay when passed into a function
// It's defined in the <array> header
// It can be declared like this
// std::array<int, 3> myArray; // declare an integer array with length 3
// The length of std::array must be known at compile time
// Can be initialized using lists or list initialization
// Since C++17, you can omit type and size if you wish, but only when you omit both together, and only if the array is explicitly initialized

// std::array supports a second form of array element access (the at() function) that does (runtime) bounds checking
// std::array myArray { 9, 7, 5, 3, 1 };
// myArray.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
// myArray.at(9) = 10; // array element 9 is invalid, will throw a runtime error

// Because std::array doesn't decay to a pointer when passed to a function, the size() function will work even if you call it from within a function

// Best practice: always pass std::array by reference or const reference

// We recommend using std::Array over built-in fixed arrays for any non-trivial array use

/*
	11.16
*/
// std::vector provides dynamic array functionality that handles its own memory management
// This means you can create arrays that have their own length set at run-time, without having to explicitly allocate and deallocate memory using new and delete
// std::vector lives in the <vector> header

// Declaring a std::vector is simple:
// // no need to specify length at the declaration
// std::vector<int> v;
// std::vector<int> v2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize vector (before C++11)
// std::vector<int> v3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize vector
//
// // as with std::array, the type can be omitted since C++17
// std::vector v4 { 9, 7, 5, 3, 1 }; // deduced to std::vector<int>

// Just like std::array, accessing array elements can be done via the [] operator (which does no bounds checking) or the at() function (which does bounds checking):
// v[6] = 2; // no bounds checking
// v.at(7) = 3; // does bounds checking

// As of C++11, you can also assign values to a std::Vector using an initializer-list 
// v = { 0, 1, 2, 3, 4 }; // okay, vector length is now 5
// v = { 9, 8, 7 }; // okay, vector length is now 3
// The vector will self-resize to match the number of elements provided

// When a vector variable goes out of scope, it automatically deallocates the memory it controls

// You can get the size of a std::vector with .size()
// The value returned will be an unsigned integer

// std::vectors can be resized with .resize()
// Doing this preserves current values while initializing new elements to zero

// We recommend using std::vector in most cases where dynamic arrays are needed

/*
	11.17
*/
// An iterator is an object designed to traverse through a container

// Pointers can be used as iterators
// Iterating is such a common operation that all standard library containers offer direct support for iteration
// Instead of calculating our own begin and end points, we can simply ask the container for the begin and end points via the functions begin() and end()
// The iterator header also contains two generic functions (Std::begin and std::end) that can be used

// Much like pointers and references, iterators can be left "dangling" if the elements being iterated over change address or are destroyed
// When this happens, we say the iterator has been invalidated
// Accessing an invalidated iterator produces undefined behavior

/*
	11.18
*/
// The functionality provided in the algorithms library generally fall into one of three categories:
// Inspectors - used to view (but not modify) data in a container. Ex: searching and counting
// Mutators - used to modify data in a container. Ex: sorting and shuffling 
// Facilitators - used to generate a result based on values of the data members

// Best practice: before using a particular algorithm, make sure performance and execution order guarantees work for your particular use case

// Best practice: Favor using functions from the algorithms library over writing your own functionality to do the same thing

# if 0
int main()
{
	return 0;
}
#endif 

