#include <iostream>

/*
    CHPATER 14 R
*/

/*
    14.1
*/
// Using function overloading to overload operators is called operator overloading 
// When evaluating an expression containing an operator, the compiler uses the following rules
// If all of the operands are fundamental types, the compiler will call a built-in routine if one exists. If not, you get a compiler error
// If any of the operands are program-defined types, the compiler will use the function overload resoultion algorithm to find an unambiguous match.
//      If no match can be found (or an ambiguous match is found), the compiler will error

// Almost any operator can be overloaded in C++
// The exceptions are: conditional (?), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the casting operators
// You can only overload operators that exist (no custom operators)
// At least one of the operands in an overload operator must be a user-defined type

// Best practice: an overloaded operator should operate on at least one program-defined type (either as a parameter of the function, or the implicit object)

// It is not possible to change the number of operands an operator supports 
// It is also not possible to change the operators' precedence

// Best practice: when overloading operators, it's best to keep the function of the operators as close to the original intent of the operators as possible 

// Best practice: if the meaning of an overloaded operator is not clear and intuitive, use a named function instead

// Best practice: operators that do not modify their operands (e.g. arithmetic operators) should generally return results by value
//      Operators that modify their leftmost operand should generally return the leftmost operand by reference 

/*
    14.2
*/
// Overloading operators using friend functions
// The following example shows how to overload operator plus (+) in order to add two "Cents" objects together

class Cents
{
private:
	int m_cents {};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);
    Cents operator-() const;

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + c2.m_cents;
}

//int main()
//{
//	Cents cents1{ 6 };
//	Cents cents2{ 8 };
//	Cents centsSum{ cents1 + cents2 };
//	std::cout << "I have " << centsSum.getCents() << " cents.\n";
//
//	return 0;
//}

// Overloading the plus operator is as simple as declaring a function named operator+, giving it two parameters of the type of operands we want to add, picking an appropriate 
//		return type, and then writing the function 

// Even though friend functions aer not members of the class, they can still be defined inside the class if desired
// We don't recommend this, as non-trivial function definitions are better kept in a separate .cpp file, outside of the class definition

// It is often possible to define overloaded operators by calling other overloaded operators. You should do this if and when doing so produces simpler code

/*
	14.3
*/
// You can also overload operators with normal functions 

// Best practice: prefer overloading operators as normal funcitons instead of friends it it's possible to do so without adding additonal functions

/*
	14.4
*/
// Overloading operator<< is similar to overloading operator+, except that the parameter types are different
// std::cout is actually an object of type std::ostream. Therefore, out overloaded function will look like this:
// friend std::ostream& operator<< (std::ostream& out, const Point& point);
class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')'; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

//int main()
//{
//    const Point point1{ 2.0, 3.0, 4.0 };
//
//    std::cout << point1 << '\n';
//
//    return 0;
//}

// We return std::ostream as a reference because returning by value results in a compiler error

// Any time we rant our overloaded binary operators to be chainable, the left operand should be returned (by reference)

// It is also possible to overload the >> operator
// std::cin is an object of type std::istream

/*
    14.5
*/
// Overloading operators using a member function is very similar to overloading operators using a friend function. When overloading an operator using a member function:
// The overloaded operator must be added as a member function of the left operand
// The left operand becomes the implicit *this object
// All other operands become function parameters

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
//Cents Cents::operator+ (int value)
//{
//    return Cents{ m_cents + value };
//}

// Note everything can be overloaded as a friend function
// The assignment (=), subscript([]), function call (()), and member selection (->) operators must be overloaded as member functions, because the language requires them to be

// Not everything can be overloaded as a member function
// I/O operators must be overloaded as regular functions (preferred) or friend functions 

// The following rules of thumb can help you determine whether to overload using a regular function or member function:
/*
    * If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function
    * If you’re overloading a unary operator, do so as a member function
    * If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function
    * If you’re overloading a binary operator that modifies its left operand, but you can’t add members to the class definition of the left operand
    *       (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function
    * If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function
*/

/*
    14.6
*/
// Because they only operate on the object they are applied to, typically unary operator overloads are implemented as member functions
// note: this function is a member function!
Cents Cents::operator-() const
{
    return -m_cents; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}
// Our overloaded negative operator (-) is a unary operator implemented as a member function, so it takes no parameters (operates on the *this object)
// it returns a Cents object that is the negation of the original cents value
// Because the operator- does not modify the Cents object, we can (and should) make it a const function (so it can be called on const Cents objects)

/*
    14.7
*/
// Comparison operater overloading
// Because the comparison operators are all binary operators that do not modify their left operands, we will make our overloaded comparison operators friend functions
#include <string>
#include <string_view>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}

//int main()
//{
//    Car corolla{ "Toyota", "Corolla" };
//    Car camry{ "Toyota", "Camry" };
//
//    if (corolla == camry)
//        std::cout << "a Corolla and Camry are the same.\n";
//
//    if (corolla != camry)
//        std::cout << "a Corolla and Camry are not the same.\n";
//
//    return 0;
//}

// Best practice: only define overloaded operators that make intuitive sense for your class

// Overloaded comparison operators tend to have a high degree of redundancy, and the more complex the implementation, the more redundancy there will be
// Fortunately, many of the comparison operators can be implemented using the other comparison operators:
// friend bool operator== (const Cents& c1, const Cents& c2) { return c1.m_cents == c2.m_cents; };
// friend bool operator!= (const Cents& c1, const Cents& c2) { return !(operator==(c1, c2)); };
// 
// friend bool operator< (const Cents& c1, const Cents& c2) { return c1.m_cents < c2.m_cents; };
// friend bool operator> (const Cents& c1, const Cents& c2) { return operator<(c2, c1); };
// 
// friend bool operator<= (const Cents& c1, const Cents& c2) { return !(operator>(c1, c2)); };
// friend bool operator>= (const Cents& c1, const Cents& c2) { return !(operator<(c1, c2)); };

/*
    14.8
*/
// Overloading the increment (++) and decrement (--) operators is pretty straightforward, with one small exception
// There are actually two versions of the increment and decrement operators: a prefix increment and decrement and a postfix increment and decrement
// Because the increment and decrement operators are both unary operators and they modify their operands, they're best overloaded as member functions 

// Overloading increment and decrement
class Digit
{
private:
    int m_digit;
public:
    Digit(int digit = 0)
        : m_digit{ digit }
    {
    }

    Digit& operator++(); // prefix has no parameter
    Digit& operator--(); // prefix has no parameter

    Digit operator++(int); // postfix has an int parameter
    Digit operator--(int); // postfix has an int parameter

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

// No parameter means this is prefix operator++
Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

// No parameter means this is prefix operator--
Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

// int parameter means this is postfix operator++
Digit Digit::operator++(int)
{
    // Create a temporary variable with our current digit
    Digit temp{ *this };

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

// int parameter means this is postfix operator--
Digit Digit::operator--(int)
{
    // Create a temporary variable with our current digit
    Digit temp{ *this };

    // Use prefix operator to decrement this digit
    --(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
    out << d.m_digit;
    return out;
}

//int main()
//{
//    Digit digit(5);
//
//    std::cout << digit;
//    std::cout << ++digit; // calls Digit::operator++();
//    std::cout << digit++; // calls Digit::operator++(int);
//    std::cout << digit;
//    std::cout << --digit; // calls Digit::operator--();
//    std::cout << digit--; // calls Digit::operator--(int);
//    std::cout << digit;
//
//    return 0;
//}

// Postfix operator overloads are distinguished from prefix operator overloads by an int parameter (postfix has one, prefix has no parameters)

/*
    14.9
*/
// Overloading the subscript ([]) operator
// Must be overloaded as a member function
// An overloaded operartor[] function will always take one parameter: the subscript that the user places between the hard braces
class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index)
{
    return m_list[index];
}

// We can define const and non-const versions of operator[] separately. The const version will be used with const-objects, and the non-const with non-const objects

// Rule: make sure you're not trying to call an overloaded operator[] on a pointer to an object

// The operator[] function parameter doesn't need to be an integer

/*
    14.10
*/
// Overloading the parenthesis operator
// Parenthesis operator overload must be implemented as a member function
// In the case of classes, operator() is just a normal operator that calls a function (named operator()) like any other overloaded operator
// It can take as many parameters as you want:
#include <cassert> // for assert()

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // for const objects
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

//int main()
//{
//    Matrix matrix;
//    matrix(1, 2) = 4.5;
//    std::cout << matrix(1, 2) << '\n';
//
//    return 0;
//}

// Operator() is also commonly overloaded to implement functors (or function object), which are classes that operate like functions
// The advanage of a functor over a normal function is that functors can store data in member variables

/*
    14.11
*/
// User-defined conversions allow usto convert our class into another data type
// Three things to note:
/*
    * To overload the function that casts our class to an int, we write a new function in our class called operator int(). Note that there is a space between the word
    *     operator and the type we are casting to. Such functions must be non-static members
    * User-defined conversions do not have parameters, as there is no way to pass arguments explicitly to them. They do still have a hidden *this parameter, pointing to the
    *    implicit object (which is the object to be converted)
    * User-defined conversions do not declare a return type. The name of the conversion (e.g. int) is used as the return type, as it is the only return type allowed.
    *       This prevents redundancy
*/

// // Overloaded int cast
// operator int() const { return m_cents; }
// 
// int getCents() const { return m_cents; }
// void setCents(int cents) { m_cents = cents; }

// You can provide user-defined conversions for any data type you wish including your own program-defined data types!

// Overloaded typecasts and converting constructors perform similar roles:
// An overloaded typecast allows us to define a function that converts some program-defined type A into some other type B
// A converting constructor allows us to define a function that creates some program-defined type A from some other type B
// In general, a converting constructor should be preferred to an overloaded typecast, as it allows the type being constructed to own the construction
// There are a few cases where an oerloaded typecast should be used instead:
/*
    * When providing a conversion to a fundamental type (since you can’t define constructors for these types)
    * When providing a conversion to a type you can’t add members to (e.g. a conversion to std::vector, since you can’t define constructors for these types either)
    * When you do not want the type being constructed to be aware of the type being converted to
*/

/*
    14.12
*/
// A copy constructor is a special type of constructor used to create a new object as a copy of an existing object (of hte same type)
// If you do not provide a copy constructor for your classes, C++ will create a public copy constructor for you
// The created copy constructor utilizes a method of initialization called memberwise initialization 
// Mmberwise initialization simply means that each member of the copy is initialized directly from the member class being copied
// Just like we can explicitly define a default constructor, we can also explicitly define a copy constructor:
class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }, m_denominator{ fraction.m_denominator }
        // Note: We can access the members of parameter fraction directly, because we're inside the Fraction class
    {
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

//int main()
//{
//    Fraction fiveThirds{ 5, 3 }; // Direct initialize a Fraction, calls Fraction(int, int) constructor
//    Fraction fCopy{ fiveThirds }; // Direct initialize -- with Fraction copy constructor
//    std::cout << fCopy << '\n';
//}

// Unlike with default constructors, it's fine to use the default copy constructor if it meets your needs

// The copy constructor's parameter must be a const reference

// We can prevent copies of our class from being made by making the copy constructor private

// The process of omititng certain copy (or move) steps for performance purposes is called elision
// The compiler does this sometimes to optimize

// The rule of three is a well-known C++ principle that states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator
//      then it probably requires all three. Not following the rule of three is likely to lead to malfunctioning code

// The rule of zero states, “Classes that have custom destructors, copy/move constructors or copy/move assignment operators should deal exclusively with 
//      ownership of dynamic memory or resources. Other classes should not have custom destructors, copy/move constructors or copy/move assignment operators.”
// The sentiment behind this rule is that a class should either model data or manage ownership of memory or resources. A class should not try to do both, as this 
//      would muddle the responsibility of the class

/*
    14.13
*/
// Copy initialization for classes
// Copy initialization may call both the class the constructor and the class copy constructor, which is inefficient
// While elision is usually performed by the compiler so that this doesn't happen, it isn't necessarily guaranteed

// Best practice: avoid using copy initialization and use uniform initialization instead

// When you pass or return a class by value, that process uses copy initialization

/*
    14.14
*/
// By default, C++ will treat any constructor as an implicit conversion operator
// Constructors eligible to be used for imnplicit conversions are called converting constructors 

// You can make constructors (and conversion functions) explicit via the explicit keyword, which is placed in front of the function's name
// Constructors and conversion functions made explicit will not be used for *implicit* conversions or copy initialization 
class MyString
{
private:
    std::string m_string;
public:
    // explicit keyword makes this constructor ineligible for implicit conversions
    explicit MyString(int x) // allocate string of size x
    {
        m_string.resize(x);
    }

    MyString(const char* string) // allocate string to hold string value
    {
        m_string = string;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);

};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
    out << s.m_string;
    return out;
}

void printString(const MyString& s)
{
    std::cout << s;
}

//int main()
//{
//    MyString mine = 'x'; // compile error, since MyString(int) is now explicit and nothing will match this
//    std::cout << mine;
//
//    printString('x'); // compile error, since MyString(int) can't be used for implicit conversions
//
//    return 0;
//}

// Best practice: consider making your constructors and user-defined conversions member functions explicit to prevent implicit conversion errors

// We can use the delete keyword to delete functions
// When a function has been deleted, any use of that function is considered a compile error

/*
    14.15
*/
// The copy assignment operator (operator=) is used to copy values from one object to another *already existing* object

// Overloading the copy assignment operator (operator=) is fairly straightforward, with one specific caveat
// The copy assignment operator must be overloaded as a member function
// If you aren't careful, overloading this operator can allow self-assignment, which usually just wastes time but can sometimes lead to disaster (especially in cases
//      where your objects are reponsible for dynamically allocating memory)
// We can get around this by adding a check at the beginning of the overload function that just returns the unmodified object

// This self-assignment check is typically skipped for copy constructors
// Self-assignment is usually omitted in cases that can naturally handle self-assignment as well

// The copy and swap idiom

// Unlike other operators, the compiler will provide a default copy assignment operator for your class if you do not provide one. It does memberwise assignment
// Just like other constructors and operators, you can prevent assignments from being made by making your copy assignment operator private or using the delete keyword

/*
    14.16
*/
// Because C++ does not know much about your class, the default copy constructor and default assignment operators it provides use a copying method known as a 
//      memberwise copy (also known as a shallow copy)
// This means that C++ copies each member of the class individually. When classes are simple (e.g. do not contain any dynamically allocated memory), this works very well
// However, when designing classes that handle dynamically allocated, shallow copying can get us in a lot of trouble!
// This is because shallow copies of a pointer just copy the address of the pointer -- it does not allocate any memory or copy the contents being pointed to

// A deep copy allocates memory for the copy and then copies the actual value, so that the copy lives in distinct memory from the source
// This way, the copy and source are distinct and will not affect each other in any way
// Doing deep copies requires that we write our own constructors and overloaded assignment operators

// Classes in the standard library that deal with dynamic memory handle all of their memory management, and have overloaded copy constructors and assignment operators
//      that do proper deep copying 
// So just use them

/*
    14.17
*/
// You can overload operators for built-in types to work with your classes
// This might even be necessary if you want to use templates
