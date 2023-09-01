#include <iostream>
#include "Fixed.hpp"
#include <cmath> 

/* 
*   Initialization of static member attribute
*   This variable represent the number of bits of the 
        fractionnal part, or simply the postion of the binary point 
*/
const int Fixed::frac = 8;

/************************ METHODS *******************************************/

/* Returns the raw value of the fixed-point value */
int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
    return (this->num);
}

/*  Sets the raw value of the fixed-point number */
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";

    this->num = raw;
    return ;
}

/* Converts the fixed-point value to a floating-point value. */
float Fixed::toFloat( void ) const
{
    return ((float)(getRawBits()) / (1 << frac));
}

/* Converts the fixed-point value to an integer value */
int Fixed::toInt( void ) const
{
    // Dividing by 2^frac to get int value
    return (getRawBits() >> frac);
}

/************************ CONSTUCTORS ****************************************/

/* Default Constructor */
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";

    this->num = 0;
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called\n";

    *this = rhs;
}

/* Int Constructor, converts i to the corresponding fixed-point value. */
Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called\n";
    
    // Storing the fixed point representation of this float
    this->num = i * (1 << frac);
}

/* Float Constructor, converts f to the corresponding fixed-point value. */
Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called\n";

    // Setting the binary point at (2 ^ frac)
    this->num = roundf(f * (1 << frac));
}

/************************ OPERATORS OVERLOAD *********************************/

/* Copy Assignement Operator */
Fixed&  Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";

    if (this != &other) // No self assignement
        this->num = other.getRawBits();
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed &obj)
{
    return (os << obj.toFloat());
}


/************************ DESTRUCTOR *****************************************/

/* Destructor */
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";

    return ;
}
