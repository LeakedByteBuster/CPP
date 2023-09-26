#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"



int main(void)
{
    /* 
    *   gradeRequiredToSign && gradeRequiredToExcute == 1 in AForm.cpp
    *       and exception is not thrown
    */
    try {
        Bureaucrat  carlos("Carlos", 15);
        ShrubberyCreationForm   a("Home");

        std::cout << carlos;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
