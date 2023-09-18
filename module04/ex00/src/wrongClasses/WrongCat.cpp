#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongCat default constructor is called\n";
    #endif // CONSTROCTURS_MSG

    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongCat copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

WrongCat&    WrongCat::operator=(const WrongCat &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongCat copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

WrongCat::~WrongCat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongCat destructor is called\n";
    #endif // CONSTROCTURS_MSG
}


void    WrongCat::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "Miaou, Miaou... Miaou, Miaou..."<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}
