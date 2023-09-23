#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*           Constructors & Destructor & Copy Assignement Operator            */
/* -------------------------------------------------------------------------- */

Cure::Cure() : AMateria("cure")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cure default constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

Cure::Cure(Cure const &rhs) : AMateria("cure")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cure copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Cure&   Cure::operator=(Cure const &)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cure copy assignement operator is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    return (*this);
}

Cure::~Cure()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cure destructor constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */
AMateria*    Cure::clone() const
{
    AMateria *tmp = new Cure(*this);
    return (tmp);
}

void    Cure::use(ICharacter &target)
{

    #ifndef STOP_SIMULATION
        std::cout << "* heals "<< target.getName() << "'s wound " << " *"\
            << std::endl;
    #else
        (void)target;
    #endif // STOP_SIMULATION

    return ;
}