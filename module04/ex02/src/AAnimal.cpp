#include "AAnimal.hpp"

AAnimal::AAnimal() : type("?????")
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AAnimal default constructor is called\n";
    #endif // CONSTROCTURS_MSG
}

AAnimal::AAnimal(const AAnimal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AAnimal copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

AAnimal&    AAnimal::operator=(const AAnimal &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AAnimal copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG
    //  Self assignement guard
    if (this == &rhs)
        return (*this);

    type = rhs.getType();

    return (*this);
}

AAnimal::~AAnimal()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "AAnimal destructor is called\n";
    #endif // CONSTROCTURS_MSG
}

std::string AAnimal::getType() const
{
    return (this->type);
}

void    AAnimal::setType(const std::string type)
{
    this->type = type;
    return ;
}
