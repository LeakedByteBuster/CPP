#include "Dog.hpp"

Dog::Dog()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog default constructor is called\n";
    #endif // CONSTROCTURS_MSG

    type = "Dog";
}

Dog::Dog(const Dog &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Dog&    Dog::operator=(const Dog &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

Dog::~Dog()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog destructor is called\n";
    #endif // CONSTROCTURS_MSG
}

void    Dog::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "Wooof Woof!"<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}
