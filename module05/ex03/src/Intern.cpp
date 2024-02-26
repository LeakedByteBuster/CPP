#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    #if defined(DEBUG)
        std::cout << "Intern constructor is called" << std::endl;
    #endif  // DEBUG
}

Intern::Intern(const Intern &)
{
    #if defined(DEBUG)
        std::cout << "Intern copy constructor is called" << std::endl;
    #endif  // DEBUG
}

Intern& Intern::operator=(const Intern &)
{
    #if defined(DEBUG)
        std::cout << "Intern copy assignment operator is called" << std::endl;
    #endif  // DEBUG

    return (*this);
}

Intern::~Intern()
{
    #if defined(DEBUG)
        std::cout << "Intern destructor is called" << std::endl;
    #endif  // DEBUG
}

#define __PRINTACTION std::cout << "Intern creates " << formName << std::endl;

AForm   *Intern::makeForm(std::string formName, std::string target)
{
    int res =   (formName == "robotomy request")     * 1 + \
                (formName == "presidential pardon")  * 2 + \
                (formName == "shrubbery creation")   * 3;

    switch (res)
    {
    case 1:
        __PRINTACTION
        return (new RobotomyRequestForm(target)); /* RobotomyRequestForm */
    case 2: 
        __PRINTACTION
        return (new PresidentialPardonForm(target)); /* PresidentialPardonForm */
    case 3:
        __PRINTACTION
        return (new ShrubberyCreationForm(target)); /* ShrubberyCreationForm */
    default:
        std::cerr << "Invalid requested form: " << formName << \
            " not found" << std::endl;
    }
    return (NULL);
}