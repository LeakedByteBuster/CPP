#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class   Fixed{

private:
    int                 num;    /* Fixed Point  | integer part */
    static const int    frac;   /* Binary point | bits in fraction part */

public :
/* -------------------------------------------------------------------------- */
/*           Constructors & Destructor & Copy Assignement Operator            */
/* -------------------------------------------------------------------------- */
    Fixed();                            /* Default Constructor */
    Fixed(const Fixed &);               /* Copy Constructor */
    Fixed(const int);                   /* __INT Constructor */
    Fixed(const float);                 /* __FLOAT Constructor */
    Fixed&  operator=(const Fixed &);   /* Copy Assignement Operator */
    ~Fixed();                           /* Destructor */

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */
    int     getRawBits(void) const; /* Setter */
    void    setRawBits(int const);  /* Getter */
    float   toFloat( void ) const;  /* Converts Fixed to Float */
    int     toInt( void ) const;    /* Converts Fixed to Int */

/* ------------------------------------------------------------------------- */
/*                  Increment & Decrement Operators Overload                 */
/* ------------------------------------------------------------------------- */
    Fixed&  operator++();       /* Pre-increment overload */
    Fixed   operator++(int);    /* Post-increment overload */
    Fixed&  operator--();       /* Pre-increment overload */
    Fixed   operator--(int);    /* Post-increment overload */

/* ------------------------------------------------------------------------- */
/*                       Comparaison Operators Overload                      */
/* ------------------------------------------------------------------------- */
    bool    operator>(const Fixed& rhs);     /* Greater than overload */
    bool    operator<(const Fixed& rhs);     /* Less than overload */
    bool    operator>=(const Fixed& rhs);    /* Greater than or equal overload */
    bool    operator<=(const Fixed& rhs);    /* Less than or equal overload */
    bool    operator==(const Fixed& rhs);    /* Equality overload */
    bool    operator!=(const Fixed& rhs);    /* Not-equal-to overload */

/* ------------------------------------------------------------------------- */
/*                           Static Member Functions                         */
/* ------------------------------------------------------------------------- */
    /* NOTE:: if a == b, a reference to b is returned. min() & Max() */
    static Fixed&   min(Fixed& a, Fixed& b);             /* Returns smallest */
    static Fixed&   min(const Fixed& a, const Fixed& b); /* Returns smallest */
    static Fixed&   max(Fixed& a, Fixed& b);             /* Returns biggest */
    static Fixed&   max(const Fixed& a, const Fixed& b); /* Returns biggest */

/* -------------------------------------------------------------------------- */
/*                    Binary Arithmetic operators overload                    */
/* -------------------------------------------------------------------------- */
    Fixed   operator+(const Fixed& rhs);
    Fixed   operator-(const Fixed& rhs);
    Fixed   operator*(const Fixed& rhs);
    Fixed   operator/(const Fixed& rhs);
};

/* Extraction operator overload */
std::ostream&   operator<<(std::ostream& os, const Fixed &obj);

#endif // FIXED_HPP