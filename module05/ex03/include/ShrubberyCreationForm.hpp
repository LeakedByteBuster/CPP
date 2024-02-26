#if !defined(SHRUBBERYCREATIONFORM_HPP)
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

    void    childAction(std::string target) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP