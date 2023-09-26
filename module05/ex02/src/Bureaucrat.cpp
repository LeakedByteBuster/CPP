#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(0)
{
    #if defined(DEBUG)
        std::cout << "Bureaucrat constructor is called" << std::endl;
    #endif  // DEBUG

    if (grade <= HIGH_GRADE)
        throw GradeTooHighException(name + " Grade too high!");
    else if (grade > LOW_GRADE)
        throw GradeTooLowException(name + " Grade too low!");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    #if defined(DEBUG)
        std::cout << "Bureaucrat parameterized constructor is called" << std::endl;
    #endif  // DEBUG

    if (grade <= HIGH_GRADE)
        throw GradeTooHighException(name + " Grade too high!");
    else if (grade > LOW_GRADE)
        throw GradeTooLowException(name + " Grade too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.getName()), grade(rhs.getGrade())
{
    #if defined(DEBUG)
        std::cout << "Bureaucrat copy constructor is called" << std::endl;
    #endif  // DEBUG
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
    #if defined(DEBUG)
        std::cout << "Bureaucrat copy assignment operator is called" << std::endl;
    #endif  // DEBUG

    if (this != &rhs){
        grade = rhs.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    #if defined(DEBUG)
        std::cout << "Bureaucrat destructor is called" << std::endl;
    #endif  // DEBUG
}

void            Bureaucrat::incrementGrade()
{
    if ((grade - 1) <= HIGH_GRADE)
        throw GradeTooHighException("Cannot increment " + name + " Grade too high!");
    grade--;
}

void            Bureaucrat::lowerGrade()
{
    if ((grade + 1) > LOW_GRADE)
        throw GradeTooLowException("Cannot lower " + name + " Grade too low!");
    grade++;
}

const std::string     Bureaucrat::getName() const
{
    return (name);
}

int             Bureaucrat::getGrade() const
{
    return (grade);
}

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}

void                Bureaucrat::signForm(const AForm &form) const
{
    if (form.getIsSigned()) {   
        std::cout << name << " signed " << form.getName() << std::endl;
        return ;
    }
    std::cout << name << " couldn't sign " << form.getName() << " because ";
}
