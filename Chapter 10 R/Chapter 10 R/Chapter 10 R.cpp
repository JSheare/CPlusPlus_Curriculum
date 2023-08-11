#include <iostream>

/*
    CHAPTER 10 R
*/

/*
    10.1
*/
// C++ allows for program-defined types (user defined types)
// The definition for a program-defined type is called a type definition 
// Program-defind type definitions always end in a semicolon

// Best practice: Name your program-defined types starting with a capital letter and do not use a suffix

// Best practice: a program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible
//      A program-defined type used in multiple code files should be defined in a header file with the same names as the program-defined type and then #included where needed

// PD types are partially exempt from the one-definition rule with two caveats:
// Only one definition per code file allowed (header guards will ensure this)
// All type definitions for a given type must be identical, otherwise undefined behavior will result

/*
    10.2
*/
// An enumeration is a compound data type where every possible value is defined as a symbolic constant (called an enumerator)
// Unscoped enumerations are defined via the enum keyword

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

// Best practice: name your enumerated types starting with a capital letter. Name your enumerators staring with a lower case letter

// Each enumerated type you create is considered to be a distinct type, meaning the compiler can distinguish it from other types

// Enumerated types are best used when you have a smallish set of related constants, and objects only need to hold one of those values at a time

// Because enumerations are small and inexpensive to copy, it is fine to pass (and return) them by value

// Unscoped enumerations are named such because they put their enumerator names into the same scope as the enumeration definition itself
// As such, an enumerator name can't be used in multiple enumerations within the same scope

// unscoped enumerators can be accessed with the scope resolution operator (::) and the name of their enumeration

// Best practice: prefer putting your enumerations inside a named scope region (such as a namespace or class) os that the enumerators don't pollute the global namespace

// We can use the equality operators to test whether an enumeration has the value of a particular enumerator or not

/*
    10.3
*/
// Enumerators are integral symbolic constants. As a result, enumerated types actually hold an intergral value
// When we define an enumerator, each enumerator is automatically assigned an integer value based on its position in the enumerator list. By default, the first
//      enumerator is assigned the integral value 0, and each subsequent enumerator value has one greater than the previous enumerator

// It's possible to explicity define the value of enumerators (positive or negative integer literals) with =

// Best practice: avoid assigning explicit values to your enumerators unless you have a compelling reason to do so

// The specific integral type used to represent enumerators is called the underlying type (or base)
// Most compilers will use int as this base
// you can specify which type to use if you wish, but you probably shouldn't do this unless it's absolutely necessary

// Best practice: specify the base type of an enumeration only when necessary

// You can use static_cast to convert an integer to an enumerator
// You can also just use a list initialization in C++17 or greater

/*
    10.4
*/
// Scoped enumerations work similarly to unscoped enumerations, but have two primary differences:
// They aren't storngly typed (they won't implicitly convert to integers)
// They are strongly scoped (the enumerators are only placed into the scope region of the enumeration)
// To make a scoped enumeration, we use the keywords enum class

// Scoped enumerations define their own scope regions 
// As such, their enumerators must be accessed with the scope resolution operator (::)
// Scoped enumerations also don't implicitly convert to integers (or whatever the base type is)
// You can still use static_cast to convert them to integers (and vice versa) if necessary
 
// Best practice: favor scoped enumerations over unscoped enumerations unless there's a compelling reason to do otherwise

// In C++20 or greater you can using enum to import all of the enumerators from an enum into the current scope, so you don't need to use ::

/*
    10.5
*/
// A struct is a program-defined data type that allows us to bundle multiple variables together in a single type:
struct Employee
{
    int id {};
    int age {};
    double wage {};
};
// The variables that are part of the struct are called data members (or member variables)
// Defining a struct object:
// Employee joe;
// Accessing struct members"
// joe.age = 32; 
// std::cout << joe.age;
// . is called the member seleciton operator in this context

/*
    10.6
*/
// Struct data members are not initialized by default
// In generaly programming, an aggregate data type is any type that can contain multiple data members
// Aggregates use a form of initialization called aggregate initialization, which allows us to directly initialize the members of aggregates
// To do this we provide an initializer list as an initializer, which is just a list of comma-separated initialization values
// Employee joe {2, 28, 45000.0};
// Each of these does a memberwise initialization, which means each member in the struct is initialized in the order of the declaration

// Best practice: prefer the (non-copy) braced list form when initializaing aggregates

// If an aggregate is initialized but the number of initialization values is fewer than the number of members, then all remaining members will be value-initialized

// Variables of a struct can const (or constexpr), and just like all const variables, they must be initialized

// In C++20 or greater you can also initialize using designated initiators (.member_name) to reduce member initialization ambiguity:
// Employee joe {.id {2}, .age {28}, .wage {45000.0}};

// Best practice: when adding a new member to an aggregate, it's safest to add it to the bottom of the definition list so the initializers for other members don't shift

// Assignment with a list also works:
// joe = {2, 39, 66000.0};
// Designated initiators work here too

/*
    10.7
*/
// When we define a struct (or class) type, we can provide a default initialization value for each member as part of the type definition
// This process is called non-static member initialization, and the initialization value is called a default member initializer 

// Explicit initialization values take precedence over default values

// Best practice: provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn't include an initializer list

// Best practice: if no explicit initializer values will be provided for an aggregate, prefer value initialization (with an empty braces initializer) to default initialization

/*
    10.8
*/
// Structs are generally passed by const reference into functions to avoid making copies

// If you want to return multiple things from a function, a common way to do it is with a struct
// Return the struct as an anonymous object

/*
    10.9
*/
// In C++, structs (and classes) can have members that are other program-defined types
// Either you can use a type that's already been defined in the global namespace or you can nest the type inside of the one that uses it

// The (memory) size of a struct will be at least as large as the size of all the variables it contains. But it could be larger!
// For performance reasons, the compiler will sometimes add gaps into structures (this is called padding)

/*
    10.10
*/
// Since references to an object act just like the object itself, we can also use the member selection operator (.) to select a member from a reference to a struct
void printEmployee(const Employee& e)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

// However, using the (.) doesn't work if you have a pointer to a struct
// You would need to dereference it first
// To make for a clearer syntax, C++ offers a member seleciton from pointer operator (->) that can be used to select members from a pointer to an object
// Employee* ptr{ &joe };
// std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object

// Best practice: when using a pointer to access the value of a member, use the member seletion from pointer operator (->) instead of the member selection operator(.)

/*
    10.11
*/
// Much like a function template is a template definition for instantiating functions, a class template is a template definition for instantiating class types
template <typename T>
struct Pair
{
    T first {};
    T second {};
};
// Inside main() we can instantiate Pair objects using whatever types we desire (i.e. Pair<int> for an int one)

// Because working with pairs of data is common, the C++ standard library contains a class template named std::pair in the <utility> header
// We developed our own Pair class in this lesson to show how things work, but in real code, you should favor std::pair over writing your own

// Just like funciton templates, class templates are typically defined in header files so they can be included into any code file that needs them

/*
    10.12
*/
// Starting in C++17, when instantiating an object from a class template, the compiler can deduce the template types from the types of the object's initializer
// This is called class template argument deduction or CTAD for short:
// std::pair<int, int> p1{ 1, 2 }; // explicitly specify class template std::pair<int, int> (C++11 onward)
// std::pair p2{ 1, 2 };           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)
// std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
// std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

// Usually CTAD works right out of the box, but sometimes the compiler still needs a little help with the deduction
// We can provide a deduction guide for these cases
// Here's a deduction guide for our Pair (needed in C++17)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
// template <typename T, typename U>
// Pair(T, U) -> Pair<T, U>;
// This should happen automatically for aggregates in C++20 or greater

// Just like function parameters can have default arguments, template parameters can be given default values
// These will be used when the template parameter isn't explicitly specified and can't be deduced:
//template <typename T = int, typename U = int> // default T and U to type int
// struct Pair
// {
//     T first{};
//     U second{};
// };
// 
// template <typename T, typename U>
// Pair(T, U) -> Pair<T, U>;


#if 0
int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // my apple is red
    Color shirt { green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    //Color socks{ white }; // error: white is not an enumerator of Color
    //Color hat{ 2 };       // error: 2 is not an enumerator of Color

    return 0;
}
#endif


