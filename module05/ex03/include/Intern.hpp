#if !defined(INTERN_HPP)
#define INTERN_HPP


#include <string>
class   AForm;

class Intern
{

public:
    Intern();
    Intern(const Intern &);
    Intern& operator=(const Intern &);
    ~Intern();

    AForm   *makeForm(std::string formName, std::string target);
};

#endif // INTERN_HPP