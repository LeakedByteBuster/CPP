#include "Dog.hpp"

void    deepCopyDog(std::string dst[], const std::string src[])
{
    for (int i = 0; i < NUMBER_OF_IDEAS; i++){
        dst[i] = src[i];
    }
}

Dog::Dog()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog default constructor is called\n";
    #endif // CONSTROCTURS_MSG

    ideas = new Brain();
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

    ideas = new Brain();
    deepCopyDog(this->ideas->getIdeas(), rhs.ideas->getIdeas());
    type = rhs.getType();

    return (*this);
}

Dog::~Dog()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Dog destructor is called\n";
    #endif // CONSTROCTURS_MSG

    delete  ideas;
}

void    Dog::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "Wooof Woof!"<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}

std::string*    Dog::getIdeas() const
{
    return (ideas->Brain::getIdeas());
}
