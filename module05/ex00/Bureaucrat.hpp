#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

#define LOW_GRADE 150
#define HIGH_GRADE 0

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;

public:
    Bureaucrat();
    Bureaucrat(std::string, int);
    Bureaucrat(const Bureaucrat &);
    Bureaucrat&  operator=(const Bureaucrat &);
    ~Bureaucrat();

    void                incrementGrade();
    void                lowerGrade();
    const std::string   getName() const;
    int                 getGrade() const;
};

std::ostream&   operator<<(std::ostream &, const Bureaucrat &);

#endif // BUREAUCRAT_HPP