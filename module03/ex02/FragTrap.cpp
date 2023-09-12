#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    #ifdef DEBUG
        std::cout << "FragTrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "FragTrap " << getName() <<" is ready for the fight 👊" \
            << std::endl;
    #endif // NOT_SIMULATE

    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.getName())
{
    #ifdef DEBUG
        std::cout << "FragTrap copy constructor is called" << std::endl;
    #endif // DEBUG

    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "FragTrap copy assignement operator is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "FragTrap " << getName() <<" is ready for the fight 👊" \
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

FragTrap::~FragTrap()
{
    #ifdef DEBUG
        std::cout << "FragTrap destructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << getName() << " is getting out of the ring" << std::endl;
    #endif // NOT_SIMULATE
}

/* Displays a positive high fives request on the standard output */
void    FragTrap::highFivesGuys(void)
{
    #ifndef NOT_SIMULATE
        std::cout << getName() << " requested a " << HWHT << \
            " High Five!" << NC << std::endl;
    #endif // NOT_SIMULATE
    return ;
}