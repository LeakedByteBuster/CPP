/*
*   IEE 754 : s ==> sign | e ==> exponent | 'm' => mantissa
*                             | n ==> number of bits for fractional part
*   
*   1.  Multiplication of floating numbers
*           [ Formula (m1 * m2) * (2 ^ (e1 + e2)) ]
*   2.  Multiply the given float or int number by (2 ^ n)
*   3.  round the result before storing it the fixed point, if needed
*   4.  convert your fixed point representation back to float or int by:
*           [  FixedPointRepresentation / 2^n ]
*   Note: std::cout its precision is up 5
*/

#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
