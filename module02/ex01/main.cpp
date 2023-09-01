/*
*   IEE 754 Multiplaction: s ==> sign | e ==> exponent | 'm' => mantissa 
*                               | n ==> number of bits for fractional part
*   
*   1.  Converting from floating point to FixedPoint
*           [ Formula (m1 * m2) * 2 ^ (e1 + e2) ]
*   2.  round the result before storing it the fixed point
*   3.  convert your fixed point representation to float by:
*           [  FixedPointRepresentation / 2^n ]
*   Note: std::cout its precision is up 5
*/

#include <iostream>
#include "Fixed.hpp"

void    printBinary()
{
    int  x = 1;
    int  n = sizeof(int) * 8 -1;

    n = sizeof(int) * 8 -1;
    for (; n >= 0;n--){
        std::cout << ((x >> n) & 1);
        if (n%8 == 0)
            printf(" ");
    }
    std::cout << "\n";
    return ;
}

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

    #ifndef NDEBUG
        printBinary();
    #endif // NDEBUG

    return 0;
}
