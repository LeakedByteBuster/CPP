#if !defined(GRADETOOLOWEXCEPTION_HPP)
#define GRADETOOLOWEXCEPTION_HPP

#include <stdexcept> // std::invalid_argument
#include <string>

#define LOW_GRADE 150

class GradeTooLowException : public std::invalid_argument
{

public:
    // std::string filename;
    // int         lineNumber;
    GradeTooLowException(const std::string &error);
};

#endif // GRADETOOLOWEXCEPTION_HPP