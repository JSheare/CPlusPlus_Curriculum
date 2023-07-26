#include <iostream>

/*
    CHAPTER 8 R
*/

/*
    8.1
*/
// The C++ language standard defined how different fundamental types (and in some cases, compound types) can be converted into other types
// These conversion rules are called the standard conversions

/*
    8.2
*/
// A numeric promotion is the type conversion of certain narrower types (such as char) to certain wider numeric types (typically int or double) that can be processsed 
//      efficiently ans is less likely to have a result that overflows
// All numeric promotions are value-preserving, which means that the converted value will always be equal to the source value 
// These are said to be "safe conversions"

// The numeric promotion rules are divided into two subcategories: integral promotions and floating point promotions 

// Using the floating point promotion rules, a value of type float can be converted to a value of type double

// Using the integral promotion rules, the following conversion can be made:
/*
    * signed char or signed short can be converted to int
    * unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type, or unsigned int otherwise
    * if char is signed by default, it follows the signed char conversion rules above. If unsigned by default, it follows the unsigned char conversion rules above
    * bool can be converted to int, with false becoming 0 and true becoming 1
*/

/*
    8.3
*/
// Numeric conversions cover additional type conversions between fundamental types
// The specific rules for numeric conversions are complicated and numerous, so here are the most important things to remember:
// In *all* cases, converting a value into a type whose range doesn't support the value will lead to results that are probably unexpected

/*
    8.4
*/
// In C++, a narrowing conversion is a potentially unsafe numeric conversion where the destination type may not be able to hold all the values of the source type

// Best practice: because they can be unsafe and are a source of errors, avoid narrowing conversion whenever possible 

// Best practice: make intentional narrowing conversions explicit with a static_cast

/*
    8.5
*/
// The operators that require operands of the same type:
// +, -, *, /, %
// <, >, <=, >=, ==, !=
// &, ^, |
// ?: (conditional operator)

// The usual arithmetic conversion rules:
// The compiler has a prioritized list of types that looks something like this:
// long double, double, float, unsigned long long, long long, unsigned long, long, unsigned int, int
// There are only two rules:
// If the type of at least one of the operands is on the priority list, the operand with the lower priority is converted to the type of the operand with higher priority
// Otherwise, both operands are numerically promoted

/*
    8.6
*/
// C++ comes with a number of type casting operators that can be used by the programmer to request that the compiler perform a type conversion
// 5 types of casts: C-style casts, static casts, cosnt casts, dynamic casts, and reinterpret casts

// const casts and reinterpret casts should generally be avoided because they are only useful in rare cases and can be harmful if used incorrectly

// C-style casts have the following syntax:
// double d = { double(x)/y };

// Best practice: avoid using C-style casts

// Static casts:
// double d = { static_cast<double>(x) / y };
// Best practice: favor static_cast when you need to convert a value from one type to another

/*
    8.7
*/
//  In C++, using is a keyword that creates an alias for an existing data type
// To create such a type alias, we use the using keyword, followed by a name for the type alias, followed by an equals sign and an existing data type:
// using Distance = double;  // define Distance as an alias for the type double

// Best practice: name your type aliases starting with a capital letter and do not use a suffix

// typedefs do the same thing but with different syntax:
// typedef double Distance;

// Best practice: prefer type aliases over typedefs

// Type aliases allow you to take complex types and give them a simpler name

/*
    8.8
*/
// Type deduction (also sometimes called type inference) is a feature that allows the compiler to deduce the type of an object from the object's initializer
// To use type deduction, the auto keyword is used in place of the variable's type

// In most cases, type deduction will drop the const or constexpr qualifier from deduced types

// If you want the type deduced from a string literal to be std::string or std::string_view, you'll need to use the s or sv suffixes 

// Best practice: use type deduction for your variables, unless you need to commit to a specific type

/*
    8.9
*/
// auto also works for function return types

// Best practice: favor explicit return types over function return type deduction for normal functions 

// The auto keyword can also be used to declare functions using a trailing return syntax:
// auto add(int x, int y) -> int;
// Don't actually use this unless necessary

// In C++20 an above you can use auto for the types of function parameters. This triggers function templates

/*
    8.10
*/
// Function overloading allows us to create multiple functions with the same name, so long as each identically named function has different parameter types
// Each function sharing a name is called an overload function
// Additionally, when a function call is made to a function that has been overloaded, the compiler will try to match the function call to the appropriate overload
//      based on the arguments used in the function call

// Best practice: use function overloading to make your program simpler

/*
    8.11
*/
// Number and type of parameters can be used for overloaded function differentiation. Return type cannot be used for differentiation
// A function's type signature is defined as the parts of the function header that are used for differentiation of the function

/*
    8.12
*/
// The process of matching function calls to a specific overload is called overload resolution
// When a function call is made to an overloaded function, the compiler steps through a sequence of rules to determine which (if any) of the overloaded functions is the best match
// If the compiler finds multiple matches in a given step, an ambiguious function call will result

/*
    8.13
*/
// A default argument is a default value provided for a function parameter
// You must use an equals sign to specify a default argument
// Unfortunately, due to syntax, if a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments
// Default arguments cannot be redeclared

// Best practice: if the function has a forward declaration (especially one in a header file), put the default argument there. Otherwise put the default argument in the function def

/*
    8.14
*/
// Just like a normal definition, a template describes what a function or class looks like
// In a template we can use one or more placeholder types. A placeholder type represents some type that is not known at the time the template is written, but that will be provided later

// A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types
// When we create our function template, we use placeholder types (also called type template parameters) for any parameter types, return types, or types used in the function body
//      that we want to be specified later
// Template function ex:
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

// Best practice: Use a single capital letter (starting with T) to name your type template parameters

/*
    8.15
*/
// To use our max<T> function template, we can make a function call with the following syntax:
// max<actual_type>(arg1, arg2); // actual_type is some actual type, like int or double
// In cases where the type of arguments match the actual type we want, we do not need to specify the actual type: the compiler will deduce it
// In most cases, the normal function call syntax will be the one we use to call functions instantiated from a function template

// Best practice: favor the normal function call syntax when making calls to a function instantiated from a function template

// Functions implicitly instantiated from templates are implicitly inline

// Best practice: templates that are needed in multiple files should be defined in a header file and then #included wherever needed

// Best practice: use function templates to write generic code that can work with a wide variety of types whenever you have the need

/*
    8.16
*/
// Abbreviated function template ex:
auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}

/*
    8.17
*/
// A non-type template parameter is a template parameter with a fixed type that serves as a placeholder for a constexpr value passes in as a template argument

// Best practice: Use N as the name of an int non-type template parameter

// 

int main()
{
    return 0;
}


