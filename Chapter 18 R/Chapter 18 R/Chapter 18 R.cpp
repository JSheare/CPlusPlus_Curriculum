#include <iostream>

/*
    CHAPTER 18 R
*/

/*
    18.1
*/
// C++ will let us set a base class pointer or reference to a derived object
// These references/pointers will only see the derived object members which were part of the base class
// This can be useful when you want to store a lot of different derived classes (with the same base class) in an array together, which wouldn't be possible otherwise
// This can also be useful in that it allows you to write a single function that works for all classes derived from the base
// The only problem is that only the base class's members can be accessed
// There is a solution, however: virtual functions

/*
    18.2
*/
// A virtual function is a special type of member function that, when called, resolves to the most-derived version of the function for the actual type of the object
//      being referenced or pointed to
// This capability is known as polymorphism
// A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function
// Such functions are called overrides

// To make a function virtual, simply place the "virtual" keyword before the function declaration:

class Base
{
public:
    virtual std::string_view getName() const { return "Base"; } // note addition of virtual keyword
};

class Derived : public Base
{
public:
    virtual std::string_view getName() const { return "Derived"; }
};

//int main()
//{
//    Derived derived{};
//    Base& rBase{ derived };
//    std::cout << "rBase is a " << rBase.getName() << '\n';
//
//    return 0;
//}

// Outputs: rBase is a Derived

// Calling a virtual member function directly on an object (not through a pointer or a reference) will always invoke the member function belonging to the same type of that object

// Note that if a function is marked as virtual, all matching overrides in a derived class are also implicity considered virtual, even if not explicitly marked as such
// This does not work the other way around--a virtual override in a derived class does not implicitly make the base class function virtual

// Best practice: never call virtual functions from constructors or destructors

/*
    18.3
*/
// To address some common challenges with inheritance, C++ has two inheritance-related identifiers: override and final
// These are often referred to as "specifiers"
// Although final isn't used very much, override is a fantastic addition that you should use regularly

// To help address the issue of functions that are meant to be overrides but aren't, the override specifier can be applied to any virtual function by placing the 
//      override specifier after the function signature (the same place a function-level const specifier goes)
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }
    virtual std::string_view getName3(int x) { return "A"; }
};

class B : public A
{
public:
    //std::string_view getName1(short int x) override { return "B"; } // compile error, function is not an override
    //std::string_view getName2(int x) const override { return "B"; } // compile error, function is not an override
    std::string_view getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

};
// Best practice: use the virtual keyword on virtual function in a base class. Use the overrides specifier (but not the virtual keyword) on override functions in derived classes
//      This includes virtual destructors

// The final specifier can be used to ensure that someone can't override a virtual function
// Used in the same place as the override specifier

// There is one special case in which a derived class virtual function override can have a different return type than the base class and still be considred a matching override
// If the return type of the virtual function is a pointer or a reference to some class, override functions can return a pointer or reference to a derived class
// These are called covariant return types
// Covariant return types are often used in cases where a virtual member function returns a pointer or reference to the class containing the member function
// However, this isn't strictly necessary. Covariant return types can be used in any case where the return type of the override member function is derived from the 
//      return type of the base virtual member function

/*
    18.4
*/
// You should *always* make your destructors vitrual if you're dealing with inheritance
// Note: it is not necessary to make an empty derived class destructor just to mark it as virtual
// Note that if you want your base class to have a virtual destructor that is otherwise empty, you can define your destructor this way:
// virtual ~Base() = default; 

// Leave your assignments non-virtual for now, in the interest of simplicity

// If you want to ignore virtualization, just use the scope resolution operator on the member you want to call

// Recommendations about virtual functions:
// If you intend your class to be inherited from, make sure your destructor is virtual
// If you do not intend your class to be inherited from, mark your class as final. This will prevent other classes from inheriting from it in the first place, without
//      imposing any other use restrictions on the class itself

/*
    18.7
*/
// C++ allows you to create a special kind of virtual function called a pure virtual function (or abstract function) that has no body at all!
// A pure virtual function simply acts as a placeholder that is meant to be redefined by derived classes

// To create a pure virtual function, rather than define a body for the function, we simply assign the function the value of 0:
// virtual int getValue() const = 0;

// Doing this has two main consequences:
// First, any class with one or more pure virtual functions becomes an abstract base class, which means that it can not be instantiated!
// Second, any derived class must define a body for this function, or that derived class will be considered an abstract base class as well

// Pure virtual functions can still be given definitions, they just need to be defined seperately (not inline)

// An interface class is a class that has no member variables, and where *all* of the functions are pure virtual
// In other words, the class is purely a definition, and has no actual implementation

// Interfaces are useful when you want to define the functionality that derived classes must implement, but leave the details of how the derived class implements that 
//      that functionality entirely up to the derived class
// Interface classes are often named beginning with an I

/*
    18.8
*/
// The diamond problem: a class has multiple inheritance from two classes that both inherit from a single base class
// Weird behaviors can result from having multiple copies of the same members

// To share a base class, simply insert the "virtual" keyword in the inheritance list of the derived class
// This creates what is called a virtual base class, which means there is only one base object
// The base object is shared between all objects in the inheritance tree and it is only constructed once

/*
    18.9
*/
// The assigning of a derived class to a base class object is called object slicing
// The derived part of the derived object is sliced off, leaving obly the base part

// This is easy to do by accident with functions. Ex: function has a parameter of base class (not reference to base class) and you pass in a derived object
// Can also be easy to do with std::vector, where the type of std::vector has been declared as the base class

// Frankenobjects are objects that are composed of parts of multiple objects and occur when you try to assign a derived class to a base class reference variable
// Don't do this

// Tip: try to avoid object slicing. It pretty much just leads to headaches

/*
    18.10
*/
// When dealing with polymorphism, you'll often encounter cases where you have a pointer to a base class, but you want to access some information that exists only in a derived class
// Converting a derived pointer to a base pointer is sometimes called upcasting. This happens implicitly often
// But what if you wanted to go the other way?

// C++ provides a casting operator named dynamic_cast that can be used for just this purpose
// Although dynamic casts have a few different capabilities, by far the most common use for dynamic casting is for converting base-class pointers into derived-class pointers
// This process is called downcasting
// Works just like static_cast

// If dynamic_cast fails, the result of the conversion will be a null pointer
// Rule: always ensure your dynamic casts actually succeed by checking for a nullptr result

// Note that dynamic casting will not work in the following cases:
// with protected or private inheritance
// For classes that do not declare or inherit any virtual functions
// In certain cases involving virtual base classes

// You can downcast with static_cast, which is faster, but it doesn't do any runtime checking
// This means that it can "succeed" in casting without actually doing so, which can lead to undefined behavior

// Dynamic cast can also be used with references
// dynamic_cast doesn't return anything on failure to cast a reference, it just throws an exception

// In general, using a virtual function *should* be preferred over downcasting. However, there are times when downcasting is the better choice:
// When you can not modify the base class to add a virtual function (e.g. because the base class is part of the standard library)
// When you need access to something that is derived-class specific
// When adding a virtual function to your base class doesn't make sense. Using a pure virtual function may be an option here if you don't need to instantiate the base class

/*
    18.11
*/
// Overloading operator<< with inherited classes
// Usually we overload << as a friend function, which makes it ineligible for virtualization

// The way around this is to make our overloaded operator<< friend function call a virtual member function that returns a string instead:
//class Base
//{
//public:
//	// Here's our overloaded operator<<
//	friend std::ostream& operator<<(std::ostream& out, const Base& b)
//	{
//		// Call virtual function identify() to get the string to be printed
//		out << b.identify();
//		return out;
//	}
//
//	// We'll rely on member function identify() to return the string to be printed
//	// Because identify() is a normal member function, it can be virtualized
//	virtual std::string identify() const
//	{
//		return "Base";
//	}
//};
//
//class Derived : public Base
//{
//public:
//	// Here's our override identify() function to handle the Derived case
//	std::string identify() const override
//	{
//		return "Derived";
//	}
//};

//int main()
//{
//	Base b{};
//	std::cout << b << '\n';
//
//	Derived d{};
//	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects
//
//	Base& bref{ d };
//	std::cout << bref << '\n';
//
//	return 0;
//}

// Even better, have the virtual function return an ostream reference, which will allow us to print class members that have their own overloaded operator<< normally:
class Base
{
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		// Delegate printing responsibility for printing to virtual member function print()
		return b.print(out);
	}

	// We'll rely on member function print() to do the actual printing
	// Because print() is a normal member function, it can be virtualized
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

// Some class or struct with an overloaded operator<<
struct Employee
{
	std::string name{};
	int id{};

	friend std::ostream& operator<<(std::ostream& out, const Employee& e)
	{
		out << "Employee(" << e.name << ", " << e.id << ")";
		return out;
	}
};

class Derived : public Base
{
private:
	Employee m_e{}; // Derived now has an Employee member

public:
	Derived(const Employee& e)
		: m_e{ e }
	{
	}

	// Here's our override print() function to handle the Derived case
	std::ostream& print(std::ostream& out) const override
	{
		out << "Derived: ";

		// Print the Employee member using the stream object
		out << m_e;

		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{ Employee{"Jim", 4} };
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref{ d };
	std::cout << bref << '\n';

	return 0;
}

