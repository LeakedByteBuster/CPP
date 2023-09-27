#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
    #if defined(DEBUG)
        std::cout << "PresidentialPardonForm default constructor is called\n";
    #endif // DEBUG
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5)
{
    #if defined(DEBUG)
        std::cout << "PresidentialPardonForm parameterized constructor is called\n";
    #endif // DEBUG

    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs)
{
    #if defined(DEBUG)
        std::cout << "PresidentialPardonForm copy constructor is called\n";
    #endif // DEBUG
    
    setTarget(rhs.getTarget());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    #if defined(DEBUG)
        std::cout << "PresidentialPardonForm copy assignement operator is called\n";
    #endif // DEBUG

    if (this != &rhs){
        setIsSigned(rhs.getIsSigned());
        setTarget(rhs.getTarget());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    #if defined(DEBUG)
        std::cout << "PresidentialPardonForm destructor is called\n";
    #endif // DEBUG
}

void    PresidentialPardonForm::childAction(std::string target) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}