#include "Ice.hpp"

/* -------------------------------------------------------------------------- */
/*           Constructors & Destructor & Copy Assignement Operator            */
/* -------------------------------------------------------------------------- */

Ice::Ice() : AMateria("ice")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Ice default constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

Ice::Ice(Ice const &rhs) : AMateria("ice")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Ice copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Ice&    Ice::operator=(Ice const &)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Ice copy assignement operator is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    return (*this);
}

Ice::~Ice()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Ice destructor constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */

AMateria*    Ice::clone() const
{
    Ice *tmp = new Ice(*this);
    return (tmp);
}

void    Ice::use(ICharacter &target)
{
    #if !defined(STOP_SIMULATION)
        std::cout << "* shoots an ice bolt at " << target.getName() << " *";
    #else
        (void)target;
    #endif // STOP_SIMULATION

    return ;
}