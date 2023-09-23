#include "Cat.hpp"

Cat::Cat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat default constructor is called\n";
    #endif // CONSTROCTURS_MSG

    type = "Cat";
}

Cat::Cat(const Cat &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Cat&    Cat::operator=(const Cat &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

Cat::~Cat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat destructor is called\n";
    #endif // CONSTROCTURS_MSG
}

void    Cat::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "Miaou, Miaou..."<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}
