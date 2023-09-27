#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#if defined(LEAKS)
    void    lk()
    {
        system("leaks Bureaucrat");
    }
#endif // Leaks

int main(void)
{
    AForm       *rrf = NULL;
    AForm       *srf = NULL;
    AForm       *prf = NULL;

    try {
        Bureaucrat  presi("A7enkouch", 1);
        Intern      randomInterns;

        rrf = randomInterns.makeForm("robotomy request", "Bender");
        if (!rrf) { return (1); }
        srf = randomInterns.makeForm("shrubbery creation", "Bender");
        if (!srf) { delete rrf; return (1); }
        prf = randomInterns.makeForm("presidential pardon", "Bender");
        if (!prf) { delete rrf; delete srf; return (1); }
        
        std::cout << *rrf;
        std::cout << *srf;
        std::cout << *prf;

        rrf->beSigned(presi);
        srf->beSigned(presi);
        // prf->beSigned(presi); /* Uncomment this to execute prf */
        presi.executeForm(*rrf);
        presi.executeForm(*srf);
        presi.executeForm(*prf);

        delete rrf;
        delete srf;
        delete prf;

    } catch (const std::exception &e) {
        if (rrf) { delete rrf; }
        if (srf) { delete srf; }
        if (prf) { delete prf; }
        std::cout << e.what() << std::endl;
    }

    #if defined(LEAKS)
        atexit(lk);
    #endif // LEAKS
    return (0);
}
