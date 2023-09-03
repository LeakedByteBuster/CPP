#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class   Point{
private:
    // ◦ Fixed const attribute x
    const Fixed x;
    // ◦ Fixed const attribute y
    const Fixed y;

public:

    // ◦ default constructor that initializes x and y to 0
    Point();
    // ◦ constructor that takes as parameters two constant floating-point numbers
    // It initializes x and y with those parameters.
    Point(const float, const float);
    // ◦ copy constructor
    Point(const Point &);
    // ◦ copy assignment operator overload
    Point&   operator=(const Point &);
    // ◦ destructor.
    ~Point();

    Fixed    getX() const;
    Fixed    getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP