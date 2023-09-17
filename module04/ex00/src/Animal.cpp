#include "Animal.hpp"

Animal::Animal() : type("?????")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Animal default constructor is called\n";
    #endif // CONSTROCTURS_MSG
}

Animal::Animal(const Animal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Animal copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Animal&    Animal::operator=(const Animal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Animal copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

Animal::~Animal()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Animal destructor is called\n";
    #endif // CONSTROCTURS_MSG
}

std::string Animal::getType() const
{
    return (this->type);
}

void    Animal::setType(const std::string type)
{
    this->type = type;
    return ;
}


void    Animal::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "?????"<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}
