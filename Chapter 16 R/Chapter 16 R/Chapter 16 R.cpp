#include <iostream>

/*
    CHAPTER 16 R
*/

/*
    16.1
*/
// There are many different kinds of relationships two objects may have in real life, and we use specific "relation-type" words to describe these relationships

/*
    16.2
*/
// The process of building complex objects from simpler ones is called object composition
// Because structs and classes are built from smaller, simpler parts, they are sometimes referred to as composite types 

// To qualify as a composition, an object and a part must have the following relationship:
/*
    * The part (member) is a part of the object (class)
    * The part (member) can only belong to one object (class) at a time
    * The part (member) has its existence managed by the object (class)
    * The part (member) does not know about the existence of the object (class)
*/

// A good rule of thumb is that each class should be built to accomplish a single task. That task should either be the storage and manipulation of some kind of data
//      OR the coordination of its members. Ideally not both

/*
    16.3
*/
// To qualify as an aggregation, a whole object and its parts must have the following relationship:
/*
    * The part (member) is part of the object (class)
    * The part (member) can (if desired) belong to more than one object (class) at a time
    * The part (member) does not have its existence managed by the object (class)
    * The part (member) does not know about the existence of the object (class)
*/
// Like a composition, an aggregation is still a part-whole relationship, where the parts are contained within the whole, and it is a unidirectional relationship
// However, unlike a composition, parts can belong to more than one object at a time, and the whole object is not responsible for the existence and lifespan of the parts

// Best practice: implement the simplest relationship type that meets the needs of your program, not what seems right in real-life

/*
    16.4
*/
// To qualify as an association, an object and another object must have the following relationship:
/*
    * The associated object (member) is otherwise unrelated to the object (class)
    * The associated object (member) can belong to more than one object (class) at a time
    * The associated object (member) does not have its existence managed by the object (class)
    * The associated object (member) may or may not know about the existence of the object (class)
*/
// Unlike a composition or aggregation, where the part is a part of the whole object, in an association, the associated object is otherwise unrelated to the object

// Sometimes objects may have a relationship with other objects of the same type. This is called a reflexive association

// Associations can be indirect

/*
    16.5
*/
// A dependency occurs when one object invokes another object's functionality in order to accomplish some specific task
// A dependency is always a unidirectional relationship

/*
    16.6
*/
// A container class is a class designed to hold and organize multiple instances of another type
// Most well-defined containers will include functions that:
/*
    * Create and empty container (via a constructor)
    * Insert an new object into the container
    * Remove an object from the container
    * Report the number of objects currently in the container
    * Empty the container of all objects
    * Provide access to stored objects
    * Sort the elements (optional)
*/

// Container classes generally come in two different varieties
// Value containters are compositions that store data copies of the objects that they are holding
// Reference containers are aggregations that store pointers or references to other objects

/*
    16.7
*/
// When a compiler sees an initializer list, it automatically converts it into an object of type std::initializer_list
// Therefore, if we create a constructor that takes a std::initializer_list parameter, we can create objects using the initializer list as input
// std::initializer_list lives in the <initializer_list> header

// Best practice: when initializing a container that has a list constructor:
//      use brace initialization when intending to call the list constructor
//      use direct initialization when intending to call a non-list constructor

// Best practice: if you provide list construction, it's a good idea to provide list assignment as well

#if 0
int main()
{
    return 0;
}
#endif 

