#ifndef FIXED_HPP
#define FIXED_HPP


class   Fixed{ /* Fixed point */
private:
    int                 num;    /* Integer part */
    static const int    frac; /*  Fractional part  */

public :
    
    Fixed(); /* Default Constructor */
    Fixed(const Fixed &); /* Copy Constructor */
    Fixed&  operator=(const Fixed &); /* Copy Assignement Operator */
    ~Fixed(); /* Destructor */

    int getRawBits(void) const;
    void setRawBits(int const);

};

#endif // FIXED_HPP