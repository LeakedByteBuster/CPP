#include "ClapTrap.hpp"
#include <iostream>

#define CLAP_ENERGY 10

/* -------------------------------------------------------------------------- */
/*                               Orthodox Form                                */
/* -------------------------------------------------------------------------- */

/* Default Constructor */
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
                                       energyPoints(10), attackDamage(0)
{
    #ifdef DEBUG
        std::cout << "Claptrap parameterized constructor is called" << std::endl; 
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ClapTrap " << name << " is making noises" << std::endl;
    #endif // NOT_SIMULATE
}

/* Copy Constructor */
ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "Claptrap copy constructor is called" << std::endl; 
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ClapTrap " << rhs.name << " duplicate step into the ring"\
            << std::endl;
    #endif // NOT_SIMULATE

    *this = rhs;
    return ;
}

/* Copy Assignement Operator */
ClapTrap&    ClapTrap::operator=(const ClapTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "Claptrap operator= is called" << std::endl; 
    #endif // DEBUG

    if (this != &rhs)
    {
        this->name = rhs.name; 
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    return (*this);
}

/* Destructor */
ClapTrap::~ClapTrap()
{

    #ifdef DEBUG
        std::cout << "ClapTrap destructor is called" << std::endl; 
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        if (hitPoints == 0)
            std::cout << name << " lost the fight!" << std::endl;
        else
            std::cout << name << " is a real warrior!" << std::endl;
    #endif // NOT_SIMULATE
}

/* -------------------------------------------------------------------------- */
/*                                  Methods                                   */
/* -------------------------------------------------------------------------- */

/* target loses <attack damage> hit points, Attacking costs 1 energy */
void ClapTrap::attack(const std::string& target)
{
    #ifdef NOT_SIMULATE
        (void)target;
    #endif // NOT_SIMULATE
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " cannot attack\n";
        #endif // NOT_SIMULATE
        return ;
    }

    energyPoints -= 1;

    #ifndef NOT_SIMULATE
        std::cout << name << " attacks " << target << std::endl;
    #endif // NOT_SIMULATE
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << HWHT;
    if (hitPoints <= 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " is dead!\n";
        #endif // NOT_SIMULATE
        std::cout << NC;
        return ;
    }

    hitPoints -= amount;
    /* In case the hit killed the player */
    if (hitPoints <= 0)
    {
        hitPoints = 0;
        #ifndef NOT_SIMULATE
            std::cout << "-" << amount << " hitPoints (dead)!\n";
        #endif // NOT_SIMULATE
        std::cout << NC;
        return ;
    }
    /* In case the player is still alive after the hit */
    #ifndef NOT_SIMULATE
        std::cout << "-" << amount << " hitPoints\n";
    #endif // NOT_SIMULATE
    std::cout << NC;
    return ;
}

/* Gets <amount> hit points back, repairing costs 1 energy point each. */
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {   
        #ifndef NOT_SIMULATE
            std::cout << name << " cannot be healed\n";
        #endif // NOT_SIMULATE
        return ;
    }
    /* In case the player has some energy points */
    hitPoints += amount;
    energyPoints -= 1;
    if (hitPoints > 100)
        hitPoints = 100;
    else if (hitPoints > 10 && energyPoints <= 10)
        hitPoints = 10;

    #ifndef NOT_SIMULATE
        std::cout << name << " received " << amount << " hitPoints" \
            << " (current hitPoints is " << hitPoints << ")" << std::endl;
    #endif // NOT_SIMULATE
    return ;
}

/* -------------------------------------------------------------------------- */
/*                                  Getters                                   */
/* -------------------------------------------------------------------------- */

/* Method used to get name private attribute */
std::string    ClapTrap::getName() const
{
    return (name);
}

/* Method used to get hitPoints private attribute */
int    ClapTrap::getHitPoints() const
{
    return (hitPoints);
}

/* Method used to get energyPoints private attribute */
int    ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}

/* Method used to get attackDamage private attribute */
int    ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

/* -------------------------------------------------------------------------- */
/*                                  Setters                                   */
/* -------------------------------------------------------------------------- */


/* Method used to set name private attribute */
void    ClapTrap::setName(const std::string name)
{
    this->name = name;
    return ;
}

/* Method used to set HitPoints private attribute */
void    ClapTrap::setHitPoints(const int hitPoints)
{
    this->hitPoints = hitPoints;
    return ;
}

/* Method used to set energyPoints private attribute */
void    ClapTrap::setEnergyPoints(const int energyPoints)
{
    this->energyPoints = energyPoints;
    return ;
}

/* Method used to set attackDamage private attribute */
void    ClapTrap::setAttackDamage(const int attackDamage)
{
    this->attackDamage = attackDamage;
    return ;
}
