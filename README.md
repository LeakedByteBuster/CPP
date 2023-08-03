# CPP

## Advice
Here is a set of ‘‘rules’’ you might consider while learning C++. As you get more proficient you can evolve them into something suitable for your kind of applications and your style of program- ming. They are deliberately very simple, so they lack detail. Don’t take them too literally. To write a good program takes intelligence, taste, and patience. You are not going to get it right the first time. Experiment!

Remember, this advice is only rough rules of thumb, not immutable laws. A piece of advice should be applied only ‘‘where reasonable.’’ There is no substitute for intelligence, experience, common sense, and good taste.

I find rules of the form ‘‘never do this’’ unhelpful. Consequently, most advice is phrased as suggestions of what to do, while negative suggestions tend not to be phrased as absolute prohibi- tions. I know of no major feature of C++ that I have not seen put to good use. The ‘‘Advice’’ sec- tions do not contain explanations. Instead, each piece of advice is accompanied by a reference to the appropriate section of the book. Where negative advice is given, that section usually provides a suggested alternative.

### Notes to the Reader : Chapter 1 - P 16

- [1] When you program, you create a concrete representation of the ideas in your solution to some problem. Let the structure of the program reflect those ideas as directly as possible:
  - [a] If you can think of ‘‘it’’ as a separate idea, make it a class.
  - [b] If you can think of ‘‘it’’ as a separate entity, make it an object of some class.
  - [c] If two classes have a common interface, make that interface an abstract class.
  - [d] If the implementations of two classes have something significant in common, make that
        commonality a base class.
  - [e] If a class is a container of objects, make it a template.
  - [f] If a function implements an algorithm for a container, make it a template function imple-
menting the algorithm for a family of containers.
  - [g] If a set of classes, templates, etc., are logically related, place them in a common namespace.
- [2] When you define either a class that does not implement either a mathematical entity like a matrix or a complex number or a low-level type such as a linked list:
    - [a] Don’t use global data (use members).
    - [b] Don’t use global functions.
    - [c] Don’t use public data members.
    - [d] Don’t use friends, except to avoid [a] or [c].
    - [e] Don’t put a ‘‘type field’’ in a class; use virtual functions.
    - [f] Don’t use inline functions, except as a significant optimization.

### A Tour of C++: Chapter 2 - P 43
- [1] Don’t panic! All will become clear in time; §2.1.
- [2] You don’t have to know every detail of C++ to write good programs; §1.7. 
- [3] Focus on programming techniques, not on language features; §2.1.

### A Tour of the Standard Library : Chapter 3 - P 66

- [1] Don’t reinvent the wheel; use libraries.
- [2] Don’t believe in magic; understand what your libraries do, how they do it, and at what cost
        they do it.
- [3] When you have a choice, prefer the standard library to other libraries.
- [4] Do not think that the standard library is ideal for everything.
- [5] Remember to #include the headers for the facilities you use; §3.3.
- [6] Remember that standard library facilities are defined in namespace std; §3.3.
- [7] Use string rather than char*; §3.5, §3.6.
- [8] If in doubt use a range-checked vector (such as Vec); §3.7.2.
- [9] Prefer vector<T>, list<T>, and map<key,value> to T[]; §3.7.1, §3.7.3, §3.7.4.
- [10] When adding elements to a container, use push_back() or back_inserter(); §3.7.3, §3.8.
- [11] Use push_back() on a vector rather than realloc() on an array; §3.8.
- [12] Catch common exceptions in main(); §3.7.2.

### Basic Facilities : Chapter 4 - P 85
- [1] Keep scopes small; §4.9.4.
- [2] Don’t use the same name in both a scope and an enclosing scope; §4.9.4.
- [3] Declare one name (only) per declaration; §4.9.2.
- [4] Keep common and local names short, and keep uncommon and nonlocal names longer; §4.9.3.
- [5] Avoid similar-looking names; §4.9.3.
- [6] Maintain a consistent naming style; §4.9.3.
- [7] Choose names carefully to reflect meaning rather than implementation; §4.9.3.
- [8] Use a typedef to define a meaningful name for a built-in type in cases in which the built-in
type used to represent a value might change; §4.9.7.
- [9] Use typedefs to define synonyms for types; use enumerations and classes to define new types;
§4.9.7.
- [10] Remember that every declaration must specify a type (there is no ‘‘implicit int’’); §4.9.1.
- [11] Avoid unnecessary assumptions about the numeric value of characters; §4.3.1, §C.6.2.1.
- [12] Avoid unnecessary assumptions about the size of integers; §4.6.
- [13] Avoid unnecessary assumptions about the range of floating-point types; §4.6.
- [14] Prefer a plain int over a short int or a long int; §4.6.
- [15] Prefer a double over a float or a long double; §4.5.
- [16] Prefer plain char over signed char and unsigned char; §C.3.4.
- [17] Avoid making unnecessary assumptions about the sizes of objects; §4.6.
- [18] Avoid unsigned arithmetic; §4.4.
- [19] View signed to unsigned and unsigned to signed conversions with suspicion; §C.6.2.6.
- [20] View floating-point to integer conversions with suspicion; §C.6.2.6.
- [21] View conversions to a smaller type, such as int to char, with suspicion; §C.6.2.6.

### Pointers, Arrays, and Structures : Chapter 5 - P 104
- [1] Avoid nontrivial pointer arithmetic; §5.3.
- [2] Take care not to write beyond the bounds of an array; §5.3.1.
- [3] Use 0 rather than NULL; §5.1.1.
- [4] Use vector and valarray rather than built-in (C-style) arrays; §5.3.1.
- [5] Use string rather than zero-terminated arrays of char; §5.3.
- [6] Minimize use of plain reference arguments; §5.5.
- [7] Avoid void*except in low-level code; §5.6.
- [8] Avoid nontrivial literals (‘‘magic numbers’’) in code. Instead, define and use symbolic con-
stants; §4.8, §5.4.

### Expressions and Statements : Chapter 6 - P 139
- [1] Prefer the standard library to other libraries and to ‘‘handcrafted code;’’ §6.1.8.
- [2] Avoid complicated expressions; §6.2.3.
- [3] If in doubt about operator precedence, parenthesize; §6.2.3.
- [4] Avoid explicit type conversion (casts); §6.2.7.
- [5] When explicit type conversion is necessary, prefer the more specific cast operators to the C- style cast; §6.2.7.
- [6] Use the T(e) notation exclusively for well-defined construction; §6.2.8.
- [7] Avoid expressions with undefined order of evaluation; §6.2.2.
- [8] Avoid goto; §6.3.4.
- [9] Avoid do-statements; §6.3.3.
- [10] Don’t declare a variable until you have a value to initialize it with; §6.3.1, §6.3.2.1, §6.3.3.1.

### Functions : Chapter 7 - P 163

- [1] Be suspicious of non-const reference arguments; if you want the function to modify its argu- ments, use pointers and value return instead; §5.5.
- [2] Use const reference arguments when you need to minimize copying of arguments; §5.5.
- [3] Use const extensively and consistently; §7.2.
- [4] Avoid macros; §7.8.
- [5] Avoid unspecified numbers of arguments; §7.6.
- [6] Don’t return pointers or references to local variables; §7.3.
- [7] Use overloading when functions perform conceptually the same task on different types; §7.4.
- [8] When overloading on integers, provide functions to eliminate common ambiguities; §7.4.3.
- [9] When considering the use of a pointer to function, consider whether a virtual function
(§2.5.5) or a template (§2.7.2) would be a better alternative; §7.7.
- [10] If you must use macros, use ugly names with lots of capital letters; §7.8.

### Namespaces and Exceptions : Chapter 8 - P 194

- [1] Use namespaces to express logical structure; §8.2.
- [2] Place every nonlocal name, except main(), in some namespace; §8.2.
- [3] Design a namespace so that you can conveniently use it without accidentally gaining access to
 unrelated namespaces; §8.2.4.
- [4] Avoid very short names for namespaces; §8.2.7.
- [5] If necessary, use namespace aliases to abbreviate long namespaces names; §8.2.7.
- [6] Avoid placing heavy notational burdens on users of your namespaces; §8.2.2, §8.2.3.
- [7] Use the Namespace::member notation when defining namespace members; §8.2.8.
- [8] Use using namespace only for transition or within a local scope; §8.2.9.
- [9] Use exceptions to decouple the treatment of ‘‘errors’’ from the code dealing with the ordinary
 processing; §8.3.3.
- [10] Use user-defined rather than built-in types as exceptions; §8.3.2.
- [11] Don’t use exceptions when local control structures are sufficient; §8.3.3.1.

### Source Files and Programs : Chapter 9 - P 197

- [1] Use header files to represent interfaces and to emphasize logical structure; §9.1, §9.3.2.
- [2] #include a header in the source file that implements its functions; §9.3.1.
- [3] Don’t define global entities with the same name and similar-but-different meanings in differ-
ent translation units; §9.2.
- [4] Avoid non-inline function definitions in headers; §9.2.1.
- [5] Use #include only at global scope and in namespaces; §9.2.1.
- [6] #include only complete declarations; §9.2.1.
- [7] Use include guards; §9.3.3.
- [8] #include C headers in namespaces to avoid global names; §9.3.2.
- [9] Make headers self-contained; §9.2.3.
- [10] Distinguish between users’ interfaces and implementers’ interfaces; §9.3.2.
- [11] Distinguish between average users’ interfaces and expert users’ interfaces; §9.3.2.
- [12] Avoid nonlocal objects that require run-time initialization in code intended for use as part of
non-C++ programs; §9.4.1.


### Classes : Chapter 10 - P 257

- [1] Represent concepts as classes; §10.1.
- [2] Use public data (structs) only when it really is just data and no invariant is meaningful for the
data members; §10.2.8.
- [3] A concrete type is the simplest kind of class. Where applicable, prefer a concrete type over
more complicated classes and over plain data structures; §10.3.
- [4] Make a function a member only if it needs direct access to the representation of a class;
§10.3.2.
- [5] Use a namespace to make the association between a class and its helper functions explicit;
§10.3.2.
- [6] Make a member function that doesn’t modify the value of its object a const member function;
§10.2.6.
- [7] Make a function that needs access to the representation of a class but needn’t be called for a
specific object a static member function; §10.2.4.
- [8] Use a constructor to establish an invariant for a class; §10.3.1.
- [9] If a constructor acquires a resource, its class needs a destructor to release the resource;
§10.4.1.
- [10] If a class has a pointer member, it needs copy operations (copy constructor and copy assign-
ment); §10.4.4.1.
- [11] If a class has a reference member, it probably needs copy operations (copy constructor and
copy assignment); §10.4.6.3.
- [12] If a class needs a copy operation or a destructor, it probably needs a constructor, a destructor, a
copy assignment, and a copy constructor; §10.4.4.1.
- [13] Check for self-assignment in copy assignments; §10.4.4.1.
- [14] When writing a copy constructor, be careful to copy every element that needs to be copied
(beware of default initializers); §10.4.4.1.

---

## PROGRAMMING PARADIGMS :

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Procedural Programming      | Decide which procedures you want; use the best algorithms you can find.
| ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
| Modular Programming         | (data-hiding principle) Decide which modules you want; partition the program so that data is hidden within modules
|                             | ### Where there is no grouping of procedures with related data, the procedural programming style suffices. ###
|                             |   - From the design of procedures and toward the organization of data
|                             |   - A set of related procedures with the data they manipulate is often called a module. 
|                             |   - C++ provides a mechanism for grouping related data, functions, etc., into separate namespaces
| ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
| Data Abstraction            | Decide which types you want; provide a full set of operations for each type.
|                             | ### Where there is no need for more than one object of a type, the data-hiding programming style using modules suffices. ###
|                             |  - [ module types; user-defined types; abstract types; concrete types; virtual functions ]
|                             |     - abstract types, the interface is more completely insulates a user from implementation details.
|                             |  - define types that behave in (nearly) the same way as built-in types. often called "abstract data type (user-defined type)"
|                             |  - A member function with the same name as its class is called a constructor.
| ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
| Object-Oriented Programming | Decide which classes you want; provide a full set of operations for each class; make commonality explicit by using inheritance
|                             | ### Where there is no such commonality, data abstraction suffices. ###
|                             |  - Data abstraction is fundamental to good design but user-defined types by themselves are not flexible
|                             |  - class Circle is said to be derived from class Shape, and class Shape is said to be a base of class Circle.
|                             |      - Circle and Shape subclass and superclass, respec- tively.
|                             |  - The amount of commonality between types that can be exploited by using inheritance and virtual functions is the litmus test 
|                             |      of the applicability of object-oriented programming to a problem.
|                             |      - Graphics : enormous scope for object-oriented programming
|                             |      - Classical Arithmetic Types : hardly any scope for more than data abstraction (object-oriented programming seem unnecessary.)
|                             |      - Class hierarchies and abstract classes complement each other instead of being mutually exclusive.
|                             |          - classes and modules contain functions, while modules contain classes and functions.
| ----------------------------|----------------------------------------------------------------------------------------------------------------------------------------
| Generic Programming         | Decide which algorithms you want; parameterize them so that they work for a variety of suitable types and data structures
|                             | - If an algorithm can be expressed independently of representation details and if it can be done so affordably and without 
|                             |      logical contortions, it ought to be done so.
|                             | - [ Containers; Generic Algorithms;   ]
|                             | - All standard library containers support this notion of iterators and sequences.


## Terminology
">>"                : Extraction operator || (‘‘put to’’)   || "see-out //cout"
"<<"                : Insertion operator  || (‘‘get from’’) || "see-in //cin"  
"::"                : Scope resolution  [name_of_the_class::name_of_constructor]
":"                : To inherit from a class class [ eg. Car: public Vehicle{...}; ]
The ‘‘:public’’     : can be read as ‘‘is derived from,’’ ‘‘implements,’’ and ‘‘is a subtype of.’’

Function Overloading: multiple functions can have the same name with different parameters 
                         - functions can have the same name as long as the number and/or type of parameters are different
Stack::something    : qualification indicates that "something" is from the Stack namespace
throw               : transfers control to a handler for exceptions of type Stack::Overflow in some function that directly or indirectly called Stack::push().
Constructor         : A member function with the same name as its class
                         -  A constructor defines a way to initialize an object of its class. [ automatically called when an object of a class is created ]
                         - [ special method that automatically called when an object of a class is created ]
                         - [ Note: it is always public, and it does not have any return value ]
sequence            : A sequence has a beginning and an end.
iterator            : refers to an element, and provides an operation that makes the iterator refer to the next element of the sequence.
Destructor          :
virtual             : ‘‘may be redefined later in a class derived from this one’’ in Simula and C++.
class               :    - A class is a template for objects, and an object is an instance of a class.
                             - When the individual objects are created, they inherit all the variables and functions from the class.
                             - Note: By default, all members of a class are private if you don't specify an access specifier:
                             - Access Specifiers : [ Public, Private, Protected (is similar to private, but it can also be accessed in the inherited class) ]
                             - Access Private Specifiers : use public "get" and "set" methods/functions
Encapsulation       :  make sure that "sensitive" data is hidden from users.
class members       : { Attributes and methods } are basically[ variables and functions ] that belongs to the class.
polymorphic type    : A class that provides the interface to a variety of other classes
inheritance         : The derived class is said to inherit members from its base class, so the use of base and derived classes
                        - Multi-Level Inheritence       : [ MyGrandChild is derived from class MyChild (which is derived from MyClass). ]
                         - Multiple Inheritence (comma)   : [  class MyChildClass: public MyClass, public MyOtherClass{...}; ]
template<class T>   : Prefix makes T a parameter of the declaration it prefixes.
container           : A class holding a collection of elements of some type
                         - the dereference operator * to mean ‘‘access an element through an iterator’’
reference variable  : A "reference" to an existing variable, and it is created with the '&' operator  [string food = "Hamburger; "string &meal = food;]
                             - '&' can be used for accessing address of variable
