#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    #ifdef DEBUG
        std::cout << "ScavTrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ScavTrap " << name <<" step into the ring 🤼" \
            << std::endl;
    #endif // NOT_SIMULATE

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    #ifdef DEBUG
        std::cout << "ScavTrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ScavTrap " << name <<" step into the ring 🤼" \
            << std::endl;
    #endif // NOT_SIMULATE

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
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
        std::cout << "ScavTrap " << name <<" step into the ring 🤼" \
            << std::endl;
    #endif // NOT_SIMULATE

    if (this != &rhs)
    {
        name = rhs.getName();
        hitPoints = rhs.getHitPoints();
        attackDamage = rhs.getAttackDamage();
        energyPoints = rhs.getEnergyPoints();
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
    if (hitPoints > 0 && energyPoints > 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " entered in" << HWHT << \
                " Gate keeper mode" << NC << std::endl;
        #endif // NOT_SIMULATE
    }
    else
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " cannot enter in" << HWHT << \
                " Gate keeper mode" << NC << std::endl;
        #endif // NOT_SIMULATE
    }
    return ;
}
