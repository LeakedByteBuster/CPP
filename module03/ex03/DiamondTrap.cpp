#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    ClapTrap::setHitPoints(FragTrap::getHitPoints2());
    ClapTrap::setEnergyPoints(DiamondTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage2());

    #ifdef DEBUG
        std::cout << "DiamondTrap parameterized constructor is called\n";
    #endif // DEBUG
    
    #ifndef NOT_SIMULATE
        std::cout << "...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺃ ﺎﺸﻣ اﺬﻫ ...ﻖﻳﺮﺗ ﻦﻣ ﺎﻳﻮﺧﺃ" \
            "ﺪﻴﻴﺣﺍ ...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺍ ﺎﺸﻣ اﺬﻫ" << " " << name << std::endl;
    #endif // NOT_SIMULATE
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "\e[1;104m_clap_name\033[0m"), 
                                             FragTrap(name), ScavTrap(name),
                                             name(name)
{
    ClapTrap::setHitPoints(FragTrap::getHitPoints2());
    ClapTrap::setEnergyPoints(DiamondTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage2());

    #ifdef DEBUG
        std::cout << "DiamondTrap parameterized constructor is called\n";
    #endif // DEBUG
    
    #ifndef NOT_SIMULATE
        std::cout << "...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺃ ﺎﺸﻣ اﺬﻫ ...ﻖﻳﺮﺗ ﻦﻣ ﺎﻳﻮﺧﺃ" \
            "ﺪﻴﻴﺣﺍ ...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺍ ﺎﺸﻣ اﺬﻫ" << " " << name << std::endl;
    #endif // NOT_SIMULATE
}

DiamondTrap::~DiamondTrap()
{
    #ifdef DEBUG
        std::cout << "DiamondTrap destructor is called\n";
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << name  << " is the real deal! "<< std::endl;
    #endif // NOT_SIMULATE
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs.getName() + "\e[1;104m_clap_name\033[0m"), 
                                             FragTrap(rhs.getName()), ScavTrap(rhs.getName()),
                                             name(rhs.getName())
{ 
    #ifdef DEBUG
        std::cout << "DiamondTrap copy constructor is called" << std::endl;
    #endif // DEBUG

    *this = rhs;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs)
{
    #ifdef DEBUG
        std::cout << "DiamondTrap copy assignement operator is called" << std::endl;
    #endif // DEBUG

    #ifndef NOT_SIMULATE
        std::cout << "...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺃ ﺎﺸﻣ اﺬﻫ ...ﻖﻳﺮﺗ ﻦﻣ ﺎﻳﻮﺧﺃ" \
            "ﺪﻴﻴﺣﺍ ...ﺶﻣ اﺬﻫ،رﻮﺨﻟ آﺭﺍ ﺎﺸﻣ اﺬﻫ" << " " << name << std::endl;
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

void DiamondTrap::whoAmI()
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        #ifndef NOT_SIMULATE
            std::cout << "\e[1;105m/*       Who am i? "<< name << "\e[1;105m grandson of " << \
                ClapTrap::getName() << "\e[1;105m        */\033[0m" << std::endl;
        #endif // NOT_SIMULATE
    }
    else
    {
        #ifndef NOT_SIMULATE
            std::cout << name << " cannot say who he is" << std::endl;
        #endif // NOT_SIMULATE
    }
    return ;
}

/* target loses <attack damage> hit points, attacking costs 1 energy */
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    return ;
}

std::string DiamondTrap::getName() const
{
    return (this->name);
}
