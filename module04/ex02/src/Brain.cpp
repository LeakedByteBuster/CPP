#include <iostream>
#include "Brain.hpp"

void    CopyString(std::string dst[], const std::string src[])
{
    int i = 0;
    while (!src[i].empty()){
        dst[i] = src[i];
        i++;
    }
    return ;
}

Brain::Brain()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Brain default constructor is called\n";
    #endif // CONSTROCTURS_MSG
}

Brain::Brain(const Brain &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Brain copy constructor is called\n";
    #endif // CONSTROCTURS_MSG

    *this = rhs;
}

Brain& Brain::operator=(const Brain &rhs)
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Brain copy assignement operator is called\n";
    #endif // CONSTROCTURS_MSG

    /* Performing a deep copy */
    CopyString(this->ideas, rhs.ideas);
    return (*this);
}

Brain::~Brain()
{
    #ifdef CONSTROCTURS_MSG
        std::cout << "Brain destructor is called\n";
    #endif // CONSTROCTURS_MSG
}

void    Brain::setIdeas(const std::string ideas[])
{
    CopyString(this->ideas, ideas);
    return ;
}

std::string*    Brain::getIdeas() const
{
    return ((std::string *)ideas);
}
