#if !defined(GRADETOOHIGHEXCEPTION_HPP)
#define GRADETOOHIGHEXCEPTION_HPP

#include <stdexcept>  // std::invalid_argument

#define HIGH_GRADE 0 /* The highest grade is 1 not 0 */

class GradeTooHighException : public std::invalid_argument
{
public:
    GradeTooHighException(const std::string &error);
};

#endif // GRADETOOHIGHEXCEPTION_HPP