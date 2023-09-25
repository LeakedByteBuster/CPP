#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade <= 0 || grade > 150)
        throw *this;
}

void            Bureaucrat::GradeTooHighException() const
{
    #if !defined(STOP_SIMULATION)
        std::cout <<  name << " Grade too high! " << grade << std::endl;
    #endif // STOP_SIMULATION
}

void            Bureaucrat::GradeTooLowException() const
{
    #if !defined(STOP_SIMULATION)
        std::cout << name << " Grade too low! " << grade << std::endl;
    #endif // STOP_SIMULATION
}

void            Bureaucrat::incrementGrade()
{
    if ((grade - 1) <= 0)
        throw *this;
    grade--;
}

void            Bureaucrat::lowerGrade()
{
    if ((grade + 1) > 150)
        throw *this;
    grade++;
}

std::string     Bureaucrat::getName() const
{
    return (name);
}

int             Bureaucrat::getGrade() const
{
    return (grade);
}

void            Bureaucrat::setName(const std::string &name)
{
    this->name = name;
}

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}