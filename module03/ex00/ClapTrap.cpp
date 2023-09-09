#include "ClapTrap.hpp"
#include <iostream>

/* Default Constructor */
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
                                       energyPoints(10), attackDamage(0)
{
    #ifdef DEBUG
        std::cout << "ClapTrap Constructor is called" << std::endl;
    #endif // DEBUG
}

/* Copy Constructor */
ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "ClapTrap Copy Constructor is called" << std::endl; 
    #endif // DEBUG
    
    *this = rhs;
    return ;
}

/* Copy Assignement Operator */
ClapTrap    ClapTrap::operator=(const ClapTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "Claptrap operator= is called" << std::endl; 
    #endif // DEBUG

    if (this != &rhs)
    {
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

    #ifndef SIMULATE
        std::cout << this->name << ": is dead !" << std::endl;
    #endif // SIMULATE
}

/* 
*   Causes its target to lose <attack damage> hit points, Attacking costs 1 
*       energy point each. 
*/
void ClapTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        #ifndef SIMULATE
            std::cout << "ClapTrap " << this->name << ": cannot attack. 0 energy!\n";
        #endif // SIMULATE
    }

    this->energyPoints -= 1;

    #ifndef SIMULATE
        std::cout << "ClapTrap " << this->name << ": attacks " <<  target << ", "
            << "causing " << this->attackDamage << " points of damage!\n";
    #endif // SIMULATE
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        #ifndef SIMULATE
            std::cout << "ClapTrap " << name << ": is dead!\n";
        #endif // SIMULATE
        return ;
    }

    hitPoints -= amount;
    if (hitPoints <= 0)
    {
        hitPoints = 0;
        #ifndef SIMULATE
            std::cout << "ClapTrap " << name << ": -" << amount << " hitPoints (dead)!\n";
        #endif // SIMULATE
        return ;
    }
    #ifndef SIMULATE
        std::cout << "ClapTrap " << name << ": -" << amount << " hitPoints\n";
    #endif // SIMULATE
    
    return ;
}

/* Gets <amount> hit points back, repairing costs 1 energy point each. */
void    ClapTrap::beRepaired(unsigned int amount)
{
    #ifndef SIMULATE
        std::cout << "ClapTrap " << this->name << ":: cannot beRepaired 0 energy!\n";
    #endif // SIMULATE
    
    this->hitPoints += amount;
    this->energyPoints -= 1;
    if (this->hitPoints > 10)
        this->hitPoints = 10;
    
    #ifndef SIMULATE
        std::cout << this->name << ": received " << amount << " hitPoints" \
            << ", current hitPoints is " << this->hitPoints << std::endl;
    #endif // SIMULATE
    return ;
}

std::string    ClapTrap::getName() const
{
    return (name);
}

int    ClapTrap::getHitPoints() const
{
    return (hitPoints);
}

int    ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}

int    ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

void    ClapTrap::setHitPoints(const int hitPoints)
{
    this->hitPoints = hitPoints;
    return ;
}

void    ClapTrap::setEnergyPoints(const int energyPoints)
{
    this->energyPoints = energyPoints;
    return ;
}

void    ClapTrap::setAttackDamage(const int attackDamage)
{
    this->attackDamage = attackDamage;
    return ;
}
