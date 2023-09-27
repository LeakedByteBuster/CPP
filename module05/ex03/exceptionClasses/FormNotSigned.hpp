#if !defined(FORMNOTSIGNED_HPP)
#define FORMNOTSIGNED_HPP

#include <stdexcept>

class   FormNotSigned : public std::runtime_error
{
public:
    FormNotSigned(std::string error);
};

#endif // FORMNOTSIGNED_HPP