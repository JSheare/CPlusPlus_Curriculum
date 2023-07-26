#include <iostream>

/*
    CHAPTER 7 R
*/

/*
    7.1
*/
// The specific sequence of statements that the CPU executes is called the program's execution path (or path for short)
// Straight-line programs take the same path every time they are run

// Control flow statements are statements that allow the programmer to change the normal path of execution through the program 
// When a control flow statement cause point of executiuon to change to a non-sequential statement, this is called branching 

/*
    7.2
*/
// if statements
// execute multiple statements after if/else with a block ({})
// Best practice: consider putting statements associated with an if or else in blocks
// Statements called within if/else control flow are implicitly treated as being called within a block. This means that, for example, any variables declared inside will die after the
//      control flow has been executed:
// if (some condition)
// {
//      int x = {5}
// } <- x dies here

/*
    7.3
*/
// Nested if statements are possible
// Always enclose inner if/else statements in a block

// Null statements do nothing.
// They are typically used when the language requires a statement to exist but the programmer doesn't need one
// For readability, they are typically placed on their own lines:
// if (x > 10)
// ;  // this is a null statement

/*
    7.4
*/
// Evaluating a constexpr conditional at runtime is wasteful (since the result will never vary)
// It is also wasteful to compile code into the executable that can never be executed

// Best practice: favor constexpr if statements over non-constexpr statements when the conditional is a constant expression 

/*
    7.5
*/
// The idea behind a switch statement sis simple: an expression (sometimes called the condition) is executed to produce a value
// If the expression's value is equal to the vaklue after any of the case labels, the statements after the matching case label are executed
// If no matching value can be found and a default label exists, the statements after the default label are executed instead 

// Compared to the original if statement, the switch statement has the advantage of only evaluating the expression once (making it more efficient), and the 
// switch statement also makes it clear to the reader that it is the same expression being tested for equality in each case

// Best practice: prefer switch statements over if-else chains when there is a choice 

// We start a switch statement by using the switch keyword, followed by parentheses with the conditional expression that we would like to evaluate inside
// Often the expression is just a single variable, but it can be any valid expression 
// The one restriction is that the condition must evaluate to an intergral type 

// Switch labels:
// The first kind of label is the case label, which is declared using the case keyword followed by a constant expresison 
// The constant expression must either match the type of the condition or must be convertible to that type

// The second kind of label is the default label, which is declared using the 'default' keyword
// If the conditional expression does not match any case label and a default label exists, execution begins at the first statement after the default label

// Best practice: place the default case last in the switch block

// If the value of the conditional expression does not match any of the case labels, and default case has been provided, then no cases inside the switch are executed
// Execution continues after the end of the switch block

// A break statement tells the compiler that we are done executing statements within the switch, and that execution should continue 
//      with the statement after the end of the switch block
// This allows us to exit a switch statement without exiting the entire function

// Best practice: each set of statements underneath a label should end in a break statement or a return statement

/*
    7.6
*/
// Without a break or return, execution will overflow into subsequent cases
// When execution flows from a statement underneath a label into statements underneath a subsequent label, this is called fallthrough

// Attributes are a modern C++ feature that allows the programmer to provide the compiler with some additional data about the code
// To specify an attribute, the attribute name is placed between double brackets
// The [[fallthrough]] attribute modifies a null statement to indicate that the fallthrough is intentional (and no warnings should be triggered)

// Best practice: use the [[fallthrough]] attribute (along with a null statement) to indicate intentional fallthrough

// Switch case statements can be placed in a sequence to execute the same statement for multiple different cases:
// switch (c)
// {
//      case 'a':
//      case 'b':
//      case 'c':
//          return true;
//      default:
//          return false;
// }

// Statements after labels are scoped to the switch block. No implicit blocks are created
// You can declare or define (but not initialize) variables inside the switch, both before and after the case labels

// Best practice: if defining variables used in a case statement, do so in a block inside the case

/*
    7.7
*/
// An unconditional jump causes execution to jump to another spot in the code
// "Unconditional" means the jump always happens 
// Unconditional jumps are implemented via a goto statement, and spot to jump to is identified through use of a statement label:

#include <cmath> // for sqrt() function

//int main()
//{
//    double x{};
//tryAgain: // this is a statement label
//    std::cout << "Enter a non-negative number: ";
//    std::cin >> x;
//
//    if (x < 0.0)
//        goto tryAgain; // this is the goto statement
//
//    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
//    return 0;
//}

// Statement labels utilize a scope called function scope, which means the label is visible throughout the function even before its point of declaration
// The goto statement and its corresponding statement label must appear in the same function
// goto statements can jump forward and backward
// Statement labels must be associated with a statement

// Spaghetti code is code that has a path of execution that resembles a bowl of spaghetti, making it extremely difficult to follow

// Best practice: avoid goto statements (unless the alternatives are significantly worse for code readability)

/*
    7.8
*/
// while loops:
// while (condition)
//      statement;
// The only way to exit an inifinite loop is through a return-statement, a break-statement, an exit-statement, a goto-statement, an exception being thrown,
//      or the user killing the program

// Best practice: favor while(true) for intentional infinite loops

// The most common type of loop variable is called a counter, which is a loop variable that counts how many times a loop has executed 

// Best practice: integral loop variables should generally be a signed integral type

/*
    7.9
*/
// A do-while statement is a looping construct that works just like a while loop, except the statement always executes at least once
// After the statement has been executed, the do-while loop checks the condition. If the condition evaluates to true, the path of execution jumps back up to the top of the
//      do-while loop and executes it again

// Best practice: favor while loops over do-while when given an equal choice

/*
    7.10
*/
// for loops:
// for (init-statement; condition; end-expression)
//      statement;
// The init-statement is typically used for variable definition and initialization
// These variables have "loop scope," which is really just a form of block scope where these variables exist from the point of definition through the end of the loop statement

// Best practice: avoid operator!= when doign numeric comparisons in the for-loop condition

// You can write loops like this
// for ( ;; )
// If you ever wanted to for some reason

// Multiple variables can be defined in the init statement, separated by commas

// Best practice: defining multiple variables (in the init statement) and using the comma operator (in the end expression) is acceptable inside a for statement

// Best practice: prefer for loops over while loops when there is an obvious loop variable. Prefer while loops over for loops when there is no obvious loop variable

/*
    7.11
*/
// The break statement causes a while loop, do-while loop, for loop, or switch statement to end, with execution continuing with the next statement after the loop or switch
// The continue statement provides a convenient way to end the current iteration of a loop without terminating the entire loop

// Best practice: use break and continue when they simplify your loop logic

// Best practice: use early returns when they simplify your function's logic

/*
    7.12
*/
// A halt is a flow control statement that terminates the program
// std::exit() is a function that causes the program to terminate normally 
// Normal termination means the program has exited in an expected way
// Although std::exit() is called implicitly when function main() ends, std::exit() can also be called explicitly to halt the program before it would normally terminate
// You need to #include the cstdlib header to do this

// std::exit() does not clean up any local variables, so it's generally better to avoid calling std::exit()

// the std::atexit() function allows you to specify a function that will automatically be called on program termination vis std::exit()
// This allows you to specify a cleanup function in one place and then not have to worry about remembering to call that function explicity before calling std::exit()
// The function passed into std::atexit() must take no parameters and return no value
// You can register multiple cleanup functions and they will be called in reverse order

// There are a seperate set of these functions for multithreaded programs. Not going to write them but be aware that they exist

// Abnormal termination means the program had some kind of unusual runtime error and the program couldn't continue to run

// std::abort() causes your program to terminate abnormally
// It does no cleanup

// std::terminate() is typically used in conjunction with unhandled exceptions. It calls std::abort()

// Best practice: only use halt if there is no safe way to return normally from the main function

/*
    7.13
*/
// Best practice: write your program in smal, well-defined units (functions or classes), compile often, and test your code as you go

/*
    7.14
*/
// Code coverage is used to describe how much of the source code of a program is executed while testing 
// Statement coverage refers to the percentage of statements in your code that have been excercised by your testing routines
// Branch coverage refers to the percentage of branches that have been executed, each possible branch counted seperately

// Best practice: aim for 100% branch coverage of your code

// Loop coverage says that if you have a loop in your code, you should ensure that it works properly when it iterates 0 times, 1 time, and 2 times

// Best practice: use the 0, 1, 2 test to ensure your loops work correctly with different numbers of iterations 

// Best practice: test different categories of input values to make sure your unit handles them properly

/*
    7.17
*/
// A program that handles error cases well is said to be robust

// operator>> is called the extraction operator when used in the context of std::cin
// When the user enters input in response to an extraction operation, the data is placed in a buffer inside of std::cin
// A buffer (also called a data buffer) is simply a piece of memory set aside for storing data temporarily while it's moved from one place to another
// When the extraction operator is used, the following procedure happend:
/*
    * If there is data already in the input buffer, that data is used for extraction
    * If the input buffer contains no data, the user is asked to input data for extraction (this is the case most of the time). 
        When the user hits enter, a ‘\n’ character will be placed in the input buffer
    * operator>> extracts as much data from the input buffer as it can into the variable (ignoring any leading whitespace characters, such as spaces, tabs, or ‘\n’)
    * Any data that can not be extracted is left in the input buffer for the next extraction
*/

/*
    7.18
*/
// In programming, a precondition is any condition that must always be true prior to the execution of a component of code
// An invariant is a condition that must be true while some component is executing
// A postcondition is something that must be true after the execution of some component of code

// An assertion is an expression that will be true unless there is a bug in the program
// In C++, runtime asseritons are implemented via the assert preprocessor macro, which lives in the <cassert> header
// You can use a logical-AND operator along with the assert condition to print a little message along with the assertion error

// Best practice: use assertions to document cases that should be logically impossible

// Using the macro NDEBUG disables assertion macros

// static_assert is an assetion that is checked at compile-time and thus raises compiler errors, so it doesn't need a header included:
// static_assert(condition, diagnostic_message)
// Because it's evaluated by the compiler, the condition must be a constant expression
// static_assert can be placed anywhere in the code file
// startic_assert is not compiled out in release builds

/*
    7.19
*/
// An algorithm is considered stateful if it retains some information across calls 
// Deterministic algorithms always produce the same output sequence 
// PRNGs

/*
    7.20
*/
// The Mersenne Twister
// To access any of the randomization capabilities in C++, we include the <random> header of the standard library
#include <random>
// The library has support for two Mersenne Twister types:
// mt19937 (32-bit unsigned integers)
// mt19937_64 (64-bin unsigned integers)

int main()
{
    std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << mt() << '\t'; // generate a random number

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }

    return 0;
}

// A uniform distribution is a random number distribution that produces outputs between two numbers X and Y (inclusive) with equal probability

// Best practice: use std::random_device to seed your PRNGs (unless it's not implemented properly for your target compiler/architecture

// Best practice: ony seed a given pseudo-random number generator once, and do not reseed it

