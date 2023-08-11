#include <iostream>

/*
    CHAPTER 9 R
*/

/*
    9.1
*/
// C++ supports a second set of data types called compound data types
// Compound data types are data types that can be constructed from fundamental data types
// Each compound data type has its own unique properties as well

/*
    9.2
*/
// All expressions in C++ have two properties: a type and a value category
// The type of the expression is equivalent to the type of the value, object, or function that results from the evaluated expression
// The type of an expression must be determinable at compile time

// The value category of an expression (or subexpression) indicates whether an expression resolved to a value, a function, or an object of some kind 
// After C++11, there are five value categories: lvalue, rvalue, glvalue, prvalue, and xvalue
// The last three were added with C++11 to support a feature called move semantics

// An lvalue is an expression that evaluates to an identifiable object or funciton (or bit-field)
// The term "identity" is used by the C++ standard
// Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement:
// int x = { 5 };
// int y = { x };  // x is an lvalue expression
// A modifiable lvalue is an lvalue whose value can be modified
// A non-modifiable lvalue is an lvalue whose value can't be modified (because the lvalue is const or constexpr)

// An rvalue is an expression that is not an lvalue
// Commonly seen rvalues include literals (except C-style string literals), and the return value of functions and operators
// rvalues aren't identifiable and only exist within the scope of the expression in which they are used

// An assignment operation requires the left operand of the assignment to be a modifiable lvalue expression and the right operand to be an rvalue expression
// lvalues will implicitly convert into rvalues in cases like this: x = y;

/*
    9.3
*/
// In C++, a reference is an alias for an existing object
// Once a reference has been defined, any operation on the reference is applied to the object being referenced

// Modern C++ contains two types of references: lvalue and rvalue references. We'll be talking about lvalue references here

// An lvalue reference acts as an alias for an existing lvalue 
// To declare an lvalue reference type, we use an ampersand (&) in the type declaration:
// int&

// An lvalue reference variable is a variable that acts as a reference to an lvalue
// To create an lvalue reference variable, we simply define a variable with an lvalue reference type:
// int x = { 5 };
// int& ref = { x };

// Best practice: when defining a reference, place the ampersand next to the type (not the reference variable's name)

// Like all constants, all references must be initialized
// When a reference is initialized with an object (or function), we say it is bound to that object (or function)
// lvalue references must be bound to a *modifiable* value (i.e. something like int& x = { y }; where y is const or constexpr wouldn't work)

// In most cases, the type of the reference must match the type of the referent 
// lvalue references to void are disallowed

// Once initialized, a reference in C++ cannot be reseated, meanign it cannot be changed to reference another object

// Reference variables follow the same scoping and duration rules that normal variables do
// With one exception, the lifetime of a reference and the lifetime of its referent are independent
// When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists
// Such a reference is called a dangling reference. Accessing a dangling reference leads to undefined behavior

// References aren't objects, and as such they can't be used anywhere an object is required 

/*
    9.4
*/
// By using the const value when declaring an lvalue reference, we tell an lvalue reference to treat the object it is refering as a const
// Such a reference is called an lvalue reference to a const value
// Because lvalue references to const treat the object they are referencing as const, they can be used to access but not modify the value being referenced

// lvalue references to a const can also bind to modifiable values. In such a case, the object being referenced is treated as a const when accessed throug the reference

// Best practice: favor lvalue references to const over lvalue references to non-const unless you need to modify the object being referenced

// lvalues references to const can also bind to rvalues
// When this happens, a temporary object is created and initialized with the rvalue, and the refernece to cosnt is boudn to that temporary object
// A temporary object (or anonymous object) is an object that is created for temp use (and then destroyed) within a single expression
// Temp objects have no scope

// When a const lvalue reference is bound to a temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference

/*
    9.5
*/
// An argument passed to a function is copied into the function's parameter. The parameter is then used normally by the function and destroyed when the function is finished executing
// Some objects are expensive to copy though
// One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value
// When using pass by reference, we declare a function parameter as a reference type rather than as a normal type
// When the funciton is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy is made

// When using pass by reference, any changes made to the reference parameter *will* affect the argument

// Unfortunately, pass by reference only works with arguments that are modifiable lvalues. There is a way around this though
// pass by constant reference (just add const to the beginning of the function parameter you're trying to pass by reference)
// This will also ensure that the function can't modify the argument passed into it

// Best practice: favor passing by const reference over passing by non-const reference unless you have a specific reason to do otherwise

// Without the ability to bind const lvalue references to rvalues, there wouldn't be a way to pass literals to functions that use pass by reference

// Best practice: as a rule of thumb, pass fundamental types by value, and class (or struct) types by const reference

// Best practice: prefer pass by value for objects that are cheap to copy, and pass by const reference for objects that are expensive to copy.
//      If you're not sure whether an object is cheap or expensive to copy, favor pass by const reference

// Best practice: prefer passing strings using std::string_view (by value) instead of const std::string&, unless your function calls other functions that require C-style strings
//      or std::string parameters

/*
    9.6
*/
// The address of operator (&) returns the memory address of its operand:
// int x = { 5 };
// std::cout << &x;  // prints the memory address of x

// The dereference operator (*) returns the value at a given memory address lvalue:
// std::cout << *(&x);  // prints the value at the memory address of x (basically the value of x)

// A pointer is an object that holds a *memory address* as its value
// Pointer types are declared using an asterisk 
// int* ptr = { &x } // contains the memory address of x

// Best practice: when declaring a pointer type, place the asterisk next to the type name

// Best practice: Always initialize your pointers

// The type of the pointer has to match the type of the object being pointed to
// With one exception, initializing a pointer with a literal value is disallowed

// We can use assignment with pointers in two different ways:
// To change what the pointer is pointing at (by assigning the pointer a new address):
//ptr = &z;  // changes ptr to point to z
// To change the value being pointed at (by assigning the dereferenced pointer a new value):
// *ptr x = 6  // changes the value of x to 6

// Pointers are objects

// the address of (&) returns a pointer containing the address of the operand

// The size of a pointer is always the same and varies with architecture

// A dangling pointer is a pointer that is holding the address of an object that is no longer valid
// Dereferencing an invalid pointer will lead to undefined behavior

/*
    9.7
*/
// A null value is a special value that means something has no value
// Null pointers are pointers that hold a null value, and thus point at nothing:
// int* ptr = {};  // initializing a null pointer

// Best practice: value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object

// The nullptr keyword represents a null pointer literal. We can use nullptr to explicitly initialize or assign a pointer a null value

// Best practice: use nullptr when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function

// We can use a conditional to test whether a pointer has value nullptr or not:
// if (ptr == nullptr) do something;
// Null pointers implicitly convert to false so the conditional isn't really necessary. Other pointers convert to true

// Best practice: a pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for null, and can assume any non-null 
//      pointer is valid

// Best practice: favor references over pointers unless the additional capabilities provided by pointers are needed

/*
    9.8
*/
// non-const pointers can't point at const variables
// pointers to constant values can be declared using const:
// const int* ptr = { &x };
// Just like a reference to const, a pointer to const can point to non-const variables too (while treating the value of the variable as constant no matter what)

// A const pointer is a pointer whose address can not be changed after initialization:
// int* const ptr = { &x };
// These must be initialized upon definition

// const pointer to a const value:
// const int* const prt = { &x };

/*
    9.9
*/
// With pass by address, instead of providing an object as an argument, the caller provides an object's address (via a pointer)
// This pointer is copied into a pointer parameter of the called function. The function can then dereference that pointer to access the object whose address was passed
// Pass by address does not make a copy of the object being pointed to
// Pass by address allows the function to modify the argument's value

// Best practice: prefer pass by reference to pass by address unless you have a specific reason to use pass by address

/*
    9.10
*/
// pass by address by reference:
// void nullify(int*& refptr)  //refptr is now a reference to a pointer

// If we want to write a function that accepts only a nullptr literal argument, we can make the parameter a std::nullptr_t (the type of nullptr)

/*
    9.11
*/
// When returning, a copy is normally passed back to caller
// Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the return value:
// const int& returnByConstReference()
// The only caveat of this is that the object that the reference refers to must still exist after the function has been executed

// Reference lifetime extension does not work across function boundaries

// Best practice: avoid returning references to non-const local static variables

// It's okay to return reference parameters by reference 

// The caller can modify values through the reference

// Return by address also exists and shares the same caveat that return by reference has: the object the pointer points too must still exist after function execution
// The major advantage of return by address over return by reference is that we can return nullptr

// Best practice: prefer return by reference over return by address unless the ability to return "no object" (using nullptr) is needed

/*
    9.12
*/
// By default, type decuction will drop references 

// A top-level const is a const qualifier that applies to an object itself
// A low-level const qualifier is a const qualifier that applied to the object being referenced or pointed to
// A reference to a const value is always a low-level const. A pointer can have a top-lvevl, low-level, or both kinds of const

// Best practice: if you want a const reference, reapply the const qualifier even when it's not strictly necessary, as it makes your intent clear and helps prevent mistakes

// constexpr references work the same way as const references

// Best practice: If you want a const pointer, reapply the const qualifier even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.

#if 0
int main()
{
    return 0;
}
#endif


