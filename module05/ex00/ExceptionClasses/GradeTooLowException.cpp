#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(const std::string &error) : invalid_argument(error)
{
}