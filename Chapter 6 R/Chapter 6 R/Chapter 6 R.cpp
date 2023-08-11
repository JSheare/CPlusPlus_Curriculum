#include <iostream>

/*
	CHAPTER 6 R
*/

/*
	6.1
*/
// A compound statement (also called a block, or block statement) is a groupd of zero or more statements that is treated by the compiler as if it were a single statement
// Blocks begin with a { symbol and end with a } symbol
// Blocks can be used anywhere a single statement is allowed
// No semicolon is needed at the end of a block
// Blocks can be nested inside of other blocks
// Best practice: keep the nesting level of your functions to 3 or less. If you need more, consider refactoring your function into sub-functions

/*
	6.2
*/
// C++ allows us to define our own namespaces via the namespace keyword
// We recommend starting namespace names with a capital letter
// A namespace must be defined either in the global scope or inside another namespace

// The scope resolution operator (::) tells the compiler that the identifier specified by the right-hand operand should be looked for in the scope of the left-hand operand

// If an identifier inside a namespace is used and no scope resolution is provided, the compiler will first try to find a matching declaration in that same namespace
// If no matching identifier is found, the compiler will then check each containing namespace in sequence to see if a match is found 
// You can use just :: with no namespace to explicitly call the global version of a function

// It's legal to declare namespace blocks in multiple locations

// When you separate your code into multiple files, you'll have to use a namespace in the header and source file

// Namespaces can be nested inside other namespaces
// either like this:
// namespace Goo
// {
//		namespace Foo
//			{
//				stuff
//			}
// }
// or like this
// namespace Foo::Goo
// You can also use namespace aliases to shorten this:
// namespace Active = Foo::Goo;

// When you write a library or code that you want to distribute to others, always place your code inside a namespace 

/*
	6.3
*/
// Local variables have block scope
// All variable names within a scope must be unique 
// Local variables have automatic storage duration
// Local variables can be defined inside of nested blocks
// Note that nested blocks are considered part of the scope of the outer block in which they are defined. 
// Consequently, variables defined in hte outer block can be seen inside nested block

// An identifier's linkage determines whether other declarations of that name refer to the same object or not
// Local variables have no linkage, which means that each declaration refers to a unique object

// Variables should be defined in the most limited scope
// Best practice: define variables in the most limited scope. Avoid creating new blocks whose only purpose it to limit the scope of variables 

/*
	6.4
*/
// Variables declared outside of a function are called global variables
// By convention, global variables are declared at the top of a file, below the includes, in the global namespace 
// Identifiers declared in the global namespace have global namespace scope, which means they are visible from the point of declaration until the end of the *file*
// They can also be defined inside of user-defined namespaces

// Global variables are created when the program starts, and destroyed when it ends. This is called static duration
// Variables with static duration are sometimes called static variables

// By convention, some developers prefix non-const gloval variable identifiers wiht "g" or "g_"
// Best practice: do this

// Global variables are zero initialized by default, so non-constant ones can be optionally initialized
// Constant ones, on the other hand, like all constant variables, must be initialized

/*
	6.5
*/
// When two variables, one in an outer block and one in an inner block, both have the same name, the nested variable hides the outer variable when they are both in scope
// This is called name hiding or shadowing 

// This happens with global/local variables of the same name as well
// Use :: if you want the global variable

// Best practice: avoid variable shadowing

/*
	6.6
*/
// Global variable and function identifiers can have either internal linkage or external linkage 
// An identifier with internal linkage can be seen and used within a single translation unit, but it is not accessible from other translation units 
// This means that if two source files have identically names identifiers with internal linkage, those identifiers will be treated as independent 

// Global variables with internal linkage are sometimes called internal variables
// To make a non-constant global variable ionternal, we use the static keyword 
// Const and constexpr global variables have internal linkage by default 
// Functions default to external linkage, but can be set to internal linkage via the static keyword

// Best practice: give identifiers internal linkage when you have an explicit reason to disallow access from other files
//		consider giving all identifiers you don't want accessible to other files internal linkage (use and unnamed namespace for this 

/*
	6.7
*/
// An identifier with external linkage can be seen and used brom the file in which it is defined, and from other code files (via forward declaration)

// Global variables with external linkage are sometimes called external variables
// Non-const global variables are external by default 
// To make a global variable external, we can use the extern keyword 
// extern const int g_y = { 3 };
// To actually use external global variables in other files, those files must feature forward declarations for the variables using the extern keyword 
// extern const int g_y; 
// Warning: If you want to define an uninitialized non-const global variable, don't use the extern keyword
// extern is only needed for variables

/*
	6.8
*/
// Best practice: use local variables instead of global variables whenever possible

// Warning: dynamic initialization of global variables causes a lot of problems in C++. Avoid dynamic initialization whenever possible

// As a rule of thumbm any use of a global variable should meet at least the following two criteria:
// 1) There should only ever be on of the thing the variable represents in your program
// 2) Its use should be ubiquitous throughout your program

// Instead of allowing direct access to the global variable, it's a better practice to "encapsulate" the variable
//		Make sure the variable is internally linked and then provide global "access functions" for working with the variable

// When writing an otherwise standalone function that uses the global variable, don't use the variable directly in your function body, pass it as an argument instead.

// What's the best prefix for a global variable?
// 

/*
	6.9
*/
// Global constants as internal variables
// Prior to C++17, the following is the easiest and most common solution: 
// 1) Create a header file to hold these constants
// 2) Inside this header file, define a namespace 
// 3) Add all your constants inside the namespace (make sure they're constexpr)
// 4) #include the header file wherever you need it 
// This has a lot of disadvantages though

// C++17 introduced a nwe concept called inline variables 
// An inline variable is one that is allowed to be defined in multiple files without violating the one definition rule 
// Inline global variables have external linkage by default 
// Inline variables have two primary restrictions that must be obeyed:
// 1) All definitions of the inline variable must be identical (otherwise you get undefined behavior)
// 2) The inline variable definition (not a forward declaration) must be present in any file that uses the variable 
// With inline variables we can use the method above, with one addition: the inline keyword

/*
	6.10
*/
// Using the static keyword on a local variable changes its duration from automatic duration to static duration (dies with the program)
// It's common to use the prefix s_ for static local variables
// Best practice: initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls

// With a const/constexpr static local variable, you can create and initialize the expensive object once, and then reuse it whenever the function is called
// Best practice: avoid static local variables unless the variable never needs to be reset

/*
	6.12
*/
// A name can be either qualified or unqualified
// A qualified name is a name that includes an associated scope
// Most often, names are qualified with a namespace using the scope resolution operator 

// An unqualified name is a name that does not include a scoping qualifier

// One way to reduce the repetition of typing std:: over and over is to utilize a using-declaration statement 
// A using declaration allows us to use an unqualified name as an alias for a qualified name

// Stuff like using std::cout (only applies to std::cout) is safe and acceptable 

// Using directives are things like using namespace std

// Best practice: prefer explicit namespaces over using-statements. Avoid using-directives whenever possible. Using-declarations are okay to use inside blocks

/*
	6.13
*/
// Inline expansion is a process where a function call is replaced by the code from the called function's definition
// A function that is eligible to have its function calls expanded is called an inline function 
// The inline keyword can be used to (maybe) make a function inline

// Best practice: do not use the inline keyword to request and expansion for your functions 

// Best practice: avoid the use of the inline keyword for functions unless you have a specific, compelling reason to do so

/*
	6.14
*/
// A constexpr function is a function whose return value may be computed at compile time
// To make a function a constexpr function, we simply use the constexpr keyword in front of the return type
// To be eligible for compile-time evaluation, a function must have a constexpr return type and not call any non-constexpr functions
// Additionally, a call to the function must have constexpr arguments 

// Best practice: Use a constexpr return type for functions that need to return a compile-time constant 

// Functions with a constexpr return value can also be evaluated at runtime, in which case they will return a non-constexpr result
// According to the C++ standard, a constexpr function that is eligible for compile-time evaluation must be evaluated at compile-time if the return value 
//		is used where a constant expression is required
// Otherwise, the compiler is free to evaluate the function at either compile-time or runtime

// C++20 introduces the keyword consteval, which is used to indicate that a function *must* evaluate at compile-time

// Best practice: Use consteval if you have a function that must run at compile-time for some reason

// Best practice: Constexpr functions used in a single source file (.cpp) can be defined in the source file above where they are used
//		Constexpr functions used in multiple source files should be defined in a header file so they can be included into each source file

/*
	6.15
*/
// An unnamed namespace is a namespace that is defined without a name
// All identifiers inside an unnamed namespace are treated as if they have internal linkage

// An inline namespace is a namespace that is typically used to version content 
// Inline namespaces don't affect linkage

namespace Goo
{
	int bar()
	{
		return 1;
	}
}

#if 0
int main()
{
	Goo::bar();
	return 0;
}
#endif 