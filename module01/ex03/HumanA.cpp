#include "HumanA.hpp"
#include <iostream>

// name's attribute getter and setter
std::string HumanA::getName() const
{
    return (this->name);
}

//  Sets name attribute
void        HumanA::setName(std::string name)
{
    this->name = name;
}

// Passes given paramater to the attribute weapon as a refrence
void    HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}

Weapon  &HumanA::getWeapon() const
{
    return (this->weapon);
}

// Prints "<name> attacks with their <weapon type>" in STDOUT
void        HumanA::attack()
{
    std::cout << this->name  << "attacks with their " << getWeapon().getType()\
        << "\n";
    return ;
}

//  Constructor
/*
*   ':' ; Used to indicate the list of initializers
*   Initialize attributes when the object is
*       created. The members will be initialized before HumanA's body is executed
*   Syntax: ClassName::ClassName(parameters) : parameter1(value1), parameter(value2)...
*/
HumanA::HumanA(std::string name,  Weapon &weapon) : name(name), weapon(weapon)
{
    return ;
}