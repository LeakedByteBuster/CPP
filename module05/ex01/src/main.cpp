#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Form a("Approval Form", 11, 16);
        Form b("Approval Form", 11, 16);
        { /*  These are temporary for testing copy constructor  */
            Form b(a);
            std::cout << b;
            a = b;
            std::cout << a << std::endl;
        }

        Bureaucrat  carlos("Carlos", 11);
        Bureaucrat  robert("Robert", 12);
        a.beSigned(carlos);
        b.beSigned(robert); /* Throws an exception */

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
