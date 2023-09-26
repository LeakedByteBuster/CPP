#include <iostream>
#include <time.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
    #if defined(DEBUG)
        std::cout << "RobotomyRequestForm default constructor is called\n";
    #endif // DEBUG
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45)
{
    #if defined(DEBUG)
        std::cout << "RobotomyRequestForm parameterized constructor is called\n";
    #endif // DEBUG

    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs)
{
    #if defined(DEBUG)
        std::cout << "RobotomyRequestForm copy constructor is called\n";
    #endif // DEBUG
    
    setTarget(rhs.getTarget());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    #if defined(DEBUG)
        std::cout << "RobotomyRequestForm copy assignement operator is called\n";
    #endif // DEBUG

    if (this != &rhs){
        setIsSigned(rhs.getIsSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    #if defined(DEBUG)
        std::cout << "RobotomyRequestForm destructor is called\n";
    #endif // DEBUG
}

void    RobotomyRequestForm::childAction(std::string target) const
{
    std::cout << "drr...rrrrr...rrrrrr.... (drilling noises)\n";

    srand(time(NULL));
    bool    successOrFailure = rand() % 2;
    if (successOrFailure)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << "the robotomy failed\n";
}