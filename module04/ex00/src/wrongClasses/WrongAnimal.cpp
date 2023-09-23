#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("???Wrong???")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongAnimal default constructor is called\n";
    #endif // CONSTROCTURS_MSG
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongAnimal copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongAnimal copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "WrongAnimal destructor is called\n";
    #endif // CONSTROCTURS_MSG
}


void    WrongAnimal::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "???Wrong???" << std::endl;
    #endif  // STOP_SIMULATION

    return ;
}

std::string     WrongAnimal::getType() const
{
    return (type);
}

void            WrongAnimal::setType(std::string type)
{
    this->type = type;
    return ;
}
