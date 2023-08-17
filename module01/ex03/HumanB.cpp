#include "HumanB.hpp"
#include <iostream>

// name's attribute getter and setter
std::string HumanB::getName() const
{
    return (this->name);
}
void        HumanB::setName(std::string name)
{
    this->name = name;
}

Weapon      *HumanB::getWeapon() const
{
    return (this->weapon);
}

// Prints "<name> attacks with their <weapon type>" in STDOUT
void    HumanB::attack()
{
    std::cout << this->name  << "attacks with their " << getWeapon()->getType() \
        << "\n";
}

// Sets Weapon
void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->setName(name);
}