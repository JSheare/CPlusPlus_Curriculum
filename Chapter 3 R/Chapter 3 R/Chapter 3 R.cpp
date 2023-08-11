#include <iostream>

/*
	CHAPTER 3 R
*/

/*
	3.4
*/
// Tip: when printing information for debugging purposes, use std::cerr instead of std::cout 
// Tip: when adding temporary debug statements, it an be helpful not to indent them.

/*
	3.5
*/
// You can use preprocessor directives to make your debugging statements toggleable:
// #define ENABLE_DEBUG  // comment this out to disable debugging
// #ifdef ENABLE_DEBUG
// debug statement
// #endif

// You can use log files to assist in debugging
// plog is good for this

/*
	3.6
*/
// Visual Studio debugger
// Step into using f11
// yellow arrow indicates which line will be executed next
// step forward using f11
// step over (f10) will execute the next statement in the program but will execute entire functions and then return control afterwards
// Step out (shift + f11) is useful when oyu've stepped into a function that you don't want to debug. It will finish executing the function and then return control

 /*
	3.7
 */
// Run to cursor (right click menu) will execute the program up to the statement you've selected with your cursor and then start the debugger
// continue just runs the program from your current position (either until program termination or a breakpoint)
// Start is similar to continue, just that it begins at the start of the program
// A breakpoint is a special marker that tells the debugger to stop execution of the program at the breakpoint when running in debug mode
// You can toggle breakpoints with f9
// Set next command allows us to change the point of execution to some other statement 
// Warning: you should not use the set next statement to change the point of execution to a different function. This will result in undefined behavior

/*
	3.8
*/
// In debug mode, you can hover over variables to see their value at the current time of execution
// You can also use the watch window to see how a variable's value changes as the program is executed
// You can watch all local variables in scope using Debug > Windows > Locals

/*
	3.9
*/
// The call stack is a list of all the active functions that have been called to get to the current point of execution 
// The call stack includes an entry for each function called, as well as which line of code will be returned to when the function returns

/*
	3.10
*/
// The process of making structural changes to your code without changing its behavior (typically in order to make your program more organized, modular, or performant)
//		is called refactoring 
// A function that takes up one vertical screen worth of code is generally regarded as too long
// Ideally, a function should be less than ten lines. Functions that are less than five lines are even better

// Defensive programming is a practice whereby the programmer tries to anticipate all of the ways the software could be misused.
// These misuses can often be detected and then mitigated

// Best practice: use a static analysis tool on your programs to help find areas where your code is non-compliant with best practices

int readnumber()
{
	std::cout << "please enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeanswer(int x)
{
	std::cout << "the quotient is: " << x << '\n';
}

#if 0
int main()
{
	int x{ };
	int y{ };
	x = readnumber();
	y = readnumber();
	writeanswer(x / y);

	return 0;
}
#endif
