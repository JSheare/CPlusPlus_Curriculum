#include <iostream>

/*
    CHAPTER 17 R
*/

/*
    17.1
*/
// In this chapter we'll explore the basics of how inheritance works in C++

/*
    17.2
*/
// Inheritance in C++ takes place between classes
// In an inheritance (is-a) relationship, the class being inherited from is called the parent class, base class, or superclass
// The class doing the inheriting is called the child class, derived class, or subclass

// Basic class inheritance:
#include <string>
#include <string_view>

class Person
{
    // In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }
};

// Employee publicly inherits from Person
class Employee : public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

// It's possible to chain inheritances together (e.g. person<-employee<-supervisor)

/*
    17.3
*/
// When C++ constructs derived objects, it does so in phases
// First, the most base-class (at the top of the inheritance tree) is constructed first
// Then each child class is constructed in order, until the most-child class (at the bottom of the inheritance tree) is constructed last

/*
    17.4
*/
// When a derived class is constructed, C++ first constructs it's parent class, which makes it difficult to initialize parent class members at the same time
// Fortunetely, C++ gives us the ability to explicitly choose which Base constructor will be called!
// To do this, simply add a call to the Base class constructor in the member initializer list of the derived class
class Base
{
public:
    int m_id {};

    Base(int id = 0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
public:
    double m_cost {};

    Derived(double cost = 0.0, int id = 0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

// Derived classes will need to use access functions to access private members of the base class

// Note: calling parent constructors works the same way for inheritance chains

// When a derived class is destroyed, each destructor is called in the reverse order of construction

/*
    17.5
*/
// Access specifiers
// The protected access specifier allows the class the member belongs to, friends, and derived classes to access the member
// Howver, protected members are not accessible from outside the class

// Best practice: favor private members over protected members

// There are three different ways for classes to inherit other classes: public, protected, and private
// To do so, simply specify which type of access you want when choosing the class to inherit from
// This gives us 9 combinations: 3 member access specifiers (public, private, and protected), and 3 inheritance types (public, private, and protected)
// These differ in that when members are inherited, the access specifier for an inherited member may be changed depending on the type of inheritance used
// Keep in mind the following rules:
/*
    * A class can always access its own (non-inherited) members
    * he public accesses the members of a class based on the access specifiers of the class it is accessing
    * A derived class accesses inherited members based on the access specifier inherited from the parent class.
    *       This varies depending on the access specifier and type of inheritance used
*/

// Public inheritance is by far the most commonly used type of inheritance
// When you inherit a base class publically, inherited public members stay public and inherited protected members stay protected
// Inherited private members, which were inaccessible because they were private in the base class, staye inaccessible 

// Best practice: use public inheritance unless you have a specific reason to do otherwise

// Protected inheritance is the least common method of inheritance
//  With the protected inheritance, the public and protected members become protected, and the private members stay inaccessible 

// With private inheritance, all members from a base class are inherited as private
// This means the private members are inaccessible, and protected and public members become private
// Private inheritance can be useful when the derived class has no obvious relationship to the base class, but uses the base class for implementation internally

/*
    17.6
*/
// In cases where you need to add extra functionality to a class but don't want to modify it's code (maybe it's std library code or from a 3rd party vendor)
//      a good way to add this enhanced functionality is to instead derive a new class and add the functionality there
// You do this in exactly the way you would expect 

/*
    17.7
*/
// When a member function is called with a derived class object, the compiler first looks to see if that member exists in a derived class
// If not, it begins walking up the inheritance chain and checking whether the member has been defined in any of the parent classes. It uses the first one it finds

// We can take advantage of this to redefine how our functions behave in a derived class
// All you need to do is define a derived member function with the same name as the corresponding member function of the base class
// You can even change the access specifier

// Sometimes we don't want to completely replace a base class function, but instead want to add additional functionality to it
// To have a derived function call a base function of the same name, simply do a normal function call, but prefix the function with the scope qualifier

// With friend functions, you need to static_cast to cast the derived class to a base class

/*
    17.8
*/
// You can change the access for a function in a base class to something else in a derived class using the using keyword: using Base::printvalue;
// Put this under whatever access specifier you want to change to
// Unfortunately, you have to change the access for *all* overloaded versions of a function (not just one)

// You can also mark member functions as deleted in the derived class, which ensures they can't be called at all through a derived object

/*
    17.9
*/
// Multiple inheritance enables a derived class to inherit members from more than one parent

// A mixin is a small class that can be inherited from in order to add properties to a class
// The name mixin indicates that the class is intended to be mixed into other classes, not instantiated on its own

#include <string>

struct Point2D
{
    int x;
    int y;
};

class Box // mixin Box class
{
public:
    void setTopLeft(Point2D point) { m_topLeft = point; }
    void setBottomRight(Point2D point) { m_bottomRight = point; }
private:
    Point2D m_topLeft{};
    Point2D m_bottomRight{};
};

class Label // mixin Label class
{
public:
    void setText(const std::string_view str) { m_text = str; }
    void setFontSize(int fontSize) { m_fontSize = fontSize; }
private:
    std::string m_text{};
    int m_fontSize{};
};

class Button : public Box, public Label {};

int main()
{
    Button button{};
    button.Box::setTopLeft({ 1, 1 });
    button.Box::setBottomRight({ 10, 10 });
    button.Label::setText("Username: ");
    button.Label::setFontSize(6);
}

// Ambiguity can result when multiple base classes contain a function with the same name

// The diamond problem

// Best practice: avoid multiple inheritance unless alternatives lead to more complexity

int main()
{
    return 0;
}

