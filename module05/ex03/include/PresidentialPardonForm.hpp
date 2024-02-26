#if !defined(PRESIDENTIALPARDONFORM_HPP)
#define PRESIDENTIALPARDONFORM_HPP

class   AForm;

class PresidentialPardonForm : public AForm {

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();

    void    childAction(std::string target) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP