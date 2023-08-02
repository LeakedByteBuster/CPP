# CPP

/*
*   (>>)                ==> Extraction operator || (‘‘put to’’)   || "see-out //cout"
*   (<<)                ==> Insertion operator  || (‘‘get from’’) || "see-in //cin"  
*   (::)                ==> Scope resolution  [name_of_the_class::name_of_constructor]
*   (:)                 ==> To inherit from a class class [ eg. Car: public Vehicle{...}; ]
*   The ‘‘:public’’     ==> can be read as ‘‘is derived from,’’ ‘‘implements,’’ and ‘‘is a subtype of.’’
*
*   *****************************************************************************
*
*   Function Overloading==> multiple functions can have the same name with different parameters 
*                       ==>     - functions can have the same name as long as the number and/or type of parameters are different
*   Stack::something    ==> qualification indicates that "something" is from the Stack namespace
*   throw               ==> transfers control to a handler for exceptions of type Stack::Overflow in some function that directly or indirectly called Stack::push().
*   Constructor         ==> A member function with the same name as its class
*                       ==>     -  A constructor defines a way to initialize an object of its class. [ automatically called when an object of a class is created ]
*                       ==>     - [ special method that automatically called when an object of a class is created ]
*                       ==>     - [ Note: it is always public, and it does not have any return value ]
*   sequence            ==> A sequence has a beginning and an end.
*   iterator            ==> refers to an element, and provides an operation that makes the iterator refer to the next element of the sequence.
*   Destructor          ==>
*   virtual             ==> ‘‘may be redefined later in a class derived from this one’’ in Simula and C++.
*   class               ==>     - A class is a template for objects, and an object is an instance of a class.
*                       ==>         - When the individual objects are created, they inherit all the variables and functions from the class.
*                       ==>         - Note: By default, all members of a class are private if you don't specify an access specifier:
*                       ==>         - Access Specifiers : [ Public, Private, Protected (is similar to private, but it can also be accessed in the inherited class) ]
*                       ==>         - Access Private Specifiers : use public "get" and "set" methods/functions
*   Encapsulation       ==>  make sure that "sensitive" data is hidden from users.
*   class members       ==> { Attributes and methods } are basically[ variables and functions ] that belongs to the class.
*   polymorphic type    ==> A class that provides the interface to a variety of other classes
*   inheritance         ==> The derived class is said to inherit members from its base class, so the use of base and derived classes
*                       ==>     - Multi-Level Inheritence       : [ MyGrandChild is derived from class MyChild (which is derived from MyClass). ]
*                       ==>     - Multiple Inheritence (comma)   : [  class MyChildClass: public MyClass, public MyOtherClass{...}; ]
*   template<class T>   ==> Prefix makes T a parameter of the declaration it prefixes.
*   container           ==> A class holding a collection of elements of some type
*                       ==>     - the dereference operator * to mean ‘‘access an element through an iterator’’
*   reference variable  ==> A "reference" to an existing variable, and it is created with the '&' operator  [string food = "Hamburger; "string &meal = food;]
*                       ==>         - '&' can be used for accessing address of variable
*
*   *****************************************************************************
*   
*   PROGRAMMING PARADIGMS :
*   ---------------------
*   ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*  | Procedural Programming      | Decide which procedures you want; use the best algorithms you can find.
*  | ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
*  | Modular Programming         | (data-hiding principle) Decide which modules you want; partition the program so that data is hidden within modules
*  |                             | ### Where there is no grouping of procedures with related data, the procedural programming style suffices. ###
*  |                             |   - From the design of procedures and toward the organization of data
*  |                             |   - A set of related procedures with the data they manipulate is often called a module. 
*  |                             |   - C++ provides a mechanism for grouping related data, functions, etc., into separate namespaces
*  | ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
*  | Data Abstraction            | Decide which types you want; provide a full set of operations for each type.
*  |                             | ### Where there is no need for more than one object of a type, the data-hiding programming style using modules suffices. ###
*  |                             |  - [ module types; user-defined types; abstract types; concrete types; virtual functions ]
*  |                             |     - abstract types, the interface is more completely insulates a user from implementation details.
*  |                             |  - define types that behave in (nearly) the same way as built-in types. often called "abstract data type (user-defined type)"
*  |                             |  - A member function with the same name as its class is called a constructor.
*  | ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
*  | Object-Oriented Programming | Decide which classes you want; provide a full set of operations for each class; make commonality explicit by using inheritance
*  |                             | ### Where there is no such commonality, data abstraction suffices. ###
*  |                             |  - Data abstraction is fundamental to good design but user-defined types by themselves are not flexible
*  |                             |  - class Circle is said to be derived from class Shape, and class Shape is said to be a base of class Circle.
*  |                             |      - Circle and Shape subclass and superclass, respec- tively.
*  |                             |  - The amount of commonality between types that can be exploited by using inheritance and virtual functions is the litmus test 
*  |                             |      of the applicability of object-oriented programming to a problem.
*  |                             |      - Graphics : enormous scope for object-oriented programming
*  |                             |      - Classical Arithmetic Types : hardly any scope for more than data abstraction (object-oriented programming seem unnecessary.)
*  |                             |      - Class hierarchies and abstract classes complement each other instead of being mutually exclusive.
*  |                             |          - classes and modules contain functions, while modules contain classes and functions.
*  | ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
*  | Generic Programming         | Decide which algorithms you want; parameterize them so that they work for a variety of suitable types and data structures
*  |                             | - If an algorithm can be expressed independently of representation details and if it can be done so affordably and without 
*  |                             |      logical contortions, it ought to be done so.
*  |                             | - [ Containers; Generic Algorithms;   ]
*  |                             | - All standard library containers support this notion of iterators and sequences.
*   ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
