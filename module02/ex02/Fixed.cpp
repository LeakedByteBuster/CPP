#include <iostream>
#include "Fixed.hpp"
#include <cmath> 

/* -------------------------------------------------------------------------- */
/*                 Initialization of static member attribute                  */
/* -------------------------------------------------------------------------- */

const int Fixed::frac = 8;

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */

/* Returns the raw value of the fixed-point value */
int Fixed::getRawBits( void ) const
{
    #ifndef NDEBUG
        std::cout << "getRawBits member function called\n";
    #endif // NDEBUG

    return (this->num);
}

/*  Sets the raw value of the fixed-point number */
void Fixed::setRawBits( int const raw )
{
    #ifndef NDEBUG
        std::cout << "setRawBits member function called\n";
    #endif // NDEBUG

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

/* ------------------------------------------------------------------------- */
/*                           Static Member Functions                         */
/* ------------------------------------------------------------------------- */
    Fixed&   Fixed::min(Fixed& a, Fixed& b)
    {
        return ((a.num < b.num ) ? a : b);
    }            

    Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
    {
        return ((Fixed&)((a.num < b.num ) ? a : b));
    }

    Fixed&   Fixed::max(Fixed& a, Fixed& b)
    {
        return ((Fixed&)((a.num > b.num ) ? a : b));
    }            

    Fixed&   Fixed::max(const Fixed& a, const Fixed& b)
    {
        return ((Fixed&)((a.num > b.num ) ? a : b));
    }

/* ------------------------------------------------------------------------- */
/*                                Constructors                               */
/* ------------------------------------------------------------------------- */

/* Default Constructor */
Fixed::Fixed()
{
    #ifndef NDEBUG
        std::cout << "Default constructor called\n";
    #endif // NDEBUG

    this->num = 0;
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &rhs)
{
    #ifndef NDEBUG
        std::cout << "Copy constructor called\n";
    #endif // NDEBUG

    *this = rhs;
}

/* Int Constructor, converts i to the corresponding fixed-point value. */
Fixed::Fixed(const int i)
{
    #ifndef NDEBUG
        std::cout << "Int constructor called\n";
    #endif // NDEBUG
    
    // Storing the fixed point representation of this float
    this->num = i * (1 << frac);
}

/* Float Constructor, converts f to the corresponding fixed-point value. */
Fixed::Fixed(const float f)
{
    #ifndef NDEBUG
        std::cout << "Float constructor called\n";
    #endif // NDEBUG

    // Setting the binary point at (2 ^ frac)
    this->num = roundf(f * (1 << frac));
}

/* -------------------------------------------------------------------------- */
/*                       Assignement operator overload                        */
/* -------------------------------------------------------------------------- */

/* Copy Assignement Operator */
Fixed&  Fixed::operator=(const Fixed &other)
{
    #ifndef NDEBUG
        std::cout << "Copy assignment operator called\n";
    #endif // NDEBUG

    if (this != &other)
        this->num = other.getRawBits();
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                    Binary Arithmetic operators overload                    */
/* -------------------------------------------------------------------------- */
    Fixed   Fixed::operator+(const Fixed& rhs)
    {
        Fixed   res(this->toFloat() + rhs.toFloat());
        return (res);
    }

    Fixed   Fixed::operator-(const Fixed& rhs)
    {
        Fixed   res(this->toFloat() - rhs.toFloat());
        return (res);
        
    }
    Fixed   Fixed::operator*(const Fixed& rhs)
    {
        Fixed   res(this->toFloat() * rhs.toFloat());
        return (res);
        
    }
    Fixed   Fixed::operator/(const Fixed& rhs)
    {
        Fixed   res(this->toFloat() / rhs.toFloat());
        return (res);
        
    }

/* -------------------------------------------------------------------------- */
/*                        Extraction Operator Overload                        */
/* -------------------------------------------------------------------------- */

/* Prints FixedPoint value expressed as a float */
std::ostream&   operator<<(std::ostream& os, const Fixed &obj)
{
    return (os << obj.toFloat());
}

/* ------------------------------------------------------------------------- */
/*                  Increment & Decrement Operators Overload                 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/*   Pre & Post                                                              */
/*   ----------                                                              */
/*   Returning a reference to mimic the behaviour in cpp                     */
/*   int a = 5; b = ++a; | <-- | a is incremented 'BEFORE' assignement       */
/*                                                                           */
/*   Returning a copy of the original object to mimic the behaviour in cpp   */
/*   int a = 5; b = a++; | <-- | a is incremented 'AFTER' assignement        */
/*                                                                           */
/*   [[[ same thing is applied to the pre and post decrement operators... ]]]*/
/*                                                                           */
/*   As a convention you must type the int in function Post, so the compiler */
/*       differentiate between post and pre increment or decrement           */
/*       [[[ returnType operator symbol (int){ } ]]] | Symbol : -- or ++     */
/* ------------------------------------------------------------------------- */

Fixed&  Fixed::operator++()
{
    ++this->num;
    return(*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   original(*this);

    this->num++;
    return(original);
}

Fixed&  Fixed::operator--()
{
    --this->num;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   original(*this);

    num--;
    return(original);
}
/* ------------------------------------------------------------------------- */
/*                       Comparaison Operators Overload                      */
/* ------------------------------------------------------------------------- */

bool    Fixed::operator>(const Fixed& rhs)
{
    return (this->num > rhs.num);
}

bool    Fixed::operator<(const Fixed& rhs)
{
    return (this->num < rhs.num);
}

bool    Fixed::operator>=(const Fixed& rhs)
{
    return (this->num >= rhs.num);
}

bool    Fixed::operator<=(const Fixed& rhs)
{
    return (this->num <= rhs.num);
}

bool    Fixed::operator==(const Fixed& rhs)
{
    return (this->num == rhs.num);
}

bool    Fixed::operator!=(const Fixed& rhs)
{
    return (this->num != rhs.num);
}

/* ------------------------------------------------------------------------- */
/*                                 Destructor                                */
/* ------------------------------------------------------------------------- */

Fixed::~Fixed()
{
    #ifndef NDEBUG
        std::cout << "Destructor called\n";
    #endif // NDEBUG

    return ;
}
