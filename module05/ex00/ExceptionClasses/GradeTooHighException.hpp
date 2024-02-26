#if !defined(GRADETOOHIGHEXCEPTION_HPP)
#define GRADETOOHIGHEXCEPTION_HPP

#include <stdexcept>  // std::invalid_argument

class GradeTooHighException : public std::invalid_argument
{
public:
    GradeTooHighException(const std::string &error);
};

#endif // GRADETOOHIGHEXCEPTION_HPP