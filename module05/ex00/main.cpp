#include <iostream>
#include "Bureaucrat.hpp"

static void testConstructor(int grade)
{
    try {
        Bureaucrat  robert("Robert", grade);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    /* Testing constructor and all methods */
    try {        
        Bureaucrat  clone1("clone1", 100);
        Bureaucrat  clone2(clone1);
        Bureaucrat  clone3("clone1Clone", 2);
        std::cout << clone1;
        std::cout << clone2;
        clone2 = clone3;
        std::cout << clone2 << std::endl;
    
        Bureaucrat  carlos("Carlos", 1);

        #if !defined(STOP_SIMULATION)

            std::cout << carlos;
            carlos.lowerGrade();
            std::cout << carlos;
            carlos.lowerGrade();
            std::cout << carlos;
        #endif // STOP_SIMULATION
        carlos.lowerGrade();
        carlos.incrementGrade();
        carlos.incrementGrade();
        carlos.incrementGrade();
        carlos.incrementGrade(); /* Throws an exception */

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* Testing Constructor with an out of range grade */
    testConstructor(150);  /* Lowest possible value*/
    testConstructor(0);  /* Throws an exception */
    testConstructor(151);  /* Throws an exception */
    return (0);
}
