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
    
    /* __INT Constructor */
    Fixed(const int);
    /* __FLOAT Constructor */
    Fixed(const float);

    /* Copy Assignement Operator */
    Fixed&  operator=(const Fixed &);
    /* Destructor */
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const);

    float   toFloat( void ) const;
    int     toInt( void ) const;

};

std::ostream&   operator<<(std::ostream& os, const Fixed &obj);

#endif // FIXED_HPP