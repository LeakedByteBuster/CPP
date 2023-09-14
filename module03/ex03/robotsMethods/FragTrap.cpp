#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    #ifdef DEBUG
        std::cout << "FragTrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "FragTrap " << name <<" is ready for the fight 👊" \
            << std::endl;
    #endif // NOT_SIMULATE

    this->attackDamage2 = 30;
    this->hitPoints2 = 100;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
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
        std::cout << "FragTrap " << name <<" is ready for the fight 👊" \
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

FragTrap::~FragTrap()
{
    #ifdef DEBUG
        std::cout << "FragTrap destructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << name << " is getting out of the ring" << std::endl;
    #endif // NOT_SIMULATE
}

/* Displays a positive high fives request on the standard output */
void    FragTrap::highFivesGuys(void)
{
    #ifndef NOT_SIMULATE
        std::cout << name << " requested a " << HWHT << \
            " High Five!" << NC << std::endl;
    #endif // NOT_SIMULATE
    return ;
}

/* target loses <attack damage> hit points, attacking costs 1 energy */
void FragTrap::attack(const std::string& target)
{
    #ifdef NOT_SIMULATE
        (void)target;
    #endif // NOT_SIMULATE
    if (energyPoints <= 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " cannot attack. 0 energy!\n";
        #endif // NOT_SIMULATE
    }

    setEnergyPoints((energyPoints - 1));

    #ifndef NOT_SIMULATE
        std::cout << name << " attacks " << target << \
        " (SHOUUTS...🔊 Figaroooooooooo!)" << std::endl;
    #endif // NOT_SIMULATE
    return ;
}

int     FragTrap::getAttackDamage2() const
{
    return (this->attackDamage2);
}

int     FragTrap::getHitPoints2() const
{
    return (this->hitPoints2);
}