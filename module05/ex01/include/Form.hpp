#if !defined(FROM_HPP)
#define FROM_HPP

#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class   Bureaucrat;

class Form{

private:
    const std::string   name;
    bool                isSigned;
    const int           gradeRequiredToSign;
    const int           gradeRequiredToExecute;

public:
    Form();
    Form(const std::string, const int gradeToSign, const int gradeToExecute);
    Form(const Form &rhs);
    Form&  operator=(const Form &rhs);
    ~Form();

    const std::string   getName() const;
    bool                getIsSigned() const;
    int                 getGradeRequiredToSign() const;
    int                 getGradeRequiredToExecute() const;
    /* Changes the form status to signed if the bureaucrat’s grade is high enough */
    void    beSigned(const Bureaucrat &sir);
};

std::ostream&    operator<<(std::ostream &os, const Form &rhs);

#endif // FROM_HPP