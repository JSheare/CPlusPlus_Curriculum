#include "addfloat.h" // note the use of double quotes
#include <iostream>

/*
	CHAPTER 2 R
*/

/*
	2.1
*/
// A function is a reuseable sequence of statements designed to do a particular job
// Example function:
int printint(int thing)  // Header
{
	std::cout << thing << '\n';  // Body

	return 0;
}

// Functions can call other functions
// Nested functions are not supported

/*
	2.2
*/
// int in the above example is the return type of the function
// Best practice: your main() function should return the value 0 if the program ran normally 
// C++ disallows calling the main function explicitly 
// For now, you should also define your main function at the bottom of your code file, below other functions
// A value-returning function *must* return a value of that type (using a return statement), otherwise undefined behavior will result
// Functions can only return a single value 

/*
	2.3
*/
// Functions with the return type void are non-value returning functions 
// Because they don't return anything, they don't need a return statement
// Best practice: don't put a return statement at the end of a void function 
// Early returns are return statements that appear before the end of the function body

/*
	2.4 
*/
// A function parameter is a variable used in the header of a function. They are initialized with a value provided by the caller of the function 
// int thing in the above example is the paramater of the function printint()
// An argument is the value that is passed from the caller to the function when the function call is made
// In a function declaration, the name of a function parameter is optaional. Therefore, in cases where a function parameter needs to exist but is not used in the body of the 
//		function, you can simply omit the name(i.e. void func(int){}). A parameter without a name is called an unnamed parameter
// The Google C++ style guide recommends using a comment to document what the unnamed parameter was: void func(int /*count*/)

/*
	2.5
*/
// Variables defined inside the body of a function are called local variables 
// Function parameters are also generally considered to be local variables, and we will include them as such 
// Local variables are destroyed in the opposite order of creation at the end of the set of curly braces in which it is defined
// Variable lifetime is a runtime property

// An identifier's scope determines where the identifier can be seen and used within the source code
// When an identifier can be seen and used, we sait it is in scope. When an identifier cannot be seen, we cannot use it, and we sait it is out of scope
// A local variable's scope begins at the point of variable definition, and stops at the end of the set of curly braces in which it is defined 
// Variable scope is a compile-time property 

// Local variables' lifetime ends when they go out of scope, but this isn't true for all variables
// Variables that are declared and initialized inside of main() are only usable inside of main() (unlike in python)

// Best practice: define your local variables as close to their first use as possible

/*
	2.6
*/
// A function should generally perform one (and only one) task
// When a function becomes too long, too complicated, or hard to understand, it can be split into multiple sub-functions.
//		This is called refactoring 

/*
	2.7
*/
// Aside: it's useful to generally note that it is fairly common for a single error to produce many redundant or related errors or warnings 
// Best practice: when addressing compile errors in your programs, always resolve the first error produced first and then compile again
// A forward declaration allows us to tell the compiler about the existance of an identifier before actually defining the identifier
// To write a forward declaration for a function, we use a function declaration statement:

int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon only 

int add(int x, int y) // Function definition 
{
	return x + y;
}

// Note: function declarations doe not need to specify the names of the parameters (i.e. we could've done int add(int, int); )
// Best practice: keep the parameter names in your function declarations 
// Tip: you can easily create function declarations by copy/pasting your functions' header and adding a semicolon 
// Most often, forward declarations are used to tell the compiler about the existance of some function that has been defined in a different code file 
// Forward declarations can also be used to define our functions in an order-agnostic manner (i.e. according to whatever organization we deem most appropriate)
// Forward declarations also allow us to resolve situations where one function calls another before it has been defined 

// Declarations vs. definitions 
// A declaration is a statement that tells the compiler about the existance of an identifier and its associated type information 
// A definition tells the compiler how an identifier is implemented (for functions or types) or where that identifier should be instantiated (for variables) 
// In C++ all definitions also serve as declarations 
// Conversely, not all declarations are definitions. Declarations that aren't definitions are called pure declarations 

// The one definition rule
// A well-known rule in C++. It has three parts:
/*
	* Within a given file, a function, variable, type, or template can only have one definition
	* Within a given program, a variable or normal function can only have one definition
	* Types, templates, inline functions, and inline variables are allowed to have identical definitions in different fiels 
*/

/*
	2.8
*/
// Best practice: when you add new code files to your project, give them a .cpp extension
// Use forward declarations for functions defined in other files:
//float addfloat(float x, float y);
// Commented for the discussion of header files

/*
	2.9
*/
// If two identical identifiers are introduced into the same program in a way that the compiler or linker can't tell them apart, the compiler or linker will produce an error.
// This error is genreally referred to as a naming collision 

// A namespace is a region that allows you to declare names inside of it for the purpose of disambiguation.
// The namespace provides a scoep region (called namespace scope) to the names declared inside of it 

// In C++, any name that is not defined inside a class, function, or namespace is considered to be part of an implicitly defined namespace caled the global namespace (or global scope)
// Only declarations and definition statements can appear in the global namespace. This means we can define variables in the global namespace, though you should avoid this

// When you use an identifier that is defined inside a namespace (such as the std namespace), you have to tell the compiler that the identifier lives inside the namespace 
// A few ways to do this:
// With an explicit namespace qualifier std:: 
//		The :: symbol is called the scope resolution operator 
// Using namespace std - don't have to use std:: with all member functions of the std namespace 
// Best practice: use explicit namespace prefixes to access identifiers defined in a namespace

/*
	2.10
*/
// Prior to compilation, each .cpp file goes through a preprocessing phrase. 
// In this phase, a program called the preprocessor makes various changes to the text of the code file
// The preprocessor is what processes #include directives 
// When the preprocessor has finished processing a code file, the result is called a translation unit. The translation unit is what is then compiled by the compiler
// A translation unit contains both the processed code from the code file, as well as the processed code from all of the #included files 

// When the preprocessor runs, it scans through the code file looking for preprocessor directives 
// Preprocessor directives are instructions that start with a # symbol and end with a newline 
// These directives tell the preprocessor to perform certain text manipulation tasks 

// Some of the more common ones:
// #include - preprocessor replaces this directive with the contents of the included file
// #define can be used to create a macro 
// Conditional compilation - #ifdef, #ifndef, #endif 
// #if 0 - followed by a #endif at the end of a block of code. Nothing inside is compiled. You can disable this temporarily by changing the 0 to a 1

/*
	2.11
*/
// Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing in multi-file programs 
// Header files consist of only two parts:
/*
	* A header guard
	* The actual content of the header file, which should be the forward declarations of all of the identifiers we want other files to be able to see
*/
// See addfloat.h for example header file
// Best practice: if a header file is paired with a code file, they should both have the same base name (add)
// To include the header, use #include "name_of_file.h". Note the use of double quotes
// Best practice: For now, you should avoid putting function or variable definitions in header files
// Best practice: source files should #include their paired header file (if one exists)
//		This allows the compiler to catch certain kinds of errors at compile time instead of at link time
// Best practice: avoide #including .cpp files

// Use double quotes to include header files that you've written or are expected to be found in the current directory. Use angled brackets to include headers that come with
//		your compiler, OS, or third-party libraries you've installed elsewhere on your system 

// Best practice: each file should explicitly #include all of he header files it needs to compile. Do not rely on header inlcluded transitively from other headers
/*
	Best practice: to maximize the chance that missing included will be flagged by the compiler, order your #includes as follows:
	* The paired header file
	* Other headers from your project
	* 3rd party library headers
	* standard library headers
*/

// Best practice: prefer putting documentation on what something does or how to use it in the header

/*
	2.12
*/
// You can avoid errors arising from multiple inclusions of the same functions using header guards 
// They take the following form:
/*
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif
*/
// When this header is #included, the preprocessor checks whether SOME_UNIQUE_NAME_HERE has been previously defined. 
// If this is the first time we’re including the header, SOME_UNIQUE_NAME_HERE will not have been defined. 
// Consequently, it #defines SOME_UNIQUE_NAME_HERE and includes the contents of the file. 
// If the header is included again into the same file, SOME_UNIQUE_NAME_HERE will already have been defined from the first time the contents of the header were included, 
//		and the contents of the header will be ignored (thanks to the #ifndef).

// See addfoat.h for header guard example

// You shuold always include header guards in your header files

// You can also use #pragma once in your header files instead of header guards

// Remember to #include the header file in the corresponding .cpp file


#if 0
int main()
{
	std::cout << addfloat(3.5, 3.5) << '\n';
	return 0;
}
#endif