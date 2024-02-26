#if !defined(GRADETOOLOWEXCEPTION_HPP)
#define GRADETOOLOWEXCEPTION_HPP

#include <stdexcept> // std::invalid_argument

class GradeTooLowException : public std::invalid_argument
{
public:
    GradeTooLowException(const std::string &error);
};

#endif // GRADETOOLOWEXCEPTION_HPP