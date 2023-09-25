#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <string>

/* Exception class */
class Bureaucrat
{
private:
    std::string name;
    int grade;
public:
    Bureaucrat(std::string, int);

    void            GradeTooHighException() const;
    void            GradeTooLowException() const;
    void            incrementGrade();
    void            lowerGrade();
    std::string     getName() const;
    void            setName(const std::string &);
    int             getGrade() const;
};

std::ostream&   operator<<(std::ostream &, const Bureaucrat &);

#endif // BUREAUCRAT_HPP