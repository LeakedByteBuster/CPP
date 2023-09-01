#include <iostream>
#include "Fixed.hpp"

/* Initialization of static member attribute */
/* This variable represent the number of the bits that represent the fractionnal part, 
    or simply the postion of the binary point */
const int Fixed::frac = 8;

/* Returns the raw value of the fixed-point value */
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (this->num);
}

/*  Sets the raw value of the fixed-point number */
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";

    this->num = raw;
    return ;
}

/* Default Constructor */
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";

    this->num = 0;
    return ;
}

/* Destructor */
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";

    return ;
}

/* Copy Assignement Operator */
Fixed&  Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";

    if (this != &other) // No self assignement
        this->num = other.getRawBits();
    return (*this);
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called\n";

    *this = rhs;
    return ;
}
