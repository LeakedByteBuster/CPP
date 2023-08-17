#include "Weapon.hpp"

// Returns a const reference to type
void    Weapon::setType(std::string type)
{
    this->type = type;
}

// Sets type using the new one passed as parameter
std::string       Weapon::getType() const
{
    return (this->type);
}

Weapon::Weapon(std::string type)
{
    Weapon::setType(type);
    return ;
}
