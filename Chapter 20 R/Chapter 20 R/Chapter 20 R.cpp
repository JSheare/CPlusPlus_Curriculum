#include <iostream>

/*
    CHAPTER 20 R
*/

/*
    20.1
*/
// Exception handling

/*
    20.2
*/
// In C++, a throw statement is used to signal that an exception or error case has occured
// To use a throw statement, simply use the throw keyword, followed by a value of any data type you wish to use to signal that an error has occured
// Typically, this value will be an error code, a description of the problem, or a custom exception class

// In C++, we use the try keyword to define a block of statements (called a try block)
// The try block acts as an observer, looking for any exceptions that are thrown by any of the statements within the try block

// The catch keyword is used to define a block of code (called a catch block) that handles exceptions for a single data type

// A try block must have at least one catch block immediately following it, but may have multiple catch blocks listed in sequence

// Catch function parameters work just like function parameters, with the parameter being available within the subsequent catch block
// Exceptions of fundamental types can be caught by value, but exceptions of non-fundamental types should be caught by constant reference

// If an exception is routed to a catch block, it is considered "handled" even if the catch block is empty
// However, typically you'll want your catch blocks to do something useful
// There are four common things that catch blocks do when they catch an exception:
// They may print an error and then allow the function to proceed
// They may return a value or error code back to the caller
// They may throw another exception
// A catch block in main() may be used to catch fatal errors and terminate the program in a clean way

/*
    20.3
*/
// When an exception is thrown, the program first looks to see if the exception can be handled immediately inside the current function
// If the current function can handle the exception, it does so

// If not, the program next checks whether the function's caller can handle the exception
// In order for the function's caller to handle the exception, the call to the current function must be inside a try block, and a matching catch block must be associated

// If no match is found, this process is repeated again, an so on up the call stack
// This process of checking each function up the call stack continues until either a handler is found, or all of the functions on the call stack have been checked and 
//      no handler can be found
// If a matching exception handler is found, then execution jumps from a point where the exception is thrown to the top of the matching catch block
// This requires unwinding the stack as many times as necessary to make the function handling the exception the top function on the call stack

// Unwinding the stack destroys local variables in the functions that are unwound

/*
    20.4
*/
// The call stack may or may not be unwound if an exception is unhandled 
// If the stack is not unwound, local variables will not be destroyed, which may cause problems if those variables have non-trivial destructors 
// Unhandled exceptions are generally something you want to avoid

// Fortunately, C++ provides us with a mechanism to catch all types of exceptions. This is known as a catch-all handler
// It works just like a normal catch block, except that instead of using a specific type to catch, it uses the ellipses operator(...)
// The catch-all handler must be placed last in the catch block chain. This is to ensure that exceptions can be caught by exception handlers tailored to specific data types
//      if these handlers exist

// Best practice: If your program uses exceptions, consider using a catch-all handler in main, to help ensure orderly behavior when an unhandled exception occurs
//      Also consider disabling the catch-all handler for debug builds, to make it easier to identify how unhandled exceptions are occuring

/*
    20.5
*/
// Exceptions can also be thrown in class member functions

// Exceptions can also be useful when a class constructor fails 
// When an exception is thrown by the constructor, the object's construction is aborted and all class members are destructed as per usual
// However, note that the destructor is not called

// An exception class is just a normal class that is designed specifically to be thrown as an exception
// Catch these by reference
// Exception handlers for a parent class will also match to any child classes
// Rule: handlers for derived exception classes should be listed before those for base classes

// All exceptions thrown by standard library code is of type std::exception or inherited from it, making std library exceptions very easy to catch
// std::exception has a virtual member function called what() that returns a C-style string description of the exception

// Nothing throws std::exception directly, and neither should you
// But feel free to throw any of it's children
// You can also, of course, derive your own exceptions from it

// Exception classes should be copyable

/*
    20.6
*/
// To rethrow exceptions from within the catch block, simply use the throw keyword with no associated variable/literal 

/*
    20.7
*/
// Function try blocks are designed to allow you to establish an exception handler around the body of an entire function, rather than around a block of code:
class A
{
private:
	int m_x;
public:
	A(int x) : m_x{ x }
	{
		if (x <= 0)
			throw 1; // Exception thrown here
	}
};

class B : public A
{
public:
	B(int x) try : A{ x } // note addition of try keyword here
	{
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
		// Exceptions from member initializer list or constructor body are caught here

		std::cerr << "Exception caught\n";

		throw; // rethrow the existing exception
	}
};

int main()
{
	try
	{
		B b{ 0 };
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}

// A function-level catch block for a constructor must either throw a new exception or rethrow the existing exception, they are not allowed to resolve exceptions
// Return statements are also not allowed, and reaching the end of the catch block will implicitly rethrow

// A function-level catch block for a destructor can throw, rethrow, or resolve the current exception via a return statement
// Reaching the end of the block will implicitly rethrow

// A function-level catch block for other functions can throw, rethrow, or resolve the current exception via a return statement
// Reaching the end of the catch block will implicitly resolve the exception for non-value (void) returning functions and produce undefined behavior for value-returnign functions!

// Best practice: avoid letting control reach the end of a function-level catch block. Instead, explicitly throw, rethrow, or return

// Function try blocks can catch both base and current class exceptions 

/*
	20.8
*/
// Downsides to exceptions
// They don't clean up after themselves. You need to do the hard work here
// Never throw exceptions in a destructor, otherwise the compiler will get confused and just terminate the program immediately 
// Exceptions come with some small performance overhead

/*
	20.9
*/
// Exception specifications are a language mechanism that was originally designed to document what kind of exceptions a function might throw as part of a function specification
// While most of the exception specifications have now been deprecated or removed, one useful exception specification was added as a replacement

// In C++, all function are classified as either non-throwing or potentially-throwing functions
// A non-throwing function is one that promises not ot throw exceptions that are visible to the caller
// A potentially-throwing function may throw exceptions that are visible to the caller

// To define a function as non-throwing, we can use the noexcept specifier
// To do so, we use the nopexcept keyword in the function declaration, placed to the right of the function parameter list

// Note that noexcept doesn’t actually prevent the function from throwing exceptions or calling other functions that are potentially throwing
// This is allowed so long as the noexcept function catches and handles those exceptions internally, and those exceptions do not exit the noexcept function
// If an unhandled exception would exit a noexcept function, std::terminate will be called, and if std::terminate is called from inside a noexcept function, 
//		stack unwinding may or may not occur

// noexcept cannot be used to change function signature

// noexcept has a optional boolean parameter noexcept(true) and noexcept(false), false means it's a potentially-throwing function
// This is mostly used in template functions 

// The noexcept operator also exists
// It can be fed an expression and it will tell you with a bool whether or not the compiler thinks the expression will throw an exception
// The operator can be used to conditionally execute code depending on whether it is potentially throwing or not
// This is required to fulfill certain exceptions safety guarantees
// Here are the types of safety guarantees:
/*
	* No guarantee -- There are no guarantees about what will happen if an exception is thrown (e.g. a class may be left in an unusable state)
	* Basic guarantee -- If an exception is thrown, no memory will be leaked and the object is still usable, but the program may be left in a modified state
	* Strong guarantee -- If an exception is thrown, no memory will be leaked and the program state will not be changed. This means the function must either completely 
	*		succeed or have no side effects if it fails.This is easy if the failure happens before anything is modified in the first place, but can also be achieved by rolling back 
	*			any changes so the program is returned to the pre-failure state
	* No throw / No fail -- The function will always succeed (no-fail) or fail without throwing an exception (no-throw)
*/

// Best practice: make constructors and overloaded assignment operators noexcept when you can
//		Use noexcept on other functions to express a no-fail or no-throw guarantee

// Best practice: if you are uncertain whether a function should have a no-fail/no-throw guarantee, err on the side of caution and do not mark it with noexcept
