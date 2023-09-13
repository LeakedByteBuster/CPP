#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "\e[1;104m_clap_name\033[0m"), 
                                             FragTrap(name), ScavTrap(name),
                                             name(name)
{
    ClapTrap::setHitPoints(FragTrap::getHitPoints());
    ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage());

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

// DiamondTrap(const DiamondTrap&)
// {    
// }

// DiamondTrap& operator=(const DiamondTrap&)
// {


//     return (*this);
// }

void DiamondTrap::whoAmI()
{
    #ifndef NOT_SIMULATE
        std::cout << "\e[1;105m/*       Who am i? "<< name << "\e[1;105m grandson of " << \
            ClapTrap::getName() << "\e[1;105m        */\033[0m" << std::endl;
    #endif // NOT_SIMULATE

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
