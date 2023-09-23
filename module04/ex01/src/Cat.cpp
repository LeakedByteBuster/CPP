#include "Cat.hpp"

void    deepCopyCat(std::string dst[], const std::string src[])
{
    for (int i = 0; i < NUMBER_OF_IDEAS; i++){
        dst[i] = src[i];
    }
}

Cat::Cat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat default constructor is called\n";
    #endif // CONSTROCTURS_MSG

    ideas = new Brain();
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
    
    ideas = new Brain();
    deepCopyCat(this->ideas->getIdeas(), rhs.ideas->getIdeas());
    type = rhs.getType();

    return (*this);
}

Cat::~Cat()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Cat destructor is called\n";
    #endif // CONSTROCTURS_MSG

    delete  ideas;
}

void    Cat::makeSound() const
{
    #ifndef STOP_SIMULATION
        std::cout << "Miaou, Miaou..."<< std::endl;
    #endif  // STOP_SIMULATION

    return ;
}

std::string*    Cat::getIdeas() const
{
    return (ideas->Brain::getIdeas());
}
