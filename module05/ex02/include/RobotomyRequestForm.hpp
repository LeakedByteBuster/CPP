#if !defined(ROBOTOMYREQUESTFORM_HPP)
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

//RobotomyRequestForm
class RobotomyRequestForm : public AForm {

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();

    void    childAction(std::string target) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP