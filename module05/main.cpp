#include <iostream>
#include "Bureaucrat.hpp"

static void testConstructor(int grade)
{
    try {
        Bureaucrat  w("Carlos", grade);
    } catch (const Bureaucrat &e) {
        if (e.getGrade() < 150)
            e.GradeTooHighException();
        else
            e.GradeTooLowException();
    }
}

int main(void)
{
    /* Testing constructor and all methods */
    try{
        Bureaucrat  a("Carlos", 1);   /* Throws an exception */
        a.setName("Carlos");
        #if !defined(STOP_SIMULATION)
            std::cout << a;
            a.lowerGrade();
            std::cout << a;
            a.lowerGrade();
            std::cout << a;
        #endif // STOP_SIMULATION
        a.lowerGrade();
        a.incrementGrade();
        a.incrementGrade();
        a.incrementGrade();
        a.incrementGrade(); /* Throws an exception */

    } catch (const Bureaucrat &e) {
        if (e.getGrade() < 150)
            e.GradeTooHighException();
        else
            e.GradeTooLowException();
    }

    /* Testing Constructor with an out of range grade */
    testConstructor(150);  /* Throws nothing || Lowest possible*/
    testConstructor(0);  /* Throws an exception */
    testConstructor(151);  /* Throws an exception */
    return (0);
}
