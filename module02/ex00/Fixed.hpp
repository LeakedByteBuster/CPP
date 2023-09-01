#ifndef FIXED_HPP
#define FIXED_HPP

// num ==> number part | | frac ==> fraction part
/* Fixed point */
class   Fixed{
private:
    int                 num;
    static const int    frac;

public :
    /* Default Constructor */
    Fixed();
    /* Copy Constructor */
    Fixed(const Fixed &);
    /* Copy Assignement Operator */
    Fixed&  operator=(const Fixed &);
    /* Destructor */
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const);

};

#endif // FIXED_HPP