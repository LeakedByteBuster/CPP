#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "FormNotSigned.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

AForm::AForm() : name(""), isSigned(0), gradeRequiredToSign(0), 
                gradeRequiredToExecute(0)
{
    #if defined(DEBUG)
        std::cout << "Form constructor is called" << std::endl;
    #endif  // DEBUG

    throw GradeTooHighException("Invalid arguments: grades of the executor are equal to 0");
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), 
    isSigned(0) , gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    #if defined(DEBUG)
        std::cout << "Form parameterized constructor is called" << std::endl;
    #endif  // DEBUG

    if (gradeToSign <= HIGH_GRADE || gradeToExecute <= HIGH_GRADE)
        throw GradeTooHighException(name + " grade too high");
    if (gradeToSign > LOW_GRADE || gradeToExecute > LOW_GRADE)
        throw GradeTooLowException(name + " grade too low");
}

AForm::AForm(const AForm &rhs) : name(rhs.getName()), isSigned(rhs.getIsSigned()),
        gradeRequiredToSign(rhs.getGradeRequiredToSign()), 
            gradeRequiredToExecute(rhs.getGradeRequiredToExecute())
{
    #if defined(DEBUG)
        std::cout << "Form copy constructor is called" << std::endl;
    #endif  // DEBUG
}

AForm& AForm::operator=(const AForm &rhs)
{
    #if defined(DEBUG)
        std::cout << "Form copy assignment operator is called" << std::endl;
    #endif  // DEBUG

    if (this != &rhs){
        isSigned = rhs.getIsSigned();
    }
    return (*this);
}

AForm::~AForm()
{
    #if defined(DEBUG)
        std::cout << "Form destructor is called" << std::endl;
    #endif  // DEBUG
}

/* -------------------------------------------------------------------------- */
/*                                  Methods                                   */
/* -------------------------------------------------------------------------- */

const std::string     AForm::getName() const
{
    return (name);
}

std::string AForm::getTarget() const
{
    return (target);
}

bool            AForm::getIsSigned() const
{
    return (isSigned);
}

int             AForm::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int             AForm::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

void    AForm::setTarget(std::string target)
{
    this->target = target;
}

std::ostream&    operator<<(std::ostream &os, const AForm &rhs)
{
    os << "name : " << rhs.getName() << " | GradeToExecute: " \
        << rhs.getGradeRequiredToExecute() << " | isSigned : " << rhs.getIsSigned() \
        << " | GradeToSign: " << rhs.getGradeRequiredToSign() << std::endl;

    return (os);
}

void    AForm::beSigned(const Bureaucrat &sir)
{
    if (sir.getGrade() > gradeRequiredToSign) {
        sir.signForm(*this);
        throw   GradeTooLowException(sir.getName() + " grade is too low!");
    }
    isSigned = 1;
    sir.signForm(*this);
}

void    AForm::setIsSigned(bool value)
{
    isSigned = value;
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw   FormNotSigned( name + " Form is not signed");
    if (executor.getGrade() > gradeRequiredToExecute)
        throw   GradeTooLowException(executor.getName() + " doesn't have " 
            "required grade to execute the following form " + name);
    executor.executeForm(*this);
}