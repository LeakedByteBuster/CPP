#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
    /* 
    *   gradeRequiredToSign && gradeRequiredToExcute == 1 in AForm.cpp
    *       and exception is not thrown
    * 
    *     drawTree(ofs); in ShrubberyCreationForm(target)
    * 
    *   Copy taget variable
    */
    try {
        Bureaucrat  carlos("Carlos", 70);
        ShrubberyCreationForm   tree("Mar");
        RobotomyRequestForm     robot("Marouane");


        // std::cout << robot;
        // std::cout << carlos;
        // std::cout << tree;

        tree.beSigned(carlos);
        tree.execute(carlos);
        robot.beSigned(carlos);
        robot.execute(carlos);

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
