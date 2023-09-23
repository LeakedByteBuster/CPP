#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*           Constructors & Destructor & Copy Assignement Operator            */
/* -------------------------------------------------------------------------- */

AMateria::AMateria() : mType("?????")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AMateria default constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

AMateria::AMateria(std::string const & type) : mType(type)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AMateria parameterized constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

AMateria::AMateria(AMateria const & rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AMateria copy constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

AMateria&    AMateria::operator=(AMateria const &)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AMateria copy assignement operator is called" << std::endl;
    #endif // CONSTROCTURS_MSG

    return (*this);
}

AMateria::~AMateria()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AMateria destructor constructor is called" << std::endl;
    #endif // CONSTROCTURS_MSG
}

/* ------------------------------------------------------------------------- */
/*                                  Methods                                  */
/* ------------------------------------------------------------------------- */

std::string const & AMateria::getType() const
{
    return (mType);
}

void    AMateria::use(ICharacter&)
{
    std::cout << "???AMateria???" << std::endl;
    return ;
}
