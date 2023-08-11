#include <iostream>

/*
    CHAPTER 5
*/

/*
    5.1
*/
// An expression that has multiple operators is called a compound expression
// Operators are evaluated by the compiler in the order given by their precedence level (5 for mult and divis, 6 for addition and sub)
// If two operators with the same precedence level are adjacent to each other in an expression, the operator's associativity tells the compiler whether to
//      evaluate the operators from left to right or from right to left
// See https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/ for a table with all operator precedence levels associativity

// Best practice: Use parentheses to make it clear how a non-trivial compound expression should evaluate (even if they are technically unnecessary)

// Best practice:: expressions with a single assignment operator do not need to have the right operand of hte assignment wrapped in parenthesis 

// The C++ standard uses the term value computation to mean the execution of operators in an expression to produce a value 

// Key insight: operands, function agruments, and subexpression may be evaluated in any order by the compiler 
// Ensure that the expressions (or function calls) you write are not dependent on operand (or argument) evaluation order

/*
    5.2
*/
// If both operands are integers, the division operator performs integer division instead.
// Integer division drops and fractions and returns an integer value

/*
    5.3
*/
// Best practice: prefer to compare the result of the remainder operator (%) against 0 if possible

// To do exponents in C++, #include <cmath> and use the pow() function
// Note that the parameters (and return value) of function pow() are of type double.

// In the vast majority of cases, integer exponentiation will overflow the integral type. This is likely why such a function wasn't included in the standard library

/*
    5.4
*/
// Postfix increment/decrement operators:
// First, a copy of the operand is made. Then the operand (not the copy) is incremented or decremented. Finally, the copy (not the original) is evaluated
// Best practice: Strongly favor the prefix version of the increment and decrement operators, as they are generally more performant and better behaved

// A function or expression is said to have a side effect if it has some observable effect beyond producing a return value
// Warning: C++ does not define hte order of evaluation for function arguments or the operands of operators 
// Warning: Don't use a variable that has a side effect applied to it more than once in a given statement. If you do, the result may be undefined 

/*
    5.5
*/
// The comma operator (,) allows you to evaluate multiple expressions whenever a single expression is allowed
// Best practice: avoid using the comma operator, except within for loops 

// The conditional operator (?:) (also sometimes called the "arithmetic if" operator) is a ternary operator
// C++'s only ternary operator 
// The ?: operator provides a shorthand method for doing a particular type of if/else statement:
// (condition) ? expression1 : expression2
// If condition evaluates to true, then expression1 is executed, otherwise expression2 is executed. Note that expression2 is not optional

// Best practice: always parenthesize the conditional part of the conditional operator, and consider parenthesizing the whole thing as well

// Conditional operator can be used for stuff like this:
// constexpr int classSize { inBigClassroom ? 30 : 20 };
// Which takes a lot more effort without it

// The type of expressions used in conjunction with the conditional operator must be the same or be convertible 

// Best practice: only use the conditional operator for simple conditionals where you use the result and where it enhances readability

/*
    5.6
*/
// Relational Operators are operators that let you compare two values
// Best practice: Don't add unnecessary == or != to conditions. It makes them harder to read without offering any additional value

/*
    5.7
*/
// Logical NOT Operator: !
// Ex: !x, true if x is false, or false if x is true
// Logical AND Operator: &&
// Ex: x && y
// Logical OR: ||
// Ex: x || y

// Best practice: If logical NOT is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses

// In order for logical AND to return true, both operands must evaluate to true
// So, if the first operand evaluates to false, it just returns false and doesn't bother to check the second one
// This is called a short circuit evaluation
// logical OR does this too
// This is not true with your own classes which have overloaded the operators 

// Best practice: when mixing logical AND and logical OR in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intended

#if 0
int main()
{
    int x = { 1 };
    std::cout << x << '\n';
    x = ++x;
    std::cout << x << '\n';
    return 0;
}
#endif
