#include <iostream>

/*
	CHAPTER 1 R
*/

int main() 
{
	/*
		1.1
	*/
	// #include is a preprosessor directive 
	// Sometimes compiler errors may be on the line previous to the one indicated by error message

	/*
		1.2
	*/

	/*
	* beautified
	* multiline
	* comment
	*/

	// Multiline comments cannot be nested

	/*
		1.3
	*/
	// An object is a region of storage (usually memory) that can store a value, and has other associated properties
	// Objects can be named or unnamed (anonymous). A named object is called a variable, and the name of the object is called an identifier 

	int x;  // define a variable named x, or type int
	x = 0;  // Asign the value 0 to x

	// In C++, the type of variable must be known at compile-time, and that type cannot be changed without recompliling the program 

	// Things like this are possible
	int w, z;
	// But don't do that. just give each variable its own assignment statement
	w = 0;
	z = 0;

	/*
		1.4
	*/
	// Giving variables values via assignment 
	int width;  // define an integer variable named width
	width = 5;  // copy assignment of value 5 into variable width

	// There are 6 basic ways to initialize variables in C++
	int a;			// no itnitializer (default initialization)
	int b = 5;		// initializer after equals sign (copy initialization)
	int c(6);		// initializer in parenthesis (direct initialization)

	// List initialization methods (C++11) (preferred)
	int d{ 7 };		// initializer in braces (direct list initialization)
	int e = { 8 };	// initializer in braces after equals sign (copy list initialization) 
	int f{};		// initializer is empty braces (value initialization) 

	// Default initialization leaves a variable with an indeterminate value 
	// Copy initialization was inherited from C. Fell out of favor for a while after C++11, but is now pretty much as efficient as the others
	// Direct initialization has fallen out of favor because it can make differentiating between variables and functions difficult 
	// List initialization methods disallow narrowing conversions (i.e. something like int width {4.5}; would raise an error because 4.5 is a float)
	//		These types of initializations are the modern way to initializae variables in C++
	
	// Best practice: initialize your variables upon creation

	// assigning a and f to prevent warnings
	a = 0;
	f = 0;

	// You can use the [[maybe_unused]] attribute to prevent the compiler from throwing errors when a variable isn't used
	[[maybe_unused]] int j = { 5 };

	/*
		1.5
	*/
	// << is called the insertion operator
	std::cout << width << '\n';

	// Best practice: output a newline whenever a line of output is complete
	// std::cout is buffered
	// Best practice: prefer '\n' over std::endl when outputting text to the console
	// >> is called the extraction operator

	// Demonstration of std::cin
	std::cout << "Enter a number: "; 
	int number = {};
	std::cin >> number;
	std::cout << "You entered " << number << '\n';

	// std::cin with multiple values
	std::cout << "Enter two numbers: ";
	int number1 = {};
	int number2 = {};
	std::cin >> number1 >> number2;
	std::cout << "You entered " << number1 << " and " << number2 << '\n';

	// Best practice: initialize variables before using them in std::cin

	/*
		1.6
	*/
	// Unlike some programming languages, C/C++ does not initialize most variables to a given value (such as zero) automatically.
	// Thus, when a variable is given a memory address to use to store data, the default value of that variable is whatever (garbage) value happens to already be in that memory address!
	// A variable that has not been given a known value (usually through initialization or assignment) is called an uninitialized variable. 

	// Using the value from an uninitialized variable is out first example of undefined behavior.
	// Undefined behavior is the result of executing code whose behavior is not well-defined by the C++ language.
	// In this case, the C++ language doesn't have any rules determining what happens if you use the value of a variable that has not been given a known value.
	// Consequently, if you actually do this, undefined behavior will result.
	//Code implementing undefined behavior may exhibit *any* of the following symptoms:
	/*
		* Your program produces different results every time is its run
		* Your program consistently produces the same incorrect result
		* Your program behaves inconsistently 
		* Your program seems like it's working but produces incorrect results later in the program
		* Your program crashes, either immediately or later
		* Your program works on some compilers but not others
		* Your program works until you change some other seemingly unrelated code
		* Or, your code may actually provide the correct behavior anyway
	*/

	// Implementation-defined behavior means the behavior of some syntax is left up to the implementation (the compiler) ot define.
	// Such behaviors must be consistent and documented, but different compilers may produce different results 
	//ex:
	std::cout << sizeof(int) << '\n';  // print how many bytes of memory an int value takes
	// This wil return 4 on most compilers, but on some it will produce 2

	// Best practice: avoid implementation-defined and unspecified behavior whenever possible, as they may cause your program to malfunction on other implementations

	/*
		1.7
	*/
	// C++ reserves a set of particular words for its own use. These words are called keywords (or reserved words), and each of these keywords has a special meaning within the language.
	// see https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/ for a full list (as of C++20)
	// C++ also defines special identifiers: override, final, import, and module. These have a specific meaning when used in certain contexts but are not reserved.
	
	// Variable identifier practices:
	/*
		* Variable names should begin with a lowercase letter
		* If the variable name is one word, the whole thing should be written in lowercase letters
		* snake_case
		* camelCase (or intercapped)
		* Don't start identifiers with underscores
		* Try to match identifier length with how much the corresponding variable is used
	*/

	// Best practice: when working in an existing program, use the conventions of that program. Use modern practices when you're writing new programs

	/*
		1.8
	*/
	// Whitespaces and formatting

	// Formatting indendation: just use 4 space tabs like everyone else

	// Each curly brace gets its own line:
	//	int main
	//  {
	//  }

	// Each statement within curly braces should start one tab in from the opening brace of hte function it belongs to 

	// Maximum line length of 80 characters.
	// If a line needs to be split, indent each subsequent line with an extra tab. Or, if the lines are similar, align it with the line above
	// Ex:
	/*
	int main()
	{
		std::cout << "This is a really, really, really, really, really, really, really, "
			"really long line\n"; // one extra indentation for continuation line

		std::cout << "This is another really, really, really, really, really, really, really, "
					 "really long line\n"; // text aligned with the previous line for continuation line

		std::cout << "This one is short\n";
	}
	*/
	// If a long line is split with an operator, the operator should be placed at the beginning of the next line, not the end of the current line 

	// Use whitespace to make your code easier to read by aligning values or comments or adding spacing between blocks of code

	/*
		1.9
	*/
	// A literal (also known as a literal constant) is a fixed value that has been inserted directly into the source code
	// int x = {5};
	// The 5 is the literal in this case
	// Literals are values that are inserted directly into the source code. These values usually appear directly in the executable code (unless they are optimized out)

	// Operators
	// The number of operands that an operator takes as input is called the operator's arity. Operators in C++ come in four different arities:
	// Unary operators act on one operand (ex: the - in -5)
	// Binary operators act on two
	// Ternary operators act on three (only one in C++ is the conditional operator)
	// Nullary operators act on zero operands (only one in C++ is the throw operator)
	// Operators operate in standard PEMDAS order
	// An operator that has some observable effect beyond producing a return value is said to have a side effect
	//		Operators with side effects are usually called for the behavior of the side effect rather than for the return value (if any) those operators produce

	/*
		1.10
	*/
	// An expression is a combination of literalr, variables, operators, abd function calls that calculates a single value.
	// The process of executing an expression is called evaluation and the single value produced is called the result of the expression. 
	// Expressions do not include semicolons; they are always part of statements
	// Expression statement: expression followed by a semicolon

	return 0;
}
