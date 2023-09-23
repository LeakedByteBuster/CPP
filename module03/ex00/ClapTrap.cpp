#include "ClapTrap.hpp"
#include <iostream>

#define HWHT "\e[1;97m"
#define NC "\33[0m"

/* -------------------------------------------------------------------------- */
/*                               Orthodox Form                                */
/* -------------------------------------------------------------------------- */

/* Default Constructor */
ClapTrap::ClapTrap() : name(""), hitPoints(10),
                        energyPoints(10), attackDamage(0)
{
    #ifdef DEBUG
        std::cout << "Claptrap parameterized constructor is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ClapTrap " << name << " step into the ring 🤼" << std::endl;
    #endif // NOT_SIMULATE
}

/* Parameterized Constructor */
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
                                       energyPoints(10), attackDamage(0)
{
    #ifdef DEBUG
        std::cout << "Claptrap parameterized constructor is called" << std::endl; 
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "ClapTrap " << name << " step into the ring 🤼" << std::endl;
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

    if (hitPoints == 0)
    {    
        #ifndef NOT_SIMULATE
            std::cout << this->name << " is dead!" << std::endl;
        #endif // NOT_SIMULATE
    }
    else
    {
        #ifndef NOT_SIMULATE
            std::cout << this->name << " is a real warrior!" << std::endl;
        #endif // NOT_SIMULATE
    }
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
            std::cout << this->name << " cannot attack\n";
        #endif // NOT_SIMULATE
        return ;
    }

    this->energyPoints -= 1;

    #ifndef NOT_SIMULATE
        std::cout << this->name << " attacks " << target << std::endl;
    #endif // NOT_SIMULATE
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << HWHT;
    if (hitPoints <= 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << "ClapTrap " << name << " is dead!\n";
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
            std::cout << "ClapTrap " << this->name << ": cannot be healed\n";
        #endif // NOT_SIMULATE
        return ;
    }
    /* In case the player has some energy points */
    this->hitPoints += amount;
    this->energyPoints -= 1;
    if (this->hitPoints > 10)
        this->hitPoints = 10;
    
    #ifndef NOT_SIMULATE
        std::cout << this->name << " received " << amount << " hitPoints" \
            << " (current hitPoints is " << this->hitPoints << ")" << std::endl;
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
