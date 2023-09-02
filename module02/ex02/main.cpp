/*
* |--------------------------------------------------------------|
* | Operators that can be overloaded    Examples
* |--------------------------------------------------------------|
* | Binary Arithmetic                   +, -, *, /, %
* |--------------------------------------------------------------|
* | Unary Arithmetic                    +, -, ++, —
* |--------------------------------------------------------------|
* | Assignment                          =, +=,*=, /=,-=, %=
* |--------------------------------------------------------------|
* | Bitwise                             & , | , << , >> , ~ , ^
* |--------------------------------------------------------------|
* | De-referencing                      (->)
* |--------------------------------------------------------------|
* | Dynamic memory allocation, 
* |     De-allocation	                New, delete 
* |--------------------------------------------------------------|
* | Subscript                           [ ]
* |--------------------------------------------------------------|
* | Function call                       ()
* |--------------------------------------------------------------|
* | Logical                             &, ||, !
* |--------------------------------------------------------------|
* | Relational                          >, < , = =, <=, >=
* |--------------------------------------------------------------|
*
* ---------------------------------------------------------------------
*   Operator Overloading Syntax :
*   -----------------------------
*       class className {
*           ... .. ...
*           public
*              returnType operator symbol (arguments) {
*                  ... .. ...
*              } 
*           ... .. ...
*       };
* ---------------------------------------------------------------------
*
* Smallest representable value using 8 bits for fractional part is: 2 ^ (-8)
*
*/

#include <iostream>
#include "Fixed.hpp"

/* make CXXFLAGS+="-DNDEBUG -DTEST_CASES" && ./FixedPoint */
int main(void)
{

    Fixed t;
    Fixed const k( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << t << std::endl;
    std::cout << ++t << std::endl;
    std::cout << t << std::endl;
    std::cout << t++ << std::endl;
    std::cout << t << std::endl;
    
    std::cout << k << std::endl;
    
    std::cout << Fixed::max( t, k ) << std::endl;


    #ifdef TEST_CASES

    std::cout << \
"\n/* -------------------------------------------------------------------------- */" << std::endl;
    std::cout << \
"/*                                Tests Cases                                 */" << std::endl;
    std::cout << \
"/* -------------------------------------------------------------------------- */\n" << std::endl;

        Fixed a(10.5f);
        Fixed b(30.5f);
        Fixed c(a - b);

        std::cout << "a is " << a << std::endl;

        /*  Overload  ++a */
        std::cout << "Pre-increment " << ++a << std::endl;
        std::cout << "Pre-increment " << ++a << std::endl;

        /*  Overload  a++ */
        std::cout << "Post-increment " << a++ << std::endl;
        std::cout << "Post-increment " << a++ << std::endl;

        /*  Overload  --a */
        std::cout << "Pre-decrement " << --a << std::endl;
        std::cout << "Pre-decrement " << --a << std::endl;

        /*  Overload  a-- */
        std::cout << "Post-decrement " << a-- << std::endl;
        std::cout << "Post-decrement " << a-- << std::endl;
        std::cout << "a is " << a << std::endl;

        /*  Comparaison Overload operators */
        std::cout << "\n a = " << a << " | b = " << b << " | c = " << c << " \n"\
            << std::endl;
        std::cout << "Operator: a > b ==> " << (a > b) << std::endl;
        std::cout << "Operator: b > a ==> " << (b > a) << std::endl;
        std::cout << "Operator: b < a ==> " << (b < a) << std::endl;
        std::cout << "Operator: a < b ==> " << (a < b) << std::endl;
        std::cout << "Operator: b <= a ==> " << (b <= a) << std::endl;
        std::cout << "Operator: a >= b ==> " << (a >= b) << std::endl;
        std::cout << "Operator: c >= b ==> " << (c >= b) << std::endl;
        std::cout << "Operator: c == b ==> " << (c == b) << std::endl;
        std::cout << "Operator: c == a ==> " << (c == a) << std::endl;
        std::cout << std::endl;
        
        std::cout << "\n a = " << a << " | b = " << b << " | c = " << c << " \n" \
            << std::endl;
        /* Binary Arithmetic operators */
        std::cout << "Operator: a + b = " << (a + b) << std::endl;
        std::cout << "Operator: a + b + c = " << (a + b + c) << std::endl;
        std::cout << "Operator: a * b = " << (a * b) << std::endl;
        std::cout << "Operator: a * b * c = " << (a * b * c) << std::endl;
        std::cout << "Operator: a - b = " << (a - b) << std::endl;
        std::cout << "Operator: a - b - c = " << (a - b - c) << std::endl;
        std::cout << "Operator: a / b = " << (a / b) << std::endl;
        std::cout << "Operator: a / 2 = " << (a / 2) << std::endl;


        std::cout << std::endl;

        std::cout << "\n a = " << a << " | b = " << b << " | c = " << c << " \n" \
            << std::endl;
        /* Static Member functions */
        std::cout << "min(a, b): res = " << Fixed::min(a, b) << std::endl;
        std::cout << "min(c, b): res = " << Fixed::min(c, b) << std::endl;
        std::cout << "min(const a, const b): res = " << Fixed::min((const Fixed&)a,\
            (const Fixed&)b) << std::endl;
        std::cout << "max(a, b): res = " << Fixed::max(a, b) << std::endl;
        std::cout << "max(c, b): res = " << Fixed::max(c, b) << std::endl;
        std::cout << "max(const a, const b): res = " << Fixed::max((const Fixed&)a,\
            (const Fixed&)b) << std::endl;

    #endif // TEST_CASES

    return 0;
}
