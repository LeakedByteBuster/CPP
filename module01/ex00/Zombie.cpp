#include "Zombie.hpp"
# define HRED "\e[1;91m"
# define RESET "\x1b[0m"

Zombie::Zombie(std::string name)
{
    this->setName(name);
    this->announce();
    return ;
}

Zombie::~Zombie()
{
    std::cout << HRED << "\t" << name << " has died 😔\n" << RESET;
    return ;
}

void    Zombie::announce( void )
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ...\n";
    return ;
}

std::string  Zombie::getName() const
{
    return (this->name);
}

void        Zombie::setName(std::string name)
{
    this->name = name;
    return ;
}
