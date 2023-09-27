#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
    try {
        #if !defined(ASSIGN)
            Bureaucrat  carlos("TheBossOfTheBosses", 6);
            std::cout << carlos;
            ShrubberyCreationForm   tree("TreePlanter");
            std::cout << tree;
            RobotomyRequestForm     robot("PoliticalEnemy1");
            std::cout << robot;
            PresidentialPardonForm  president("President");
            std::cout << president << std::endl;
            
            tree.beSigned(carlos);
            robot.beSigned(carlos);
            president.beSigned(carlos);

            tree.execute(carlos);
            robot.execute(carlos);
            president.execute(carlos);

        #else
            Bureaucrat  carl("TheBossOfTheBosses", 150);
            Bureaucrat  carlos(carl);
            std::cout << carlos;
            ShrubberyCreationForm   tr("TreePlanter");
            ShrubberyCreationForm   tree(tr);
            std::cout << tree;
            RobotomyRequestForm     rob("PoliticalEnemy1");
            RobotomyRequestForm     robot(rob);
            std::cout << robot;
            PresidentialPardonForm  pres("President");
            PresidentialPardonForm  president(pres);
            std::cout << president << std::endl;

                        
            tree.beSigned(carlos);
            robot.beSigned(carlos);
            president.beSigned(carlos);

            tree.execute(carlos);
            robot.execute(carlos);
            president.execute(carlos);

        #endif // ASSIGN



    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
