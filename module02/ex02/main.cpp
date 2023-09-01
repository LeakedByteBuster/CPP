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
  |     De-allocation	                New, delete 
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
*
*/

#include <iostream>
#include "Fixed.hpp"

int main()
{

    #ifdef TEST_CASES
        Fixed a(10);
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
    #endif // TEST_CASES

    return 0;
}
