#include <iostream>

/*
    CHAPTER 13 R
*/

/*
    13.1
*/
// OOP

/*
    13.2
*/
// Classes can be defined using the class keyword
// Functions defined inside of a class are called member functions (or sometimes methods)
// Member functions can be defined inside or outside the class definition. We'll define them inside the class for now, and show how to define them outside the class later
// Members (variables and functions) of a class are accessed using the member selection operator (.)

// With non-member functions, we have to pass data to the function to work with. With member functions, we can assume we always have an implicit object of the class to work with

// Best practice: name your classes starting with a capital letter

// In addition to member variables and member functions, classes can have member types or nested types (including type aliases)
// Inside the class we can access the names of nested types without a scope qualifier. However, from outside we must use the class name as a qualifier
// Nested types cannot be forward declared

// Best practice: use the struct keyword for data-only structures. Use the class keyword for objects that have both data and functions 

/*
    13.3
*/
// Public members are members of a struct or class that can be accessed directly by anyone, including from code that exists outside the struct or class
// All struct members are public members by default
// Private members are members of a class that can not be accessed by the public
// By default, all class members are private
// Private members can only be accessed by other members of the class (or by friends of the class)

// We can make class members public by using the public keyword
// Access specifiers (like public) determine who has access to the members that follow the specifier

// Best practice: make member variables private, and member functions public, unless you have a good reason not to

// The group of public members of a class are often referred to as a public interface

/*
    13.4
*/
// In object-oriented programming, Encapsulation (also called information hiding) is the process of keeping the details about how an object is implemented hidden away from users
// Instead, users access the object through a public interface

// Depending on the class, it can be appropriate for us to be able to directly get or set the value of a private member variable
// An access function is sa short public function whose job is to retrieve or change the value of a private member variable
// Getters are functions that return the value of a private member variable, setters are functions that set the value of a private member variable

// Best practice: getters should provide "read-only" access to data. Therefore, the best practice is that they should return by value or constant reference

// Class members can be declared in any order we like, but

// Best practice: declare public members first, protected members next, and private members last. This spotlights the public interface and de-emphasizes implementation details

/*
    13.5
*/
// When all members of a class (or struct) are public, we can use aggregate initializaiton to initialize the class (or struct) directly using list-initialization
// But this is no longer possible with private members

// A constructor is a special kind of class member function that is automatically called when an object of that class is constructed 
// Constructors are typically used to initialize member variables of the class to appropriate user-provided values, or to do any necessary setups

// Constructors must have the same name as the class (including caps)
// Constructors have no return type

// A constructor that takes no parameters (or has parameters that all have default values) is called a default constructor
// The default constructor is called if no user-provided initialization values are provided

// Best practice: favor value-initialization over default-initialization for class objects

// Best practice: favor brace initialization to initialize class objects

// If your class has no constructors, C++ will automatically generate a public default constructor for you
// This is someitmes called an implicit constructor

// Best practice: if you have constructors in your class and need a default constructor that does nothing (e.g. because all your members are initialized using non-static
//      member initialization), use = default

// Member classes have their default constructors called before the body of the outer class constructor is executed

// Best practice: always initialize all member variables in your objects

/*
    13.6
*/
// Class members are best initialized via a member initialization list
class Something
{
private:
    int m_value1 {};
    double m_value2{};
    char m_value3{};

public:
    Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } // Initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};
// The member initializer list is inserted after the constructor parameters. It begins with a colon (:), and then lists each variable to initialize along with 
//      the value for that variable separated by a comma

// Best practice: use member initializer lists to initialize your class member variables instead of assignment

// Const member variables must be initialized

// a member initialization list can also be used to initialize members that are classes

// Variables in the initializer list are initialized in the order in which they are declared in the class
// As a result, it's a good idea to initialize variables in the initializer list in the same order in which they are declared in the class

/*
    13.7
*/
// Non-static member initialization provides default values for your member variables that your constructors will use if the constructors do not provide initialization values
//      for the members themselves (via the member initialization list):
// class Something
// {
// private:
//     int m_value1 { 1 };
//     double m_value2{ 2.1 };
//     char m_value3{ 'a' };
// If we've provided defaults but still assign values using the member initialization list, the list will take precedence 

// Best practice: favor use of non-static member initialization to give default values for your member variables

/*
    13.8
*/
// Constructors are allowed to call other constructors from the same class. This process is called delegating constructors
// To have one constructor call another, simply call the constructor in the member initializer list
// A constructor that delegates to another constructor is not allowed to do any member initialization itself
// Do not delegate a constructor to another that delegates back to the original. This will form an infinite loop and crash the program

// Best practice: if you have multiple constructors that have the same functionality, use delegating constructors to avoid duplicate code

// Constructors are allowed to call other non-constructor functions. It's a good idea to make a seperate function for setup if necessary and then just call it

// You can make a reset method by assigning a new, default instance of your class to the implicit object using *this

/*
    13.9
*/
// A destructor is another special kind of class member function that is executed when an object of that class is destroyed
// If your class is holding any resources (e.g. dynamic memory, or a file or database handle), or if you need to do any kind of maintenance before the object is destroyed, the 
//      destructor is the perfect place to do so

// Like constructors, destructors have specific naming rules:
// The destructor must have the same name as the class, preceded by a tilde
// The destructor cannot take arguments
// The destructor has no return type

// A class can only have a single destructor
// Destructors may safely call other member functions since the object isn't destroyed until after the destructor executes

// RAII (Resource Acquisition Is Initialization) is a programming technique whereby resource use is tied to the lifetime of objects with automatic duration

/*
    13.10
*/
// C++ uses a hidden pointer called "this" to keep track of which object member functions are called on
// The "this" pointer is a hidden const pointer that holds the address of the object the member function was called on

// Consider adding a m_ prefix to all member variables

// "this" is useful for chaining member functions together
// You just have functions that otherwise would've returned void instead return references to *this

/*
    13.11
*/
// C++ provides a way to separate the "Declaration" portion of the class from the "implementation" portion
// This is done by defining the class member functions outside of the class definition
// To do so, simply define the member functions of the class as if they were normal functions, but prefix the name to the function using the scope resolution operator

// Because access functions are often only one line, they are typically left in the class definition

// Class definitions can be put into header files in order to facilitate reuse in multiple projects
// Traditionally, the class definition is put in a header file of the same name as the class, and the member functions defined outside the class are put in a .cpp file of the same name

// We recommend doing the following:
/*
    * For classes used in only one file that aren’t generally reusable, define them directly in the single .cpp file they’re used in
    * For classes used in multiple files, or intended for general reuse, define them in a .h file that has the same name as the class
    * Trivial member functions (trivial constructors or destructors, access functions, etc…) can be defined inside the class
    * Non-trivial member functions should be defined in a .cpp file that has the same name as the class
*/

// Default parameters for member functions should be declared in the class definition (in the header file), where they can be seen by whomever #includes the header

// Separating the class definition and class implementation is very common for libraries that you can use to extend your program

/*
    13.12
*/
// Const class objects can also be created by the const keyword
// Once a const class object has been initialized by the constructor, any attempt to modify the member variables of the object is disallowed
// const class objects can only explicitly call const member functions 

// A const member function is a member function that guarantees it will not modify the object or call any non-const member functions
// To make a member function const, we simply append the const keyword to the function prototype, after the parameter list, but before the function body
// For member functions outside of the class definition, the const keyword must be used on both the function prototype in the class definition and on the function definition

// Best practice: make any member function that does not modify the state of the class object const, so that it can be called by const objects

// Remember that passing class objects by const reference into functions makes the object being operated on by the function constant

// Const members can not return non-const references to members

// It is possible to have const and non-const versions of the same function

/*
    13.13
*/
// Member variables of a class can be made static by using the static keyword
// Unlike normal member variables, static member variables are shared by all objects of the class

// Note: static members are not technically associated with class objects. It's more like they belong to the class itself

// Best practice: access static members by class name (using the scope resolution operator) rather than through an object of the class (using the member selection operator)

// You must explicitly define the static member outside of the class, in the global scope:
// int Something::s_value{ 1 }; // defines the static member variable
// Note that this static member definition is not subject to access controls: you can define and initialize the variable even if it's declared as private 

// static class variables are never placed in header files
// Put them either in the associated code file or below the class definition (if the def is in a .cpp file)

// static const members can be initialized inside the class if they are an integral type
// static constexpr members can be initialized inside the class definition
// After C++17, non-const static members can be initialized inside the class definition if we declare them inline

// Best practice: prefer initializing static constexpr members at the point of definition
//      Prefer making static non-constexpr members inline and initializing them at the point of definition

/*
    13.14
*/
// Like static member variables, static member functions are not attached to any particular object
// Because static member functions are not attached to a particular objectm they can be called directly by using the class name and scope resolution operator

// Static member functions have no *this pointer
// Static member functions can directly access other static members, but not non-static members

/*
    13.15
*/
// A friend function is a function than can access the private members of a class as though it was a member of that class
// To declare a friend function, simply use the friend keyword in front of the prototype of the function you wish to be a friend of the class

// A function can be a friend of more than one class at the same time

// It is also possible to make an entire class a friend of another class
// If you want two classes to be friends of each other, both must declare the other as a friend

// You can also make individual member functions friends

/*
    13.16
*/
// An anonymous objects is essentially a value that has no name
// Anonymous objects can be created out of class objects as well, jsut omit the variable name

/*
    13.17
*/
// In C++, types can be defined (nested) inside of a class
// Classes essentially act as a namespace for any nested types 

// It is fairly uncommon for classes to have other classes as a nested type, but it is possible
// Nested classes do not have access to the *this pointer of the outer class, but they can access the outer classes' private members (that are in scope)

/*
    13.18
*/
// You can time stuff in C++ using the chrono library (arcane)
// Or use the timing class provided here: https://www.learncpp.com/cpp-tutorial/timing-your-code/

#if 0
int main()
{
    return 0;
}
#endif