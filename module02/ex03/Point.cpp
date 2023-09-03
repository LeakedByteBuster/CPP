#include "Point.hpp"

/*
    Base Initializers
    -----------------
    - For initialization of reference members (const int t;)
    - For initialization of non-static const data members (int &t;)
    - For initialization of member objects which do not have default constructor
    - For initialization of base class members
    - When constructor’s parameter name is same as data member 
    - For Performance reasons


*   Source: https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
*/

// ◦ default constructor that initializes x and y to 0
Point::Point() : x((float)0), y((float)0)
{
}

// ◦ constructor that takes as parameters two constant floating-point numbers
// It initializes x and y with those parameters.
Point::Point(const float x, const float y) : x(x), y(y)
{
}

// ◦ copy constructor
Point::Point(const Point &rhs) : x(rhs.x), y(rhs.y)
{
}

// ◦ copy assignment operator overload
Point&   Point::operator=(const Point &rhs)
{
    (void)rhs;
    return (*this);
}

// ◦ destructor.
Point::~Point()
{
}

Fixed    Point::getX() const
{
    return (this->x);
}

Fixed    Point::getY() const
{
    return (this->y);
}