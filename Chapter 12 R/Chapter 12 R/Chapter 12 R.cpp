#include <iostream>

/*
    CHAPTER 12 R
*/

/*
    12.1
*/
// Funciton pointers are pointers that point to functions 
// The syntax for creating a non-const function pointer is one of the ugliest things you will ever see in C++:
// int (*fcnPtr)();
// To make a const function pointer, the const goes after the asterisk:
// int (*const fcnPtr)();

// Function pointers can be initialized with a function (and non-const function pointers can be assigned a function)
// Like pointers to variables, we can also use &foo to get a function pointer to foo
// int (*fcnPtr)() { &foo }; // fcnPtr points to function foo
// fcnPtr = &goo; // fcnPtr now points to function goo

// Note that the type (parameters and return type) of the function pointer must match the type of the function. Ex:
// // function prototypes
// int foo();
// double goo();
// int hoo(int x);
// 
// // function pointer initializers
// int (*fcnPtr1)() { &foo };    // okay
// int (*fcnPtr2)() { &goo };    // wrong -- return types don't match!
// double (*fcnPtr4)() { &goo }; // okay
// fcnPtr1 = &hoo;              // wrong -- fcnPtr1 has no parameters, but hoo() does
// int (*fcnPtr3)(int) { &hoo }; // okay

// Function pointers can also be initialized or assigned the value nullptr

// You can call functions via function pointers
// (*fcnPtr)(5); 
// Or via implicit dereference
// fcnPtr(5)

// Note: default parameters won't work for function called through function pointers

// One of the most useful things to do with function pointers is pass a function as an argument to another function
// Functions used as arguments to another function are sometimes called callback functions 
// void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int) = ascending);

// You can make the function pointer syntax prettier with aliases
// using ValidateFunction = bool(*)(int, int);
// bool validate(int x, int y, bool (*fcnPtr)(int, int)); // ugly
// bool validate(int x, int y, ValidateFunction pfcn) // clean

// An alternate method of defining and storing function pointers is to use std::function, which is part of the standard library <functional> header
// To define a function pointer using this method, declare a std::function object like so
// #include <functional>
// bool validate(int x, int y, std::function<bool(int, int)> fcn); // std::function method that returns a bool and takes two int parameters
// On it's own
// std::function<int()> fcnPtr{ &foo }; // declare function pointer that returns an int and takes no parameters
// Note that std::function only allows calling the function via implicit dereference

// The auto variable can also be used to infer the type of function pointer
// auto fcnPtr{ &foo };

/*
    12.2
*/
// The heap memory segment (also known as the "free store") keeps track of memory used for dynamic memory allocation
// In C++, when you use the new operator to allocate memory, this memory is allocated in the application's heap segment
// The address of this memory is passed back by operator new, and can then be stored in a pointer
// It's worth knowing that sequential memory requests may not result in sequential memory addressed being allocated!
// When a dynamically allocated variable is deleted, the memory is "returned" to the heap and can then be reassigned as future allocation requests are received 
// The heap has advantages and disadvantages
/*
    * Allocating memory on the heap is comparatively slow
    * Allocated memory stays allocated until it is specifically deallocated (beware memory leaks) or the application ends (at which point the OS should clean it up)
    * Dynamically allocated memory must be accessed through a pointer. Dereferencing a pointer is slower than accessing a variable directly
    * Because the heap is a big pool of memory, large arrays, structures, or classes can be allocated here
*/

// The call stack (usually referred to as "the stack") has a much more interesting role to play
// It keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution
//      and handles all function parameters and local variables
// Implemented as an actual stack data structure

// The call stack segment holds the memory used for the call stack
// When the application starts, the main() function is pushed on the call stack by the operating system. Then the program begins executing
// When a funciton call is encountered, the function is pushed onto the call stack
// When the current function ends, the function is popped off the call stack (sometimes called unwinding)

// The items we're pushing and popping on the stack are called stack frames
// The "marker" is a register (a small piece of memory in the CPU) known as the stack pointer. The stack pointer keeps track of where the top of the call stack currently is

// Stack overflow happens when all the memory in the stack has been allocated

// The stack has advantages and disadvantages
/*
    * Allocating memory on the stack is comparatively fast
    * Memory allocated on the stack stays in scope as long as it is on the stack. It is destroyed when it is popped off the stack
    * All memory allocated on the stack is known at compile time. Consequently, this memory can be accessed directly through a variable
    * Because the stack is relatively small, it is generally not a good idea to do anything that eats up lots of stack space
*/

/*
    12.3
*/
// In the context of std::vector, length is how many elements are being used in the array, whereas capacity is how many elements were allocated in memory
// Array subscripts and at() are based on length, not capacity

// std::vector can be used as a stack
// To do this, we can use 3 functions that match our key stack operations:
// push_back()
// back()
// pop_back()
// These stack-based functions will resize the std::vector if necessary
// Because resizing the vector is expensive, we can tell the vector to allocate a certain amount of capacity up front using the reserve() function

// When a vector is resized, it may allocate more capacity than is needed to provide some "breathing room" for additional elements and to minimize the number of resize operations

/*
    12.4
*/
// A recursive function in C++ is a function that calls itself
// A recursive termination is a condition that, when met, will cause the recursive function to stop calling itself. You must include one
// Inputs for which an algorithm trivially produces an output is called a base case. These act as termination conditions for the algorithm
// Memoization can be used to cache the results of an expensive function call so the result can be returned when the same input occurs again

// Iterative functions are almost always more efficient than their recursive counterparts. This is because every time you call a function there is some amount of overhead
// Sometimes, though, the recursive implementation is so much cleaner and easier to follow that incurring a little extra overhead is worth it

// In general, recursion is a good choice when most of the following are true:
// The recursive code is much simpler to implement
// The recursion depth can be limited (e.g. there’s no way to provide an input that will cause it to recurse down 100,000 levels)
// The iterative version of the algorithm requires managing a stack of data
// This isn’t a performance-critical section of code

// Best practice: generally favor iteration over recursionm except when recursion really makes sense

/*
    12.5
*/
// Command line arguments are optional string arguments that are passed by the operating system to the program when it is launched
// To access command line arguments from within the program, we use a different form of main:
// int main(int argc, char* argv[])
// argc is an integer parameter containing a count of the number of arguments passed into the program
// argv is where the actual argument values are stored

// Command line arguments are always passed as strings, even if the value provided is numeric in nature
// To use the command line argument as a number, you must convert it:
// std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]
// 
// int myint{};
// if (!(convert >> myint)) // do the conversion
// myint = 0; // if conversion fails, set myint to a default value
// std::stringstream comes from <sstream>

/*
    12.6
*/
// C++ provides a special specifier known as ellipsis that allow us to pass a variable number of parameters to a function:
// return_type function_name(argument_list, ...)
// The ellipsis must always be the last parameter in the function

// Why ellipsis are dangerous: type checking is suspended

// Why ellipsis are dangerous: ellipsis don't know how many parameters were passed

// Use a decoder string 

/*
    12.7
*/
// A lambda expression allows us to define and anonymous function inside another function
// lambda syntax:
// [captureClause](parameters) -> returnType
// {
//     statements;
// }

// Best practice: following the best practice of defining things in the smallest scope and closest to first use, lambdas are preferred over normal functions when
//      we need a trivial, one off function to pass as an argument to some other function

// You can also store a lambda in a named variable and pass it using the name
// // Good: Instead, we can store the lambda in a named variable and pass it to the function.
// auto isEven{
//   [](int i)
//   {
//     return ((i % 2) == 0);
//   }
// };

// Best practice: when storing a lambda in a variable, use auto as the variable's type

// Best practice: when passing a lambda to a function, use auto as the parameter's type if C++20 capable, otherwise use std::function

// Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas

/*
    12.8
*/
// By default, lambdas can only access specific kinds of identifiers: global identifiers, entities that are known at compile time, and entities with static storage duration
// The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that it normall would not have access to
// All we need to do is list the entiteis we want to access from within the lambda as part of the capture clause
// It goes inside the brackets

// When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda
// By default, variables are captured by const value
// To allow modificiations of variables that were captured by value, we can mark the lambda as mutable:
// [ammo]() mutable {
// The mutable keyword in this context removes the const qualification from all variables captured by value
// Variables can also be captured by reference using &
// Multiple variables can be captured by separating them with a comma

// A default capture captures all variables that are mentioned in the lambda. Variables not mentioned in the lambda are not captured if a default capture is used
// [=](int knownArea) capture all by value
// [&](int knownArea) capture all by reference

// Best practice: only initialize variables in the capture if their value is short and their type is obvious
//      otherwise it's best to define the variable outside of the lambda and capture it

int main()
{
    return 0;
}

