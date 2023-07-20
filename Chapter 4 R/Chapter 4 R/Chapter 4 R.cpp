#include <iostream>

/*
	CHAPTER 4 R
*/

/*
	4.1
*/
// The smallest unit of memory is a binary digit (also known as a bit), which can hold a value of either 1 or 0
// Memory is organized into sequential units called memory addressed
// The number of memory addresses is limited, and the need to access data bit by bit is rare. 
// Instead, each memory address holds 1 byte of data.
// A byte is a group of bits that are operated on as a unit. The modern standard is that a byte is composed of 8 sequential bits

// Because all data on a computer is just a sequence of bits, we use a data type to tell the compiler how to interpret the contents of memory in some meaningful way
// See https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/ for a full list of primitive data types supported by C++

/*
	4.2
*/
// void is what's known as an incomplete type -- they don't contain enough information for the compiler to determine their size. They cannot be instantiated

/*
	4.3
*/
// An object with n bits can hold 2^n unique values
// The size of each type is implementation specific, but the following are true pretty much everywhere:
/*
	* A byte is 8 bits
	* memory is byte addressable, so the smallest object is 1 byte
	* Floating point support is IEEE-754 compliant 
	* We're on 32 or 64 bit architecture
*/

// The sizeof operator is a unary operator that takes either a type or a variable, and returns its size in bytes

/*
    4.4
*/
// Integers are signed by default in C++
// Here's how you define them:
//short s;      // prefer "short" instead of "short int"
//int i;
//long l;       // prefer "long" instead of "long int"
//long long ll; // prefer "long long" instead of "long long int"
// an n-bit signed variable has a range of -(2^(n-1)) to 2^(n-1)-1
// Integer overflow occurs when we try to store a value that is outside the range of the type. 
// In such a case, data is lost because the object doesn't have enough memory to store everything 
// In the case of signed integers, which bits are lost is not well-defined, thus signed interger overflow leads to undefined behavior

/*
    4.5
*/
// To define unsigned integers, we use the unsigned keyword:
// unsigned short us;
// unsigned int ui;
// unsigned long ul;
// unsigned long long ull;
// range of 0 to 255
// If an unsigned value is out of range, it is divided by one greater than the largest number of that type, and only the remainder kept
// This is called modulo wraparound (for obvious reasons)

// Unsigned integers should generally be avoided for the following reasons:
// It's easier to overflow unsigned integers because the bottom of the range is 0
// If a mathematical operation has one signed integer and one unsigned integer, the signed integer will usually be converted to an unsigned integer

// Best practice: favor signed numbers over unsigned numbers for holding quantities and mathematical operations. Avoid mixing signed and unsigned numbers

// Unsigned numbers are still useful and even necessary in some cases
// Good for bit manipulation 
// Good for cases where the wraparound behavior is well-defined
// Necessary for proper array indexing
// Sometimes unavoidable on embedded systems for performance reasons

/*
    4.6
*/
// Fixed width integers have a set bit length regardless of compiler implementation 
// They can be accessed by #including <cstdint>
// These are not supported on all architectures, but usually are
// They may also be slower on certain architectures

// C++ also guarantees two alternative sets of integers that are guaranteed to be defined
// fast types provide the fastest signed/unsigned integer type with a width of at least # bits (where # = 8, 16, 32, 64)
// least types provide the smallest signed/unsigned integer type with at least # bits (...)
// Basically no one uses these because they're inconsistent from machine to machine

// By definition, the largest object creatable on a system is equal to the largest value an object of std::size_t can hold
// For example, if std::size_t is 4 bytes wide, the largest object creatable on your system can’t be larger than 4,294,967,295 bytes, 
//      because 4,294,967,295 is the largest number a 4-byte unsigned integer can store.
// This is the absolute upper limit. It's likely smaller in reality depending on the compiler

/*
    4.7
*/
// Scientific notation in C++ follows the same e for exponent format as every other programming language
// 1.2 x 10^4 = 1.2e4

/*
    4.8
*/
// There are three different floating point data types in C++: float, double, and long double
// According to IEE standards, floats are 4 bytes, doubles are 8, and long doubles can be anywhere from 8 to 16
// Floating point data types are always signed

// Best practice: always make sure the type of your literals matches the type of variables they're being assigned to or used to initialize. Otherwise unnecessary conversions will result

// When outputting floating point numbers, std::cout has a default precision of 6 significant digits
// Floats have between 6 and 9 digits of precision
// doubles have between 15 and 18
// long double has a minimum precision of 15, 18, or 33 significant digits depending on how many bytes it occupies
// we can override std::cout's default using std:steprecision()

// Best practice: favor double over float unless space is at a premium. Otherwise beware rounding errors!

// NaN and Inf exist in C++

/*
    4.9
*/
// Bools 
// true is stored as 1 and false as 0
// To print bools as true or false instead of 1 or 0 use std::boolalpha
// To allow std::cin to accept "false" and "true" as inputs, the std::boolalpha option has to be enabled

// Functions that return bools are often named starting with the word is (i.e. isTrue or similar)

/*
    4.10
*/
// if (condition) true_statement;
// a condition (also called a conditional expression) is an expression that evaluates to a Boolean value
// else if
// else
// conditions that either aren't or don't evaluate to Booleans are simply converted to bools. Non-zero integers become true, zeros become false

/*
    4.11
*/
// char is a data type used to store a single character
// chars are initialized using character literals (or copy assignment if you want to use the ASCII value)

// Characters that have a special meaning are called escape sequences. They start with \ and then have a following letter or number
// \n
// \t (horizontal tabs)
// \' (single quote)
// \" (double quote)
// \\ (backslash)
// Full table: https://www.learncpp.com/cpp-tutorial/chars/

// Best practice: use single quotes for chars. This helps to compiler optimize more effectively
// Best practice: avoid multicharacter literals

// Do not use wchar_t
// char16_t and char32_t are for unicode

/*
    4.12
*/
// In most cases, C++ will allow us to convert values of one fundamental type to another fundamental type
// The process of converting a value from one type to another is called type conversion
// When the compiler does type conversion on our behalf without us explicitly asking, we call this implicit type conversion
// Safe in most cases, but the compiler may warn us about a loss of data sometimes

// Explicit type conversion allows us to explicitly tell the compiler to covert a value from one type to another type
// To perform an explicit type conversion, in most cases we'll use the static_cast operator. This is the syntax:
// static_cast<new_type>(expression)
// Warning: the static_cast operator will produce undefined behavior if the value being converted doesn't fit in range of the new type

/*
    4.13
*/
// In programming, a constant is a value that may not be changed 
// C++ supports several types of constants: const variables, compile-time constants, constant expressions, constexpr, and literals

// A variable whose value cannot be changed is called a constant variable 
// To make a variable a constant, place the const keyword in the variable's declaration either before or after the variable type:
// const double gravAccel = { 9.81 }  // preferred 
// int const sidesInSquare = { 4 }
// Constant variables must be initizlied at definition

// Const function parameters
// Function parameters can be made constants via the const keyword
// void printInt(const int x)
// Note that we did not provide an explicit initializer for our const parameter x -- the value of the argument in the function call will be used as the initializer for x
// Best practice: don't use const when passing by value like this

// Best practice: don't use const when returning by value

// A symbolic constant is a name that is given to a constant value. Constant variables are one type of symbolic constant, as a variable has a name and a constant value

// Best parctice: prefer constant variables over object-like macros with substitution text

/*
    4.14
*/
// A constant expression is an expression that can be evaluated by the compiler at compile-time
// When the compiler encounteres a constant expression, it may evaluate the expression at compile-time, and then replace the constant expression with the result of the evaluation
// a const variable is a compile-time constant if its initializer is a constant expression

// Any const variable that is initialized with a non-constant expression is a runtime constant
// Runtime constants are constants whose initialization values aren't known until runtime 
// (i.e. something like const int thingy = { someFunction() } where someFunction returns something that isn't a constant)

// Because compile-time constants also allow for better optimization (and have little downside), we typically want ot use compile-time constants wherever possible 
// We can use the constexpr keyword instead of const to ensure that we get a compile-time constant
// If the initialization value of a constexpr variable is not a constant expression we'll get a compiler error

// Best practices:
/*
    * Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr
    * Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const
    * 
*/

// Some types (like strings and vectors) are not compatible with constexpr. Use const for these instead

// C++ does not support constexpr function parameters

/*
    4.15
*/
// Literals are values that are inserted directly into the code
// If the default type of a literal is not as desired, you can change the type of a literal by adding a suffix
// Best practice: prefer literal suffix L (upper case) over l (lower case)

// All C-style string literals have an implicit null terminator:
// "hello" will technically also have an "\0" at the end, called a null terminator 

// A magic number is a literal that either has an unclear meaning or may need to be changed later
// Ex:
// constexpr int maxStudentsPerSchool{ numClassrooms * 30 };
// We have no idea what 30 means, so it's a magic number
// Best practice:: avoid magic numbers in your code (use constexpr variables instead)

/*
    4.16
*/
// hex literals preceeded by 0x
// binary literals preceeded by 0b
// You can use a single quote ' as a digit separator in a binary literal
// You can change the output of values to decimal, octal, or hex with std::dec, std::oct, std::hex

/*
    4.17
*/
// The easiest way to work with strings and string objects in C++ is via the std::string type, which lives in the <string> header
#include <string>
// behaves like a normal string from any other language
// To read a full line of input into a string, you're better off using the std::getline() function
// The function takes two arguments: std::cin and the string variable you want to use

// The std::ws manipulator tells std::cin to ignore any leading whitespace before extraction
// Best practice: If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace

// You can use the .length() method to get a string's character length
// Note: length returns an unsigned integral variable. Be sure to static cast it to an int before using it normally
// In C++20 you can also use the std::ssize() function to get the length as a signed integral value

// Do not pass std::string by value, as making copies of std::string is expensive. Prefer std::string_view

// You can create a string literal by adding an s to the end of a standard string literal after the double quotes (like this: "vbhfsdukbiu"s)
// You must use using namespace std::string_literals for this to work

// constexpr is not supported for these strings

/*
    4.18
*/
// C++17 OR OVER
// std::string_view provides read-only access to an existing string without making a copy
#include <string_view>
// Best practice: prefer std::string_view over std::string when you need a read-only string, especially for function parameters
// std::string_view can be initialized with many different types of strings, including C-style strings, std::strings, or other std::string_view strings
// std::string_view function parameters will accept many different types of string arguments

//std::string_view will not implicitly convert to std::string
// If you do need to do so:
// you can explicitly create a std::string with a std::string::view initializer
// Or you can use static_cast

// Assigning a new string to a std::string_view causes the std::string_view to view the new string

// You can create std:string_view literals by using a sv suffix after the last double quote in a C-style string
// Must use namespace std::string_literals here too

// std::string_view has full support for constexpr

/*
    4.19 
*/
// How to use std::string_view responsibly
// An initialized object has no control over what happens to the initialization value after initialization is finished 
// std::string is an owner. It has its own data that it manages. And when it is destroyed, it cleans up after itself

// std:string_view is a viewer. It views an object that already exists elsewhere, and cannot modify that object. When the view is destroyed, the object being viewed is not affected. 
// It is important to note that a std::string_view remains dependent on the initializer through its lifetime.
//      if the string being viewed is modified or destroyed while the view is still being used, unexpected or undefined behavior will result

// An std::string_view that is viewing a string that has been destroyed is sometimes called a dangling view

// std::string_view is best used as a read-only function parameter

// Modifying a string invalidates all views into that string

// You can use the remove_prefix() and remove_suffix() methods to remove a character from either the left or right side of a string view

// Good summary of when to use std::string vs. str::string_view at the bottom of https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/

int main()
{
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

	return 0;
}
