#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const std::string &error) : invalid_argument(error)
{
}
