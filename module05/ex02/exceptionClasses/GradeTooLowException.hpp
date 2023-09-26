#if !defined(GRADETOOLOWEXCEPTION_HPP)
#define GRADETOOLOWEXCEPTION_HPP

#include <stdexcept> // std::invalid_argument

#define LOW_GRADE 150

class GradeTooLowException : public std::invalid_argument
{
public:
    GradeTooLowException(const std::string &error);
};

#endif // GRADETOOLOWEXCEPTION_HPP