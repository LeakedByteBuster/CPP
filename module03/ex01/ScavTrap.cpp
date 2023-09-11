#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    #ifdef DEBUG
        std::cout << "ScavTrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ScavTrap " << getName() <<" step into the ring 🤼" \
            << std::endl;
    #endif // NOT_SIMULATE

    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName())
{
    #ifdef DEBUG
        std::cout << "ScavTrap copy constructor is called" << std::endl;
    #endif // DEBUG

    *this = other;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "ScavTrap copy assignement operator is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ScavTrap " << getName() <<" step into the ring 🤼" \
            << std::endl;
    #endif // NOT_SIMULATE

    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setAttackDamage(rhs.getAttackDamage());
        this->setEnergyPoints(rhs.getEnergyPoints());
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    #ifdef DEBUG
        std::cout << "ScavTrap destructor is called" << std::endl;
    #endif // DEBUG
}

void        ScavTrap::guardGate()
{
    #ifndef NOT_SIMULATE
        std::cout << getName() << " entered in" << HWHT << \
            " Gate keeper mode" << NC << std::endl;
    #endif // NOT_SIMULATE
    return ;
}
