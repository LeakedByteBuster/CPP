#if !defined(FROM_HPP)
#define FROM_HPP

#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class   Bureaucrat;

class AForm{

private:
    const std::string   name;
    bool                isSigned;
    const int           gradeRequiredToSign;
    const int           gradeRequiredToExecute;

public:
    AForm();
    AForm(const std::string, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm &rhs);
    AForm&  operator=(const AForm &rhs);
    virtual ~AForm() = 0;

    const std::string   getName() const;
    bool                getIsSigned() const;
    int                 getGradeRequiredToSign() const;
    int                 getGradeRequiredToExecute() const;

    void                        setIsSigned(bool value);
    /* Changes the Aform status to signed if the bureaucrat’s grade is high enough */
    void    beSigned(const Bureaucrat &sir);
};

std::ostream&    operator<<(std::ostream &os, const AForm &rhs);

#endif // FROM_HPP