#include "Form.hpp"
#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Form::Form() : name(""), isSigned(0), gradeRequiredToSign(0), 
                gradeRequiredToExecute(0)
{
    #if defined(DEBUG)
        std::cout << "Form constructor is called" << std::endl;
    #endif  // DEBUG

    throw GradeTooHighException("Invalid arguments to constructor Form::Form():"\
                                   " grades are equal to 0");
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), 
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

Form::Form(const Form &rhs) : name(rhs.getName()), isSigned(rhs.getIsSigned()),
        gradeRequiredToSign(rhs.getGradeRequiredToSign()), 
            gradeRequiredToExecute(rhs.getGradeRequiredToExecute())
{
    #if defined(DEBUG)
        std::cout << "Form copy constructor is called" << std::endl;
    #endif  // DEBUG
}

Form& Form::operator=(const Form &rhs)
{
    #if defined(DEBUG)
        std::cout << "Form copy assignment operator is called" << std::endl;
    #endif  // DEBUG

    if (this != &rhs){
        isSigned = rhs.getIsSigned();
    }
    return (*this);
}

Form::~Form()
{
    #if defined(DEBUG)
        std::cout << "Form destructor is called" << std::endl;
    #endif  // DEBUG
}

/* -------------------------------------------------------------------------- */
/*                                  Methods                                   */
/* -------------------------------------------------------------------------- */

const std::string     Form::getName() const
{
    return (name);
}

bool            Form::getIsSigned() const
{
    return (isSigned);
}

int             Form::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int             Form::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

std::ostream&    operator<<(std::ostream &os, const Form &rhs)
{
    os << "name : " << rhs.getName() << " | GradeToExecute: " \
        << rhs.getGradeRequiredToExecute() << " | isSigned : " << rhs.getIsSigned() \
        << " | GradeToSign: " << rhs.getGradeRequiredToSign() << std::endl;

    return (os);
}

void    Form::beSigned(const Bureaucrat &sir)
{
    if (sir.getGrade() > gradeRequiredToSign) {
        sir.signForm(*this);
        throw   GradeTooLowException(sir.getName() + " grade is too low!");
    }
    isSigned = 1;
    sir.signForm(*this);
}